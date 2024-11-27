#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libpq-fe.h>
#include "cadastrar_usuario.h"
#include "autenticar_usuario.h"


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

