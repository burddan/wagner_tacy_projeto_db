//autenticar_usuario.h
void menu_admin(PGconn *conexao);
void menu_funcionario(PGconn *conexao);
void menu_cliente(PGconn *conexao);

void autenticar_usuario(PGconn *conexao) {
		char username[50], password[50], query[256];
		PGresult *res;

		printf("Digite o username: ");
		scanf("%s", username);
		printf("Digite a senha: ");
		scanf("%s", password);

		snprintf(query, sizeof(query), "SELECT tipo FROM usuarios WHERE username = '%s' AND password = '%s'", username, password);

		res = PQexec(conexao, query);

		if (PQresultStatus(res) != PGRES_TUPLES_OK) {
				printf("Erro na consulta. Tente novamente.\n");
				PQclear(res);
				return;
		}

		if (PQntuples(res) == 0) {
				printf("Usuário ou senha inválidos.\n");
		} else {
				char *tipo = PQgetvalue(res, 0, 0);
				if (strcmp(tipo, "admin") == 0) {
						menu_admin(conexao);
				} else if (strcmp(tipo, "funcionario") == 0) {
						menu_funcionario(conexao);
				} else if (strcmp(tipo, "cliente") == 0) {
						menu_cliente(conexao);
				}
		}

		PQclear(res);
}
