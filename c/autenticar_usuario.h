//autenticar_usuario.h
int autenticar_usuario(PGconn *conexao, int *user_id) {
		char username[50]; 
		char password[50];
		// username e password mesmos nomes pro dtb

		printf("digite o usuario: ");
		scanf("%49s", username);
		printf("digite a senha: ");
		scanf("%49s", password);

		const char *consulta = "SELECT id FROM usuarios WHERE username = $1 AND password = $2";
		const char *parametros[2] = {username, password};

		PGresult *resultado = PQexecParams(conexao, consulta, 2, NULL, parametros, NULL, NULL, 0);

		if (PQresultStatus(resultado) != PGRES_TUPLES_OK || PQntuples(resultado) == 0) {
				fprintf(stderr, "autenticacao falhou tem algo de errado\n");
				PQclear(resultado);
				return 0;
		}

		*user_id = atoi(PQgetvalue(resultado, 0, 0));
		PQclear(resultado);
		return 1;
}
