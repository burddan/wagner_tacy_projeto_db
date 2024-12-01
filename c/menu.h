void menu_inicial(PGconn *conexao);
void menu_admin(PGconn *conexao, int user_id);
void menu_funcionario(PGconn *conexao, int user_id);
void menu_cliente(PGconn *conexao, int user_id);

int autenticar_usuario(PGconn *conexao, int *user_id);
void cadastrar_usuario(PGconn *conexao);

void adicionar_produto(PGconn *conexao, int user_id);
void listar_produtos(PGconn *conexao);
void deletar_produto(PGconn *conexao, int user_id);


void menu_inicial(PGconn *conexao) {
    int opcao;
    int user_id;

    do {
        printf("1. Login\n");
        printf("2. Cadastrar Usuário\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (autenticar_usuario(conexao, &user_id)) {
                    printf("Login bem-sucedido! ID do usuário: %d\n", user_id);

                    if (user_id == 1) {
                        menu_admin(conexao, user_id);
                    } else {
                        // Verificar se é cliente ou funcionário
                        const char *query = "SELECT idPerfil_cliente FROM clientes WHERE idPerfil_cliente = $1";
                        char user_id_str[10];
                        snprintf(user_id_str, 10, "%d", user_id);
                        const char *params[1] = { user_id_str };

                        PGresult *resultado = PQexecParams(conexao, query, 1, NULL, params, NULL, NULL, 0);

                        if (PQntuples(resultado) > 0) {
                            menu_cliente(conexao, user_id);
                        } else {
                            menu_funcionario(conexao, user_id);
                        }
                        PQclear(resultado);
                    }
                }
                break;

            case 2:
                cadastrar_usuario(conexao);
                break;

            case 3:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 3);
}

void menu_admin(PGconn *conexao, int user_id) {
    int opcao;
    do {
        printf("\nMenu Admin:\n");
        printf("1. Cadastrar Usuário\n");
        printf("2. Adicionar Produto\n");
        printf("3. Listar Produtos\n");
        printf("4. Deletar Produto\n");
        printf("5. Adicionar Funcionário\n");
        printf("6. Deletar Funcionário\n");
        printf("7. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar_usuario(conexao);
                break;
            case 2:
                adicionar_produto(conexao, user_id);
                break;
            case 3:
                listar_produtos(conexao);
                break;
            case 4:
                deletar_produto(conexao, user_id);
                break;
            case 5:
                printf("Funcionalidade de adicionar funcionário em construção.\n");
                break;
            case 6:
                printf("Funcionalidade de deletar funcionário em construção.\n");
                break;
            case 7:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 7);
}

void menu_funcionario(PGconn *conexao, int user_id) {
    int opcao;
    do {
        printf("\nMenu Funcionário:\n");
        printf("1. Adicionar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Deletar Produto\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_produto(conexao, user_id);
                break;
            case 2:
                listar_produtos(conexao);
                break;
            case 3:
                deletar_produto(conexao, user_id);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 4);
}

void menu_cliente(PGconn *conexao, int user_id) {
    int opcao;
    do {
        printf("\nMenu Cliente:\n");
        printf("1. Listar Produtos\n");
        printf("2. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listar_produtos(conexao);
                break;
            case 2:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 2);
}

