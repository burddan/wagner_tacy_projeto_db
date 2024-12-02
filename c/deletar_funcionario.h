void deletar_funcionario(PGconn *conexao, int user_id) {
    int idFuncionario;
    printf("Digite o ID do funcionário que deseja deletar: ");
    scanf("%d", &idFuncionario);

    const char *query = "DELETE FROM funcionarios WHERE idFuncionario = $1";
    char idFuncionarioStr[10];
    snprintf(idFuncionarioStr, 10, "%d", idFuncionario);
    const char *parametros[1] = {idFuncionarioStr};

    PGresult *resultado = PQexecParams(conexao, query, 1, NULL, parametros, NULL, NULL, 0);

    if (PQresultStatus(resultado) == PGRES_COMMAND_OK) {
        // Registrar a ação de deletar funcionário
        registrar_acao(conexao, user_id, "Deletou um funcionário");

        printf("Funcionário deletado com sucesso.\n");
    } else {
        fprintf(stderr, "Erro ao deletar funcionário: %s\n", PQerrorMessage(conexao));
    }

    PQclear(resultado);
}
