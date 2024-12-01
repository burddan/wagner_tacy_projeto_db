void registrar_acao(PGconn *conexao, int user_id, const char *acao);
void cadastrar_usuario(PGconn *conexao) {
    char username[50], password[50];
    int tipo_usuario;

    printf("Digite o nome do usuário: ");
    scanf("%49s", username);
    printf("Digite a senha: ");
    scanf("%49s", password);

    printf("Tipo de usuário:\n1. Cliente\n2. Funcionário\nEscolha: ");
    scanf("%d", &tipo_usuario);

    const char *query = "INSERT INTO usuarios (username, password) VALUES ($1, $2) RETURNING id";
    const char *params[2] = {username, password};

    PGresult *resultado = PQexecParams(conexao, query, 2, NULL, params, NULL, NULL, 0);

    if (PQresultStatus(resultado) == PGRES_TUPLES_OK) {
        int user_id = atoi(PQgetvalue(resultado, 0, 0));

        if (tipo_usuario == 1) {
            const char *cliente_query = "INSERT INTO clientes (nome, cpf, idPadaria) VALUES ($1, $2, 1)";
            printf("Cadastro como cliente realizado com sucesso.\n");
        } else if (tipo_usuario == 2) {
            printf("Cadastro como funcionário realizado com sucesso.\n");
        }

        registrar_acao(conexao, user_id, "Cadastro de novo usuário");
    } else {
        fprintf(stderr, "Erro ao cadastrar usuário: %s\n", PQerrorMessage(conexao));
    }

    PQclear(resultado);
}

