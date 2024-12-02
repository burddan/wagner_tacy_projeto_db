void adicionar_produto(PGconn *conexao, int user_id) {
    char tipo[40];
    char descricao[100];

    printf("Digite o tipo do produto: ");
    scanf("%40", tipo);
    printf("Digite a descricao do produto: ");
    scanf("%100", descricao);

    const char *consulta = "INSERT INTO Produtos (tipo, descricao, idPadaria) VALUES ($1, $2, 1)";
    const char *parametros[2] = {tipo, descricao};

    PGresult *resultado = PQexecParams(conexao, consulta, 2, NULL, parametros, NULL, NULL, 0);

    if (PQresultStatus(resultado) == PGRES_COMMAND_OK) {
        printf("produto adicionado com sucesso\n");
        registrar_acao(conexao, user_id, "adicionou um produto");
    } else {
        fprintf(stderr, "erro ao adicionar produto: %s\n", PQerrorMessage(conexao));
    }

    PQclear(resultado);
}

