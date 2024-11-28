//menu.h
void menu(PGconn *conexao){
		int opcao;
		int user_id;

		do {
				printf("\nEscolha uma opção:\n");
				printf("1. Login\n");
				printf("2. Cadastrar Usuário\n");
				printf("3. Sair\n");
				printf("Opção: ");
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
								printf("Saindo...\n");
								break;
						default:
								printf("Opção inválida.\n");
				}
		} while (opcao != 3);

}
