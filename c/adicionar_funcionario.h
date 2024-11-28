void adicionar_funcionario(PGconn *conexao, int user_id) {
    char nome[100], cpf[12], cargo[50], horario[50];
    int idade;
    float salario;

    printf("Digite o nome do funcionário: ");
    scanf("%99s", nome);
    printf("Digite o CPF do funcionário: ");
    scanf("%11s", cpf);
    printf("Digite a idade do funcionário: ");
    scanf("%d", &idade);
    printf("Digite o cargo do funcionário: ");
    scanf("%49s", cargo);
    printf("Digite o salário do funcionário: ");
    scanf("%f", &salario);
    printf("Digite o horário de trabalho: ");
    scanf("%49s", horario);

    const char *query = "INSERT INTO Funcionario (nome, cpf, idade, cargo, salario, horario_trabalho, idPadaria) VALUES ($1, $2, $3, $4, $5, $6, 1)";
    char idadeStr[10], salarioStr[20];
    snprintf(idadeStr, 10, "%d", idade);
    snprintf(salarioStr, 20, "%.2f", salario);

    const char *parametros[6] = {nome, cpf, idadeStr, cargo, salarioStr, horario};

    PGresult *resultado = PQexecParams(conexao, query, 6, NULL, parametros, NULL, NULL, 0);

    if (PQresultStatus(resultado) == PGRES_COMMAND_OK) {
        printf("Funcionário adicionado com sucesso.\n");
        registrar_acao(conexao, user_id, "Adicionou um funcionário");
    } else {
        fprintf(stderr, "Erro ao adicionar funcionário: %s\n", PQerrorMessage(conexao));
    }

    PQclear(resultado);
}

