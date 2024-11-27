int autenticar_usuario(PGconn *conn, int *user_id) {
		char username[50];
		char password[50];

		printf("Digite o nome de usuário: ");
		scanf("%49s", username);
		printf("Digite a senha: ");
		scanf("%49s", password);

		const char *query = "SELECT id FROM usuarios WHERE username = $1 AND password = $2";
		const char *params[2] = {username, password};

		PGresult *res = PQexecParams(conn, query, 2, NULL, params, NULL, NULL, 0);

		if (PQresultStatus(res) != PGRES_TUPLES_OK || PQntuples(res) == 0) {
				fprintf(stderr, "Autenticação falhou. Verifique suas credenciais.\n");
				PQclear(res);
				return 0;
		}

		*user_id = atoi(PQgetvalue(res, 0, 0));
		PQclear(res);
		return 1;
}
