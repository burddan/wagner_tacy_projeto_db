void cadastrar_usuario(PGconn *conn) {
		char username[50];
		char password[50];

		printf("Digite o nome de usuário: ");
		scanf("%49s", username);
		printf("Digite a senha: ");
		scanf("%49s", password);

		const char *query = "INSERT INTO usuarios (username, password) VALUES ($1, $2)";
		const char *params[2] = {username, password};

		PGresult *res = PQexecParams(conn, query, 2, NULL, params, NULL, NULL, 0);

		if (PQresultStatus(res) != PGRES_COMMAND_OK) {
				fprintf(stderr, "Erro ao cadastrar usuário: %s\n", PQerrorMessage(conn));
		} else {
				printf("Usuário cadastrado com sucesso!\n");
		}

		PQclear(res);
}
