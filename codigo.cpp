#include <WiFi.h>
#include <PubSubClient.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C LCD = LiquidCrystal_I2C(0x27, 16, 2);
const byte LINHAS = 4;
const byte COLUNAS = 4;
char teclas[LINHAS][COLUNAS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte pinosLinhas[LINHAS] = {2, 16, 17, 18};
byte pinosColunas[COLUNAS] = {25, 26, 27, 14};
int numeros[] = {1, 2, 3, 4, 5, 6, 7, 8, 9 };
bool dentroValidadeItem[] = {true, true, false, false, true, false, true, true, true};
const char *funcionario_id[] = {"1001", "1002", "1003", "1004", "1005", "1006", "1007", "1008", "1009"};
const char *item[] = {"Seringa", "Atadura", "Analgésico", "Gaze", "Termômetro", "Luvas", "Antisséptico", "Esparadrapo", "Curativo"};
int estoque[] = { 85, 40, 78, 90, 45, 89, 55, 98, 43, 56};
int tamanhoEstoque = sizeof(estoque) / sizeof(estoque[0]);
int tamanhoLista = sizeof(numeros) / sizeof(numeros[0]);
int ultimoNumero = 0;
bool encontrado = false;


// WIFI
const char* SSID = "Wokwi-GUEST"; // SSID / nome da rede WI-FI que deseja se conectar
const char* PASSWORD = ""; // Senha da rede WI-FI que deseja se conectar

// MQTT
const char* BROKER_MQTT = "46.17.108.113"; //URL do broker MQTT que se deseja utilizar
int BROKER_PORT = 1883; // Porta do Broker MQTT
//definindo id mqtt
#define ID_MQTT  "Vita300"

//#define TOPICO_SUBSCRIBE    "/TEF/Vita300/cmd"
#define TOPICO_PUBLISH_USER   "/TEF/Vita300/attrs/user"
#define TOPICO_PUBLISH_VALIDADE   "/TEF/Vita300/attrs/validade"
#define TOPICO_PUBLISH_ESTOQUE   "/TEF/Vita300/attrs/estoque"

Keypad teclado = Keypad(makeKeymap(teclas), pinosLinhas, pinosColunas, LINHAS, COLUNAS);
WiFiClient espClient; // Cria o objeto espClient
PubSubClient MQTT(espClient); // Instancia o Cliente MQTT passando o objeto espClient
void setup() {
  // put your setup code here, to run once:
  Serial.println("Hello, ESP32!");
  LCD.init();
  LCD.setCursor(0,0);
  LCD.print("Insira o codigo");
  Serial.begin(115200);
  initWiFi();
  initMQTT();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10); // this speeds up the simulation
  VerificaConexoesWiFIEMQTT();
  char tecla = teclado.getKey();
  if (tecla) {
    int numeroDigitado = tecla - '0';
    if(!encontrado){
      if(numeroDigitado == 0){
        for (int i = 0; i < tamanhoLista; ++i) {
          if (numeros[i] == ultimoNumero) {
            Serial.print("Numero encontrado: ");
            Serial.println(ultimoNumero);
            Serial.print("Informacao correspondente: ");
            Serial.println(funcionario_id[i]);
            encontrado = true;
            MQTT.publish(TOPICO_PUBLISH_USER,funcionario_id[i]);
            LCD.clear();
            LCD.print("Funcio logado");
            break;
          }
        }
        if (!encontrado) {
          Serial.println("Numero nao encontrado na lista.");
        }
        }
      else{
        ultimoNumero = numeroDigitado;
        Serial.println(ultimoNumero);
        LCD.clear();
        LCD.print(ultimoNumero);
        MQTT.publish(TOPICO_PUBLISH_USER, "Nenhum funcionário logado");

      }}
      else{
        if(numeroDigitado == 0){
          LCD.clear();
          LCD.print("Funcio deslogado");
          Serial.println("Usuário Deslogado");
          encontrado = false;
          MQTT.publish(TOPICO_PUBLISH_USER, "Nenhum funcionário logado");
          delay(2);
          LCD.clear();
          LCD.print("Insira o codigo");
          Serial.println("Insira o codigo");
        }
      }
  }

  if(encontrado){
    verificarValidade();
    verificarEstoque();
  }
  else{
  MQTT.publish(TOPICO_PUBLISH_VALIDADE, "Acesso Negado!");
  MQTT.publish(TOPICO_PUBLISH_ESTOQUE, "Acesso Negado!");
  }


  MQTT.loop();
}

void verificarValidade() {
  Serial.println("Verificando Validade:");

  int contadorItensVencidos = 0;
  String listaVencidos = "Itens Vencidos: ";

  for (int i = 0; i < tamanhoLista; ++i) {
    if (!dentroValidadeItem[i]) {
      Serial.print("Item ");
      Serial.print(item[i]);
      Serial.println(": Fora da Validade");
      contadorItensVencidos++;

      // Adiciona o item à string listaVencidos
      listaVencidos += item[i];
      listaVencidos += ",";

    }
  }

  MQTT.publish(TOPICO_PUBLISH_VALIDADE, listaVencidos.c_str());
  Serial.print("\nTotal de itens fora da validade: ");
  Serial.println(contadorItensVencidos);
  // Publica a lista apenas com itens vencidos no tópico MQTT
}

void verificarEstoque() {
  Serial.println("Verificando Estoque:");
  String listaEstoque = "Itens com Estoque baixo: ";

  for (int i = 0; i < tamanhoEstoque; ++i) {
    if (estoque[i] < 50 || (estoque[i] >= 50 && estoque[i] < 55)) {
      Serial.print("Item ");
      Serial.print(item[i]);
      Serial.print(": ");
      Serial.print(estoque[i]);
      Serial.println("%");

      listaEstoque += item[i];
      listaEstoque += ":";
      listaEstoque += estoque[i];
      listaEstoque += "%";
      listaEstoque += " / ";

      // Publica a mensagem no tópico MQTT
    }
  }
  MQTT.publish(TOPICO_PUBLISH_ESTOQUE, listaEstoque.c_str());
}

void initWiFi() 
{
    delay(10);
    Serial.println("------Conexao WI-FI------");
    Serial.print("Conectando-se na rede: ");
    Serial.println(SSID);
    Serial.println("Aguarde");
     
    reconectWiFi();
}

void reconectWiFi() 
{
    //se já está conectado a rede WI-FI, nada é feito. 
    //Caso contrário, são efetuadas tentativas de conexão
    if (WiFi.status() == WL_CONNECTED)
        return;
         
    WiFi.begin(SSID, PASSWORD, 6); // Conecta na rede WI-FI
     
    while (WiFi.status() != WL_CONNECTED) 
    {
        delay(100);
        Serial.print(".");
    }
   
    Serial.println();
    Serial.print("Conectado com sucesso na rede ");
    Serial.print(SSID);
    Serial.println("IP obtido: ");
    Serial.println(WiFi.localIP());
}

void initMQTT() 
{
    MQTT.setServer(BROKER_MQTT, BROKER_PORT);   //informa qual broker e porta deve ser conectado
    MQTT.setCallback(mqtt_callback);            //atribui função de callback (função chamada quando qualquer informação de um dos tópicos subescritos chega)
}

void reconnectMQTT() 
{
    while (!MQTT.connected()) 
    {
        Serial.print("* Tentando se conectar ao Broker MQTT: ");
        Serial.println(BROKER_MQTT);
        if (MQTT.connect(ID_MQTT)) 
        {
            Serial.println("Conectado com sucesso ao broker MQTT!");
            //MQTT.subscribe(TOPICO_SUBSCRIBE); 
        } 
        else
        {
            Serial.println("Falha ao reconectar no broker.");
            Serial.println("Havera nova tentatica de conexao em 2s");
            delay(2000);
        }
    }
}

void mqtt_callback(char* topic, byte* payload, unsigned int length) 
{
    String msg;
     
    //obtem a string do payload recebido
    for(int i = 0; i < length; i++) 
    {
       char c = (char)payload[i];
       msg += c;
    }
    
    Serial.print("- Mensagem recebida: ");
    Serial.println(msg);
}

void VerificaConexoesWiFIEMQTT(void)
{
    if (!MQTT.connected()) 
        reconnectMQTT(); //se não há conexão com o Broker, a conexão é refeita
     
     reconectWiFi(); //se não há conexão com o WiFI, a conexão é refeita
}