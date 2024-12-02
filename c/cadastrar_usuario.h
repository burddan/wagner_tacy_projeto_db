void registrar_acao(PGconn *conexao, int user_id, const char *acao);

void cadastrar_usuario(PGconn *conexao) {
		char username[50], password[50], tipo[20];
		char nome[100], cpf[12];
		PGresult *resultado;
		char consulta[512];

		printf("Digite o username: ");
		scanf("%s", username);
		printf("Digite a senha: ");
		scanf("%s", password);
		printf("Digite o tipo (admin, funcionario, cliente): ");
		scanf("%s", tipo);

		snprintf(consulta, 512, "INSERT INTO usuarios (username, password, tipo) VALUES ('%s', '%s', '%s')", username, password, tipo);
		resultado = PQexec(conexao, consulta);

		if (PQresultStatus(resultado) != PGRES_COMMAND_OK) {
				printf("Erro ao cadastrar usuario\n");
				PQclear(resultado);
				return;
		}

		if (strcmp(tipo, "admin") == 0) {
				printf("Usuario admin criado\n");
				PQclear(resultado);
				return;  
		}

		printf("Digite o nome completo: ");
		getchar();  
		fgets(nome, 100, stdin);
		nome[strcspn(nome, "\n")] = 0;  

		printf("Digite o cpf: ");
		scanf("%s", cpf);

		if (strcmp(tipo, "funcionario") == 0) {
				snprintf(consulta, 512, "INSERT INTO funcionarios (nome, cpf) VALUES ('%s', '%s')", nome, cpf);
		} else if (strcmp(tipo, "cliente") == 0) {
				snprintf(consulta, 512, "INSERT INTO clientes (nome, cpf) VALUES ('%s', '%s')", nome, cpf);
		}

		resultado = PQexec(conexao, consulta);

		if (PQresultStatus(resultado) != PGRES_COMMAND_OK) {
				printf("Erro ao cadastrar %s\n", tipo);
				PQclear(resultado);
				return;
		}

		printf("%s criado\n", tipo);
		PQclear(resultado);
}
