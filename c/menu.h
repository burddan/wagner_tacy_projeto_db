void adicionar_produto(PGconn *conexao, int user_id);
void listar_produtos(PGconn *conexao);
void deletar_produto(PGconn *conexao, int user_id);
void adicionar_funcionario(PGconn *conexao, int user_id);
void deletar_funcionario(PGconn *conexao, int user_id);

void menu(PGconn *conexao) {
		int opcao;
		int user_id = 0;  // Inicializa o ID do usuário como 0 (não logado).

		do {
				printf("\nmenu:\n");
				printf("1. login\n");
				printf("2. cadastrar usuario\n");
				printf("3. adcionar produto\n");
				printf("4. listar produto\n");
				printf("5. deletar produto\n");
				printf("6. adicionar funcionario \n");
				printf("7. deletar funcionario\n");
				printf("8. sair\n");
				printf("escolha uma opcao: ");
				scanf("%d", &opcao);

				switch (opcao) {
						case 1:
								if (autenticar_usuario(conexao, &user_id)) {
										printf("login bem-sucedido! ID do usuario: %d\n", user_id);
								}
								break;
						case 2:
								cadastrar_usuario(conexao);
								break;
						case 3:
								if (user_id) {
										adicionar_produto(conexao, user_id);
								} else {
										printf("faça login primeiro\n");
								}
								break;
						case 4:
								listar_produtos(conexao);
								break;
						case 5:
								if (user_id) {
										deletar_produto(conexao, user_id);
								} else {
										printf("faça login primeiro\n");
								}
								break;
						case 6:
								if (user_id) {
										adicionar_funcionario(conexao, user_id);
								} else {
										printf("por favor faça login primeiro\n");
								}
								break;
						case 7:
								if (user_id) {
										deletar_funcionario(conexao, user_id);
								} else {
										printf("por favor, faça login primeiro\n");
								}
								break;
						case 8:
								printf("saindo...\n");
								break;
						default:
								printf("Opção inválida.\n");
				}
		} while (opcao != 8);
}

