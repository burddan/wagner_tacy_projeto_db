void adicionar_produto(PGconn *conexao, int user_id) {
    char tipo[40];
    char descricao[100];

    printf("Digite o tipo do produto: ");
    scanf("%40s", tipo);
	getchar();  
    printf("Digite a descricao do produto: ");
    scanf("%100s", descricao);

    const char *consulta = "INSERT INTO Produtos (tipo, descricao, idPadaria) VALUES ($1, $2, 1)";
    const char *parametros[2] = {tipo, descricao};

    PGresult *resultado = PQexecParams(conexao, consulta, 2, NULL, parametros, NULL, NULL, 0);

    if (PQresultStatus(resultado) == PGRES_COMMAND_OK) {
        printf("Produto adicionado com sucesso\n");
        registrar_acao(conexao, user_id, "Adicionou um produto");
    } else {
		printf("Erro ao adicionaar produtos: ");
    }

    PQclear(resultado);
}

