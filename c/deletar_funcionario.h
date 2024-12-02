void deletar_funcionario(PGconn *conexao, int user_id) {
    int idfuncionario;
    printf("Digite o id do funcionário pra deletar: ");
    scanf("%d", &idfuncionario);

    const char *consulta = "DELETE FROM funcionarios WHERE idFuncionario = $1";
    char idfuncionariostr[10]; // gambiarra q tem q fazer
    snprintf(idfuncionariostr, 10, "%d", idfuncionario);
    const char *parametros[1] = {idfuncionariostr};

    PGresult *resultado = PQexecParams(conexao, consulta, 1, NULL, parametros, NULL, NULL, 0);

    if (PQresultStatus(resultado) == PGRES_COMMAND_OK) {
        registrar_acao(conexao, user_id, "Deletou um funcionario\n");

        printf("Funcionário deletado com sucesso.\n");
    } else {
		printf("erro ao deletar funcionario\n");
    }

    PQclear(resultado);
}
