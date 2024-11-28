#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libpq-fe.h>
#include "cadastrar_usuario.h"
#include "autenticar_usuario.h"
#include "listar_usuarios.h"
#include "menu.h"


int main(int argc, char *argv[]) {
		if (argc != 5) {
				fprintf(stderr, "uso: %s <usuario> <senha> <database> <host>\n", argv[0]);
				return 1;
		}

		char *usuario = argv[1];
		char *senha = argv[2];
		char *database = argv[3];
		char *host= argv[4];

		char login[256];
		snprintf(login, 256, "user=%s password=%s dbname=%s host=%s", usuario, senha, database, host);

		PGconn *conexao = PQconnectdb(login);

		if (PQstatus(conexao) != CONNECTION_OK) {
				printf("erro ao conectar ao banco de dados\n");
				PQfinish(conexao);
				return 1;
		}
		listar_usuarios(conexao);
		menu(conexao);

		PQfinish(conexao);
		return 0;
}

