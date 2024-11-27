#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libpq-fe.h>

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

int main(int argc, char *argv[]) {
		if (argc != 4) {
				fprintf(stderr, "uso: %s <usuario> <senha> <database>\n", argv[0]);
				return 1;
		}

		char *usuario = argv[1];
		char *senha = argv[2];
		char *database = argv[3];

		char conexao[256];
		snprintf(conexao, 256, "user=%s password=%s dbname=%s", usuario, senha, database);

		PGconn *conn = PQconnectdb(conexao);

		if (PQstatus(conn) != CONNECTION_OK) {
				fprintf(stderr, "Erro ao conectar ao banco de dados: %s\n", PQerrorMessage(conn));
				PQfinish(conn);
				return 1;
		}

		printf("Conexão estabelecida com sucesso!\n");

		int opcao;
		int user_id;

		do {
				printf("\nEscolha uma opção:\n");
				printf("1. Login\n");
				printf("2. Cadastrar Usuário\n");
				printf("3. Sair\n");
				printf("Opção: ");
				scanf("%d", &opcao);

				switch (opcao) {
						case 1:
								if (autenticar_usuario(conn, &user_id)) {
										printf("Login bem-sucedido! ID do usuário: %d\n", user_id);
										// Aqui chamaremos as operações CRUD
								}
								break;
						case 2:
								cadastrar_usuario(conn);
								break;
						case 3:
								printf("Saindo...\n");
								break;
						default:
								printf("Opção inválida.\n");
				}
		} while (opcao != 3);

		PQfinish(conn);
		return 0;
}

