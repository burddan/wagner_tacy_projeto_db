CREATE TABLE usuarios (
    id SERIAL PRIMARY KEY,       
    username VARCHAR(50) NOT NULL UNIQUE, 
    password VARCHAR(50) NOT NULL         
);

CREATE TABLE logs (
    id SERIAL PRIMARY KEY,
    user_id INT NOT NULL,
    acao VARCHAR(255) NOT NULL,
    data_hora TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (user_id) REFERENCES usuarios(id)
);


CREATE TABLE Padaria(
    idPadaria SERIAL PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    horario VARCHAR(50) NOT NULL,
    categoria VARCHAR(50),
    cnpj VARCHAR(14) UNIQUE NOT NULL
);
CREATE TABLE clientes(
    idPerfil_cliente SERIAL PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    cpf VARCHAR(11) UNIQUE NOT NULL,
    data_nascimento DATE,
    idade INT,
    idPadaria INT,
    FOREIGN KEY (idPadaria) REFERENCES Padaria(idPadaria)
);
CREATE TABLE Localizacao_cliente(
    idLocalizacao_cliente SERIAL PRIMARY KEY,
    bairro VARCHAR(100),
    cidade VARCHAR(100),
    idPerfil_cliente INT,
    FOREIGN KEY (idPerfil_cliente) REFERENCES Perfil_cliente(idPerfil_cliente)
);
CREATE TABLE Produtos(
    idProdutos SERIAL PRIMARY KEY,
    tipo VARCHAR(40) NOT NULL,
    descricao VARCHAR(100) NOT NULL,
    idPadaria INT,
    FOREIGN KEY (idPadaria) REFERENCES Padaria(idPadaria)
);
CREATE TABLE Historico_vendas(
    idHistorico_vendas SERIAL PRIMARY KEY,
    horario TIME NOT NULL,
    dia DATE NOT NULL,
    idPerfil_cliente INT,
    FOREIGN KEY (idPerfil_cliente) REFERENCES Perfil_Cliente(idPerfil_cliente)

);
CREATE TABLE Localizacao_loja(
    idLocalizacao_loja SERIAL PRIMARY KEY,
    bairro VARCHAR(100),
    rua VARCHAR(100),
    cidade VARCHAR(100),
    idPadaria INT,
    FOREIGN KEY (idPadaria) REFERENCES Padaria(idPadaria)
);
CREATE TABLE Funcionario(
    id SERIAL PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    cpf VARCHAR(11) UNIQUE NOT NULL,
    data_nascimento DATE,
    idade INT,
    cargo VARCHAR(50),
    salario DECIMAL(10, 2),
    horario_trabalho VARCHAR(50),
    idPadaria INT,
    FOREIGN KEY (idPadaria) REFERENCES Padaria(idPadaria)
);
