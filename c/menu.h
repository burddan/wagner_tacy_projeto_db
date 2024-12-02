//menu.h
void adicionar_produto(PGconn *conexao, int user_id);
void listar_produtos(PGconn *conexao);
void deletar_produto(PGconn *conexao, int user_id);

void menu_inicial(PGconn *conexao) {
		int opcao;

		do {
				printf("1. Login\n");
				printf("2. Cadastrar Usuário\n");
				printf("3. Sair\n");
				printf("Escolha uma opção: ");
				scanf("%d", &opcao);
				getchar();  // Limpa o buffer do teclado

				switch(opcao) {
						case 1:
								autenticar_usuario(conexao);
								break;
						case 2:
								cadastrar_usuario(conexao);
								break;
						case 3:
								printf("Saindo...\n");
								break;
						default:
								printf("Opção inválida. Tente novamente.\n");
				}
		} while (opcao != 3);
}

void menu_admin(PGconn *conexao) {
		int opcao;

		do {
				printf("Menu do admin\n");
				printf("1. Listar produto\n");
				printf("2. Adicionar produto\n");
				printf("3. Deletar produto\n");
				printf("4. Sair\n");
				printf("Escolha uma opção: ");
				scanf("%d", &opcao);
				getchar();  // Limpa o buffer do teclado

				switch(opcao) {
						case 1:
								listar_produtos(conexao);
								break;
						case 2:
								adicionar_produto(conexao, 1);  // 1 indica o código para o admin
								break;
						case 3:
								deletar_produto(conexao, 1);  // 1 indica o código para o admin
								break;
						case 4:
								printf("Saindo do menu administrador...\n");
								break;
						default:
								printf("Opção inválida. Tente novamente.\n");
				}
		} while (opcao != 4);
}

void menu_funcionario(PGconn *conexao) {
		int opcao;

		do {
				printf("Bem-vindo, Funcionário!\n");
				printf("1. Listar produto\n");
				printf("2. Adicionar produto\n");
				printf("3. Deletar produto\n");
				printf("4. Sair\n");
				printf("Escolha uma opção: ");
				scanf("%d", &opcao);
				getchar();  // Limpa o buffer do teclado

				switch(opcao) {
						case 1:
								listar_produtos(conexao);
								break;
						case 2:
								adicionar_produto(conexao, 1);  // 2 indica o código para o funcionário
								break;
						case 3:
								deletar_produto(conexao, 1);  // 2 indica o código para o funcionário
								break;
						case 4:
								printf("Saindo do menu funcionário...\n");
								break;
						default:
								printf("Opção inválida. Tente novamente.\n");
				}
		} while (opcao != 4);
}

void menu_cliente(PGconn *conexao) {
		int opcao;

		do {
				printf("Bem-vindo, Cliente!\n");
				printf("1. Listar produto\n");
				printf("2. Sair\n");
				printf("Escolha uma opção: ");
				scanf("%d", &opcao);
				getchar();  // Limpa o buffer do teclado

				switch(opcao) {
						case 1:
								listar_produtos(conexao);
								break;
						case 2:
								printf("Saindo do menu cliente...\n");
								break;
						default:
								printf("Opção inválida. Tente novamente.\n");
				}
		} while (opcao != 2);
}

