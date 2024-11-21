#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

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
		printf("erro conexao\n");
        PQfinish(conn);
        return 1;
    }


    PQfinish(conn);
	printf("sucesso\n");

    return 0;
}

