void registrar_acao(PGconn *conexao, int user_id, const char *acao);

void cadastrar_usuario(PGconn *conexao) {
		char username[50], password[50], tipo[20];
		char nome[100], cpf[12];
		PGresult *res;
		char query[512];

		printf("Digite o username: ");
		scanf("%s", username);
		printf("Digite a senha: ");
		scanf("%s", password);
		printf("Digite o tipo (admin, funcionario, cliente): ");
		scanf("%s", tipo);

		snprintf(query, sizeof(query), "INSERT INTO usuarios (username, password, tipo) VALUES ('%s', '%s', '%s')", username, password, tipo);
		res = PQexec(conexao, query);

		if (PQresultStatus(res) != PGRES_COMMAND_OK) {
				printf("Erro ao cadastrar usuário.\n");
				PQclear(res);
				return;
		}

		if (strcmp(tipo, "admin") == 0) {
				printf("Usuário admin criado com sucesso!\n");
				PQclear(res);
				return;  // Retorna ao menu inicial após criar o admin
		}

		// Para tipo "funcionario" ou "cliente", solicitamos mais informações
		printf("Digite o nome completo: ");
		getchar();  // Limpa o buffer do teclado
		fgets(nome, sizeof(nome), stdin);
		nome[strcspn(nome, "\n")] = 0;  // Remove o caractere '\n' no final

		printf("Digite o CPF (somente números): ");
		scanf("%s", cpf);

		if (strcmp(tipo, "funcionario") == 0) {
				snprintf(query, sizeof(query), "INSERT INTO funcionarios (nome, cpf) VALUES ('%s', '%s')", nome, cpf);
		} else if (strcmp(tipo, "cliente") == 0) {
				snprintf(query, sizeof(query), "INSERT INTO clientes (nome, cpf) VALUES ('%s', '%s')", nome, cpf);
		}

		res = PQexec(conexao, query);

		if (PQresultStatus(res) != PGRES_COMMAND_OK) {
				printf("Erro ao cadastrar %s.\n", tipo);
				PQclear(res);
				return;
		}

		printf("%s criado com sucesso!\n", tipo);
		PQclear(res);
}
