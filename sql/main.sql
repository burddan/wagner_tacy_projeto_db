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

