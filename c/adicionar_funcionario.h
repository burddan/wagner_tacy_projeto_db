void adicionar_funcionario(PGconn *conexao, int user_id) {
    char nome[100], cpf[12];
    char consulta[512];
    PGresult *resultado;

    printf("Digite o nome completo do funcionario: ");
    getchar();  
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;  // Remove o caractere '\n' no final

    printf("Digite o cpf do funcionario: ");
    scanf("%s", cpf);

    snprintf(consulta, 256, "INSERT INTO funcionarios (nome, cpf) VALUES ('%s', '%s')", nome, cpf);
    resultado = PQexec(conexao, consulta);

    if (PQresultStatus(resultado) != PGRES_COMMAND_OK) {
        printf("Erro ao adicionar funcionario\n");
        PQclear(resultado);
        return;
    }

    registrar_acao(conexao, user_id, "Adicionou um novo funcionario");

    printf("Funcionario adicionado\n");
    PQclear(resultado);
}
