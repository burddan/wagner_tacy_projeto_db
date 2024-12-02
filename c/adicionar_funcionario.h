void adicionar_funcionario(PGconn *conexao) {
    char nome[100], cpf[12];
    char query[512];
    PGresult *res;

    printf("Digite o nome completo do funcionário: ");
    getchar();  // Limpa o buffer do teclado
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;  // Remove o caractere '\n' no final

    printf("Digite o CPF do funcionário (somente números): ");
    scanf("%s", cpf);

    // Inserir o funcionário na tabela de funcionários
    snprintf(query, sizeof(query), "INSERT INTO funcionarios (nome, cpf) VALUES ('%s', '%s')", nome, cpf);
    res = PQexec(conexao, query);

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        printf("Erro ao adicionar funcionário.\n");
        PQclear(res);
        return;
    }

    printf("Funcionário adicionado com sucesso!\n");
    PQclear(res);
}

