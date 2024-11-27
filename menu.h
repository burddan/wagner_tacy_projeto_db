void menu(PGconn *conn){
		int opcao;
		int user_id;

		do {
				printf("\nEscolha uma opção:\n");
				printf("1. Login\n");
				printf("2. Cadastrar Usuário\n");
				printf("3. Sair\n");
				printf("Opção: ");
				scanf("%d", &opcao);
				listar_usuarios(conn);

				switch (opcao) {
						case 1:
								if (autenticar_usuario(conn, &user_id)) {
										printf("Login bem-sucedido! ID do usuário: %d\n", user_id);
								}
								break;
						case 2:
								cadastrar_usuario(conn);
								break;
						case 3:
								printf("Saindo...\n");
								break;
						default:
								printf("Opção inválida.\n");
				}
		} while (opcao != 3);

}
