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

### 🌐 Tecnologias Utilizadas

- React: Biblioteca JavaScript para a criação de interfaces de usuário interativas.

- JavaScript: Linguagem de programação fundamental para o desenvolvimento web.

- Vite: Ferramenta de construção rápida para projetos web modernos.

- React Router DOM: Biblioteca para controle de navegação em aplicativos React.

- Sass: Utilizamos Sass para a estilização do projeto, permitindo uma abordagem mais modular e organizada na criação de estilos.

- Hooks em React: Foram utilizados hooks como useState e useEffect para a transição e gerenciamento de dados entre os componentes, garantindo uma experiência de usuário fluente e interativa.

- Styled Components: Biblioteca para estilização de componentes em React.


- JSON Server: Para simular uma API e facilitar o desenvolvimento, utilizamos o JSON Server para criar um servidor RESTful a partir de um arquivo JSON.


## 🧠 Funcionalidades Principais

- Login Seguro: Verificação das credenciais do usuário em relação ao banco de dados.

- Redirecionamento Automático: Após o login bem-sucedido, os usuários são redirecionados automaticamente para a página inicial do projeto.

- Menu Dropdown Personalizado: Na parte superior esquerda, os usuários têm acesso a um menu dropdown.

- Perfil do Usuário: O dropdown exibe informações detalhadas, como nome de usuário e endereço de e-mail, proporcionando uma experiência personalizada.

- Opção de Deslogar: Os usuários podem efetuar logout facilmente através do dropdown, garantindo a segurança dos dados e permitindo uma transição suave entre sessões.
  

- API Local: A aplicação é alimentada por uma API local que armazena os dados dos usuários cadastrados no arquivo dados.json.


### 🔑 Credenciais para login:

- Todos os dados para login estão no dados.json
  
#### usuário padrão
- username: cavasini
- senha : cavasinifiap


## 📂 Deploy do Projeto com Vercel
Para acessar e visualizar a versão mais recente do projeto Vita, você pode visitar a aplicação hospedada na plataforma Vercel. A Vercel é uma plataforma de deploy que oferece escalabilidade e desempenho para garantir uma ótima experiência ao usuário.

### Para acessar o projeto, https://gs-psi.vercel.app/

## 🤝 Integrantes do Grupo
- Matheus Cavasini - 97722
- Lourenzo Ramos - 99951

## ⚙️ Executando o Projeto
Siga os passos abaixo para executar o projeto em sua máquina local:

- Clone este repositório em sua máquina: git clone https://github.com/Cavasini/GS.git
- Navegue até o diretório do projeto: cd GS
- Instale as dependências: npm install ou yarn install

### 🚀 Iniciando o Projeto

#### Início Rápido com Concurrently

O Projeto VITA facilita o desenvolvimento ao utilizar a biblioteca Concurrently. Com essa ferramenta, é possível iniciar tanto o servidor local JSON quanto o projeto React com um único comando.

- npm run dev
