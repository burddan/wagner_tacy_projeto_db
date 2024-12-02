void menu_admin(PGconn *conexao, int user_id);
void menu_funcionario(PGconn *conexao, int user_id);
void menu_cliente(PGconn *conexao, int user_id);

void autenticar_usuario(PGconn *conexao) {
		char username[50], password[50], query[256];
		PGresult *res;

		printf("Digite o username: ");
		scanf("%s", username);
		printf("Digite a senha: ");
		scanf("%s", password);

		snprintf(query, sizeof(query), "SELECT id, tipo FROM usuarios WHERE username = '%s' AND password = '%s'", username, password);

		res = PQexec(conexao, query);

		if (PQresultStatus(res) != PGRES_TUPLES_OK) {
				printf("Erro na consulta. Tente novamente.\n");
				PQclear(res);
				return;
		}

		if (PQntuples(res) == 0) {
				printf("Usuário ou senha inválidos.\n");
		} else {
				int user_id = atoi(PQgetvalue(res, 0, 0));  // Recupera o ID do usuário ?????
				char *tipo = PQgetvalue(res, 0, 1);
				printf("Usuário autenticado com sucesso! Tipo: %s\n", tipo);

				// Armazena o user_id em algum lugar global ou passa como parâmetro para as funções
				if (strcmp(tipo, "admin") == 0) {
						menu_admin(conexao, user_id);
				} else if (strcmp(tipo, "funcionario") == 0) {
						menu_funcionario(conexao, user_id);
				} else if (strcmp(tipo, "cliente") == 0) {
						menu_cliente(conexao, user_id);
				}
		}

		PQclear(res);
}

