//menu.h
void menu(PGconn *conexao){
		int opcao;
		int user_id;

		do {
				printf("1. login\n");
				printf("2. cadastrar usuario\n");
				printf("3. sair\n");
				printf("escolha: ");
				scanf("%d", &opcao);

				switch (opcao) {
						case 1:
								if (autenticar_usuario(conexao, &user_id)) {
										printf("login bem-sucedido! id do usuario: %d\n", user_id);
								}
								break;
						case 2:
								cadastrar_usuario(conexao);
								break;
						case 3:
								printf("saindo...\n");
								break;
						default:
								printf("opcao invalida\n");
				}
		} while (opcao != 3);

}
