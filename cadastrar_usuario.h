//cadastrar_usuario.h
void cadastrar_usuario(PGconn *conexao) {
		char username[50];
		char password[50];

		printf("digite o nome do usuario: ");
		scanf("%49s", username); // buffer overflow
		printf("digite a senha: ");
		scanf("%49s", password);

		const char *consulta = "INSERT INTO usuarios (username, password) VALUES ($1, $2)";
		const char *input[2] = {username, password};

		PGresult *resultado = PQexecParams(conexao, consulta, 2, NULL, input, NULL, NULL, 0);

		if (PQresultStatus(resultado) != PGRES_COMMAND_OK) {
				fprintf(stderr, "Erro ao cadastrar usuário: %s\n", PQerrorMessage(conexao));
				//printf("erro ao cadastrar usuario\n");
		} else {
				printf("usuario cadastrado com sucesso\n");
		}

		PQclear(resultado);
}
