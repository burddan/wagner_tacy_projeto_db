CREATE TABLE usuarios (
    id SERIAL PRIMARY KEY,       
    username VARCHAR(50) NOT NULL UNIQUE, 
    password VARCHAR(50) NOT NULL         
);
