//registrar_acao.h
void registrar_acao(PGconn *conexao, int user_id, const char *acao) {
    const char *consulta = "INSERT INTO logs (user_id, acao) VALUES ($1, $2)";
    char userid_string[10];
    snprintf(userid_string, 10, "%d", user_id);
    const char *parametros[2] = {userid_string, acao};

    PGresult *resultado = PQexecParams(conexao, consulta, 2, NULL, parametros, NULL, NULL, 0);

    if (PQresultStatus(resultado) != PGRES_COMMAND_OK) {
        fprintf(stderr, "Erro ao registrar ação: %s\n", PQerrorMessage(conexao));
		// printf("erro ao registrar log\n");
    }

    PQclear(resultado);
}

