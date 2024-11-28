void listar_usuarios(PGconn *conexao) {
		const char *consulta = "SELECT id, username FROM usuarios";
		PGresult *resultado = PQexec(conexao, consulta);

		/*    if (PQresultStatus(resultado) != PGRES_TUPLES_OK) {
			  fprintf(stderr, "Erro ao listar usuários: %s\n", PQerrorMessage(conexao));
		//printf("erro ao lista usuarios\n");
		PQclear(resultado);
		return; //  return pra nao continuar
		}
		*/

		int linhas = PQntuples(resultado); // a porra da linha
		printf("numero de usuários: %d\n", linhas);
		for (int i = 0; i < linhas; i++) {
				printf("ID: %s, usuarios: %s\n", PQgetvalue(resultado, i, 0), PQgetvalue(resultado, i, 1));
		}

		PQclear(resultado);
}

