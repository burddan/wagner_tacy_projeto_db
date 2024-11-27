//listar_usuarios
void listar_usuarios(PGconn *conn) {
    const char *query = "SELECT id, username FROM usuarios";
    PGresult *res = PQexec(conn, query);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        fprintf(stderr, "Erro ao listar usuários: %s\n", PQerrorMessage(conn));
        PQclear(res);
        return;
    }

    int rows = PQntuples(res);
    printf("Número de usuários: %d\n", rows);
    for (int i = 0; i < rows; i++) {
        printf("ID: %s, usuario: %s\n", PQgetvalue(res, i, 0), PQgetvalue(res, i, 1));
    }

    PQclear(res);
}

