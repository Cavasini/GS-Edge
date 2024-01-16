# 💙 VITA: Sistema Inteligente de Gestão de Estoque Hospitalar
O Projeto VITA busca implementar um sistema de gestão de estoque inteligente em hospitais, garantindo disponibilidade e prevenindo desperdícios. Com funcionalidades como controle em tempo real e rastreamento por código de barras, o projeto visa melhorar eficiência operacional, oferecer controle rigoroso e facilitar a integração na rotina dos profissionais de saúde.

### 🎯 Objetivos
- Assegurar que hospitais tenham acesso contínuo a materiais e medicamentos essenciais, evitando escassez.
- Evitar a expiração de medicamentos e materiais, reduzindo desperdícios e otimizando recursos financeiros.
- Melhorar a reposição de estoque, evitando a falta de itens essenciais e proporcionando rápido acesso aos profissionais de saúde.
- Manter um controle preciso sobre o estoque, reduzindo erros manuais e aprimorando a precisão dos registros.
- Integrar facilmente o sistema na rotina dos profissionais de saúde, utilizando a simplicidade do escaneamento de códigos de barras.

### 🩹 Dores que Busca Suprir
- Escassez de Materiais Essenciais.
- Desperdício de Recursos Financeiros.
- Ineficiência na Reposição de Estoque.
- Controle Fragilizado.
- Dificuldade de Rastreamento.
- Falta de Alertas Antecipados.
- Complexidade na Integração ao Fluxo de Trabalho.

## 🗃 Funcionalidades do Sistema

### 🔓 Autenticação de Funcionários via Keypad

O nosso sistema oferece uma forma eficiente e rapidá de autenticação para os funcionários através do keypad.

### 📊 Monitoramento de Níveis de Estoque

Após efetuar o login, os funcionários têm acesso à funcionalidade de verificação dos níveis de estoque. 
Essa ferramenta permite um acompanhamento em tempo real do status dos itens armazenados. 
Caso seja identificada uma quantidade baixa de algum produto, o sistema notifica automaticamente, proporcionando uma gestão proativa e evitando possíveis problemas de falta de estoque.

### 📆 Verificação da Validade dos Produtos

Além da verificação de nível de estoque, implementamos uma funcionalidade que verifica a validade dos produtos armazenados. 
Caso a validade de um item esteja próxima do vencimento ou tenha expirado, o sistema automaticamente notifica o administrador. 

### 🔒 Deslogar como Funcionário

A última funcionalidade oferecida é a opção de deslogar como funcionário. 
Isso proporciona segurança adicional, permitindo que os usuários encerrem sua sessão quando necessário, especialmente em ambientes compartilhados.

### 📂 Processamento de Dados pelo Jupyter Notebook

Integramos a capacidade do sistema de receber e processar dados diretamente através do Jupyter Notebook. Isso possibilita uma análise mais detalhada e interativa por parte dos usuários, permitindo uma exploração mais aprofundada das informações.

### 📫 Criação de API para Acesso Remoto

Além disso, implementamos a criação de uma API que permite o acesso remoto às funcionalidades do sistema. Isso possibilita a interação programática com os dados, facilitando a integração com outras ferramentas e sistemas externos. Essa abordagem amplia a flexibilidade e utilidade do sistema, permitindo uma variedade de usos e aplicações.

## 📋 Registro no postman

- Para realizar este projeto, foi usado do fiware descomplicado do Professor Cabrini,<a href="https://github.com/fabiocabrini/fiware">Clique aqui para ver</a>.
  
- Baixe o material e abra o Postman.
  
- Exporte os comandos disponíveis no material.
  
- Substitua a URL pelo endereço do broker.
  
- Vá para a seção "3. Provisioning a Smart Lamp" no material.
  
- No corpo (body) da requisição, substitua 'lamp' e 'lamp001' pelos nomes desejados para o registro.
  
- Insira os tópicos desejados, informando o nome e tipo (int, string, float, etc).
  
- Certifique-se de que o dispositivo foi registrado.
  
- Acesse a seção "5. List all Devices Provisioned" no material.

## 🌐 Tecnologias utilizadas
- WiFi:
**Biblioteca utilizada para facilitar a conexão e configuração da rede WiFi**
- PubSubClient:
**Biblioteca utilizada para implementação MQTT**
- LiquidCrystal_I2C:
**Biblioteca utilizada para usar o lcd_I2c**
- Keypad:
**Biblioteca utilizada para usar o keypad**
- Jupyter Notebook:
**Tecnologia para análise interativa e processamento de dados.**
- JSON:
**Formato para armazenar e estruturar dados**


## 📟 ESP32 e Wokwi Simulator
O ESP32 é um microcontrolador poderoso e versátil, amplamente utilizado para projetos de Internet das Coisas (IoT). 
Neste projeto, exploramos suas capacidades utilizando o simulador Wokwi, que oferece uma plataforma virtual para experimentação sem a necessidade de hardware físico. Isso proporciona um ambiente de desenvolvimento conveniente e eficiente.

- Link do do Wokwi <a href="https://wokwi.com/projects/382150998462319617">Clique aqui para ver</a>

## 🛰️ Servidor de IoT
A aplicação ESP32 no simulador Wokwi está conectada a um servidor de IoT, permitindo a troca de dados de forma eficiente. Isso possibilita o monitoramento remoto e a interação com o ESP32 por meio da internet.

## 🔗 Integração MQTT e API Flask: Detalhes do Código

Este conjunto de códigos representa uma solução de integração entre o protocolo MQTT (Message Queuing Telemetry Transport) e uma API Flask. A aplicação resultante possibilita o monitoramento em tempo real de dados específicos e fornece uma interface para acesso a essas informações.

### 📡 Paho MQTT

A biblioteca Paho MQTT é empregada para a implementação do protocolo MQTT. O código estabelece uma conexão com um broker MQTT especificado pelo endereço (mqtt_broker_address) e porta (mqtt_port). As funções on_connect e on_message são definidas como callbacks para lidar com a conexão inicial e o recebimento de mensagens, respectivamente.

### 📂 JSON

O sistema utiliza o formato JSON para armazenar os dados recebidos do MQTT. O arquivo JSON (mqtt_data.json) é atualizado dinamicamente à medida que novas mensagens são recebidas. A estrutura do JSON reflete a hierarquia dos tópicos MQTT, proporcionando uma organização clara dos dados.

### 🌐 Flask API

A framework Flask é empregada para criar uma API web que disponibiliza dados específicos por meio de endpoints. Três endpoints são definidos:

- **/validade**: Fornece informações sobre a validade dos produtos.
- **/estoque**: Retorna dados relacionados aos níveis de estoque.
- **/user**: Disponibiliza informações sobre o usuário associado ao sistema.
Esses endpoints são configurados para responder a requisições HTTP GET, retornando os dados relevantes do dicionário de dados.

### 🔄 Flask em Thread Separada

Para garantir a execução simultânea do loop MQTT e da API Flask, o Flask é iniciado em uma thread separada (flask_thread). Isso permite que ambas as funcionalidades operem de forma assíncrona e sem interferências mútuas.

### ⚙️ Configurações

O endereço e a porta do broker MQTT são configurados através das variáveis mqtt_broker_address e mqtt_port. O arquivo JSON (mqtt_data.json) é especificado como o local para armazenar dinamicamente os dados recebidos.

### 🚀 Execução

Ao executar este código, a aplicação inicia uma thread para o Flask e entra em um loop contínuo para a comunicação MQTT. Isso possibilita o monitoramento em tempo real dos dados MQTT por meio da API Flask, tornando o sistema adaptável a diferentes requisitos de integração e visualização de dados.

## ✅ Iniciando a aplicação

![Esp32 no wokwi](imgs/img01.jpeg)

- Antes da plicação ser iniciada, é necessário iniciar o codigo do Jupyter Notebook do aqrquivo **cp.ipynb**
  
- Como o usuário não está logado, o acesso às dados é negado.


<img src="imgs/img05.jpeg" alt="Texto Alternativo" width="700">
  
- Ao iniciar a aplicação, é mostrada a mensagem no lcd "Insira o codigo".
  
![Esp32 no wokwi](imgs/img02.jpeg)

- Para logar como usuário, clique em qualquer tecla de 1 a 9.
- Para confirmar, clique 0.
- Funcionário Logado.

![Esp32 no wokwi](imgs/img03.jpeg)

- Com o funcionário logado as funções de verificarValidade() e verificarEstoque() começam a funcionar em loop infinito.
  
- Função verificarValidade(): verifica as validades dos itens e da um MQTT.publish nos itens fora de validade.

- Função verificarEstoque(): verifica o nivel do estoque de cada item. Se o nivel for menor que 50, ele da um MQTT.publish nos itens que estão com estoque baixo e a porcentagem do nivel.

- No json, é possivel ver: o codigo do funcionário logado e os dados que estão sendo publicados pelas funções verificarValidade() e verificarEstoque().

<img src="imgs/img04.jpeg" alt="Texto Alternativo" width="700">

- Se o funcionário quiser deslogar, é somente necessário apertar a tecla 0 do keypad.

- Com o funcionário deslogado, o lcd vai voltar ao inicio da aplicação.

![Esp32 no wokwi](imgs/img02.jpeg)

- e o json vai mostrar acesso negado às informações, pois o funcionário não está logado

<img src="imgs/img05.jpeg" alt="Texto Alternativo" width="700">

### 📫 API
- As informações do json está sendo passada pela url **http://127.0.0.1:5000/**
- Para ver as informações é necessário dar request Get em uma plataforma API ou no próprio navegador.

- http://127.0.0.1:5000/validade
- http://127.0.0.1:5000/estoque
- http://127.0.0.1:5000/user
