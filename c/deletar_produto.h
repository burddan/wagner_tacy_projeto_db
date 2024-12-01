void deletar_produto(PGconn *conexao, int user_id) {
		int idProduto;
		printf("Digite o ID do produto que deseja deletar: ");
		scanf("%d", &idProduto);

		const char *query = "DELETE FROM Produtos WHERE idProdutos = $1";
		char idProdutoStr[10];
		snprintf(idProdutoStr, 10, "%d", idProduto);
		const char *parametros[1] = {idProdutoStr};

		PGresult *resultado = PQexecParams(conexao, query, 1, NULL, parametros, NULL, NULL, 0);

		if (PQresultStatus(resultado) == PGRES_COMMAND_OK) {
				printf("Produto deletado com sucesso.\n");
				registrar_acao(conexao, user_id, "Deletou um produto");
		} else {
				fprintf(stderr, "Erro ao deletar produto: %s\n", PQerrorMessage(conexao));
		}

		PQclear(resultado);
}

