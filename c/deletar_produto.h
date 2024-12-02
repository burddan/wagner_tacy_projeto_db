void deletar_produto(PGconn *conexao, int user_id) {
    int idproduto;
    printf("Digite o id do produto pra deletar: ");
    scanf("%d", &idproduto);

    const char *consulta = "DELETE FROM Produtos WHERE idProdutos = $1";
    char idprodutostr[10]; // gambiarra por enquanto
    snprintf(idprodutostr, 10, "%d", idproduto);
    const char *parametros[1] = {idprodutostr};

    PGresult *resultado = PQexecParams(conexao, consulta, 1, NULL, parametros, NULL, NULL, 0);

    if (PQresultStatus(resultado) == PGRES_COMMAND_OK) {
        printf("Produto deletado com sucesso.\n");
        registrar_acao(conexao, user_id, "Deletou um produto");
    } else {
		printf("Erro ao deletar produto \n");
    }

    PQclear(resultado);
}

