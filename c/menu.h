void adicionar_produto(PGconn *conexao, int user_id);
void listar_produtos(PGconn *conexao);
void deletar_produto(PGconn *conexao, int user_id);
void adicionar_funcionario(PGconn *conexao, int user_id);
void deletar_funcionario(PGconn *conexao, int user_id);

void menu(PGconn *conexao) {
		int opcao;
		int user_id = 0;  // Inicializa o ID do usuário como 0 (não logado).

		do {
				printf("\nMenu:\n");
				printf("1. Login\n");
				printf("2. Cadastrar Usuário\n");
				printf("3. Adicionar Produto\n");
				printf("4. Listar Produtos\n");
				printf("5. Deletar Produto\n");
				printf("6. Adicionar Funcionário\n");
				printf("7. Deletar Funcionário\n");
				printf("8. Sair\n");
				printf("Escolha uma opção: ");
				scanf("%d", &opcao);

				switch (opcao) {
						case 1:
								if (autenticar_usuario(conexao, &user_id)) {
										printf("Login bem-sucedido! ID do usuário: %d\n", user_id);
								}
								break;
						case 2:
								cadastrar_usuario(conexao);
								break;
						case 3:
								if (user_id) {
										adicionar_produto(conexao, user_id);
								} else {
										printf("Por favor, faça login primeiro.\n");
								}
								break;
						case 4:
								listar_produtos(conexao);
								break;
						case 5:
								if (user_id) {
										deletar_produto(conexao, user_id);
								} else {
										printf("Por favor, faça login primeiro.\n");
								}
								break;
						case 6:
								if (user_id) {
										adicionar_funcionario(conexao, user_id);
								} else {
										printf("Por favor, faça login primeiro.\n");
								}
								break;
						case 7:
								if (user_id) {
										deletar_funcionario(conexao, user_id);
								} else {
										printf("Por favor, faça login primeiro.\n");
								}
								break;
						case 8:
								printf("Saindo...\n");
								break;
						default:
								printf("Opção inválida.\n");
				}
		} while (opcao != 8);
}

