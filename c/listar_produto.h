void listar_produtos(PGconn *conexao) {
		const char *consulta = "SELECT idProdutos, tipo, descricao FROM Produtos";

		PGresult *resultado = PQexec(conexao, consulta);

		// deletar dps
		if (PQresultStatus(resultado) != PGRES_TUPLES_OK) {
				fprintf(stderr, "erro ao listar produtos: %s\n", PQerrorMessage(conexao));
				PQclear(resultado);
				return;
		}


		int linhas = PQntuples(resultado);
		printf("produto disponiveis:\n");

		for (int i = 0; i < linhas; i++) {
				printf("ID: %s, tipo: %s, descricao: %s\n",
								PQgetvalue(resultado, i, 0),
								PQgetvalue(resultado, i, 1),
								PQgetvalue(resultado, i, 2));
		}

		PQclear(resultado);
}
