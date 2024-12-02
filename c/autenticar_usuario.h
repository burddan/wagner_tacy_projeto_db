void menu_admin(PGconn *conexao, int user_id);
void menu_funcionario(PGconn *conexao, int user_id);
void menu_cliente(PGconn *conexao, int user_id);

void autenticar_usuario(PGconn *conexao) {
		char username[50], password[50], consulta[256];
		PGresult *resultado;

		printf("Digite o username: ");
		scanf("%s", username);
		printf("Digite a senha: ");
		scanf("%s", password);

		snprintf(consulta, 256, "SELECT id, tipo FROM usuarios WHERE username = '%s' AND password = '%s'", username, password);

		resultado = PQexec(conexao, consulta);

		if (PQresultStatus(resultado) != PGRES_TUPLES_OK) {
				printf("Erro na consulta \n");
				PQclear(resultado);
				return;
		}

		if (PQntuples(resultado) == 0) {
				printf("Usuario ou senha incorreto\n");
		} else {
				int user_id = atoi(PQgetvalue(resultado, 0, 0));  // revisar essa porra
				char *tipo = PQgetvalue(resultado, 0, 1);
				printf("Usuario tipo %s cadastrado \n", tipo);

				if (strcmp(tipo, "admin") == 0) {
						menu_admin(conexao, user_id);
				} else if (strcmp(tipo, "funcionario") == 0) {
						menu_funcionario(conexao, user_id);
				} else if (strcmp(tipo, "cliente") == 0) {
						menu_cliente(conexao, user_id);
				}
		}

		PQclear(resultado);
}

