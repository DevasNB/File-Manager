#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
/*
* Trabalho final 
*  João Devesa 2455
*/

struct recibos{
	int numero_recibo;
	char nome_pessoa[100];
	int nif;
	int preco;
};
struct recibos rec;

main() {
	
	setlocale(LC_ALL, "");
	
	int op;
	
	system("cls");
	printf("\n\n\n\n");
	printf("\t\t   *********    *********    *********    ***    *******      *********    *********\n");
	printf("\t\t   *********    *********    *********    ***    ********     *********    *********\n");
	printf("\t\t   ***   ***    ***          ***                 ***   ***    ***   ***    ***      \n");
	printf("\t\t   ***   ***    ***          ***          ***    ***   ***    ***   ***    ***      \n");
	printf("\t\t   *********    *********    ***          ***    *** ***      ***   ***    *********\n");
	printf("\t\t   *********    *********    ***          ***    *** ***      ***   ***    *********\n");
	printf("\t\t   *** ***      ***          ***          ***    ***   ***    ***   ***          ***\n");
	printf("\t\t   ***  ***     ***          ***          ***    ***   ***    ***   ***          ***\n");
	printf("\t\t   ***   ***    *********    *********    ***    ********     *********    *********\n");
	printf("\t\t   ***    ***   *********    *********    ***    *******      *********    *********\n");
	
	printf("\n\n\t\t\t\t       | CLICA EM QUALQUER TECLA PARA CONTINUAR  | \n\n\n\n");
	
	system("pause");
	sleep(1);
	
	system("cls");
		
	printf("                  MENU\n");
	printf(" ======================================\n");
	printf(" |                                    |\n");
	printf(" | Escolha uma das opões do menu:     |\n");
	printf(" | [1]: Inserir                       |\n");
	printf(" | [2]: Listar                        |\n");
	printf(" | [3]: Pesquisar                     |\n");
	printf(" | [4]: Atualizar                     |\n");
	printf(" | [5]: Eliminar                      |\n");
	printf(" | [6]: Abrir ficheiro no diretório   |\n");
	printf(" | [7]: Sair                          |\n");
	printf(" |                                    |\n");
	printf(" | [0]: Informação                    |\n");
	printf(" | R: ");
	
	fflush(stdin);
	scanf("%d", &op);
	
	printf(" |                                    |\n");
	printf(" ======================================\n");
	
	switch(op){
		case 1:
			inserir();
			break;
				
		case 2:
			listar();
			break;
				
		case 3:
			pesquisar();
			break;
				
		case 4:
			atualizar();
			break;
				
		case 5:
			eliminar();
			break;
		
		case 6:
			system("start \"\" \"\"");
			main();
			break;
			
		case 7:
			system("exit");
			return;
			
		case 0:
			main();
			break;
			
		default:
			system("cls");
			printf(" ======================================\n");
			printf(" |                                    |\n");
			printf(" | ESCOLHA UMA OPÇÃO DO MENU          |\n");
			printf(" |                                    |\n");
			printf(" ======================================\n\n");
			system("pause");
			main();
			break;
		}
}

inserir(){
	
	FILE *recibo;
	
	recibo = fopen("recibo.bin","ab");
	
	if(recibo == NULL){
		printf(" ======================================\n");
		printf(" |                                    |\n");
		printf(" | ERRO AO ENCONTRAR OU LER FICHEIRO  |\n");
		printf(" |                                    |\n");
		printf(" ======================================\n");
		return;
	}
	
	do{
		system("cls");
		printf("            INSERIR DADOS\n");
		printf(" =====================================\n");
		printf(" |                                   |\n");
		printf(" | Digite o numero de recibo:        |\n");
		printf(" | R: ");
		
		scanf("%d", &rec.numero_recibo);
		
		printf(" |                                   |\n");
		printf(" | Digite o nome de cliente:         |\n");
		printf(" | R: ");
		
		scanf("%s", &rec.nome_pessoa);
		
		printf(" |                                   |\n");
		printf(" |Digite o nif de cliente:           |\n");
		printf(" | R: ");
		
		scanf("%d", &rec.nif);
		
		printf(" |                                   |\n");
		printf(" | Digite o preco da compra:         |\n");
		printf(" | R: ");
		
		scanf("%d", &rec.preco);
		
		printf(" |                                   |\n");
		printf(" =====================================\n");
		
		fwrite(&rec, sizeof(rec), 1, recibo);
		
		sleep(1);
		system("cls");
		
		printf("                  MENU\n");
		printf(" ======================================\n");
		printf(" |                                    |\n");
		printf(" | [QUALQUER TECLA]: Continuar        |\n");
		printf(" | [ESC]: Sair                        |\n");
		printf(" |                                    |\n");
		printf(" ======================================\n");
		
		fflush(stdin);
		
	}while(getch() != 27);
	
	fclose(recibo);
	
	system("cls");
	
	printf(" ======================================\n");
	printf(" |                                    |\n");
	printf(" | RECIBO GUARDADO COM SUCESSO        |\n");
	printf(" |                                    |\n");
	printf(" ======================================\n");
	system("pause");
	
	main();
}

listar(){
	
	int check = 0;
	
	FILE *recibo;
	
	recibo = fopen("recibo.bin","rb");
	
	if(recibo == NULL){
		printf(" ======================================\n");
		printf(" |                                    |\n");
		printf(" | ERRO AO ENCONTRAR OU LER FICHEIRO  |\n");
		printf(" |                                    |\n");
		printf(" ======================================\n");
		return;
	}
	
	system("cls");
	printf("                 RECIBOS\n");
	
	while(fread(&rec, sizeof(rec), 1, recibo)){
		
		check = 1;
		
		printf(" ======================================\n");
		printf(" |                                    |\n");
		
		printf(" | Numero de recibo: %d \n", rec.numero_recibo);
		printf(" | Nome de cliente: %s \n", rec.nome_pessoa);
		printf(" | NIF de cliente: %d \n", rec.nif);
		printf(" | Preco da compra: %d \n", rec.preco);
		
		printf(" |                                    |\n");
		printf(" ======================================\n");
	}
	
	if(check == 0){
		system("cls");
		printf(" ======================================\n");
		printf(" |                                    |\n");
		printf(" | NÃO HÁ RECIBOS REGISTADOS          |\n");
		printf(" |                                    |\n");
		printf(" ======================================\n");
	}

	fclose(recibo);
	system("pause");
	system("cls");
	main();
}


pesquisar(){
	
	int num;
	int check = 0, tentativas = 3;
	
	FILE *recibo;
	
	recibo = fopen("recibo.bin","rb");
	
	if(recibo == NULL){
		printf(" ======================================\n");
		printf(" |                                    |\n");
		printf(" | ERRO AO ENCONTRAR OU LER FICHEIRO  |\n");
		printf(" |                                    |\n");
		printf(" ======================================\n");
		return;
	}
	
	system("cls");
	printf("                PESQUIAR\n");
	printf(" ======================================\n");
	printf(" |                                    |\n");
	printf(" | Digite o numero de recibo:         |\n");
	printf(" | R: ");
	
	scanf("%d", &num);
	
	printf(" |                                    |\n");
	printf(" ======================================\n");
	
	sleep(1);
	system("cls");
	printf("                 RECIBO\n");
	
	while(fread(&rec, sizeof(rec), 1, recibo)){
		if(rec.numero_recibo == num){
			
			printf(" ======================================\n");
			printf(" |                                    |\n");
			
			printf(" | Numero de recibo: %d \n", rec.numero_recibo);
			printf(" | Nome de cliente: %s \n", rec.nome_pessoa);
			printf(" | NIF de cliente: %d \n", rec.nif);
			printf(" | Preco da compra: %d \n", rec.preco);
		
			printf(" |                                    |\n");
			printf(" ======================================\n");
		
			check = 1;
			break;
		}
	}
	
	if(check == 0){
		if(tentativas == 0) {
			
			system("cls");
			printf(" ======================================\n");
			printf(" |                                    |\n");
			printf(" | RECIBO NUMERO %d NÃO EXISTE \n", num);
			printf(" | A VOLTAR PARA O INICIO             |\n");
			printf(" |                                    |\n");
			printf(" ======================================\n\n");
			
			fclose(recibo);
			sleep(1);
			system("cls");
			main();
		}
		else {
			
			tentativas = tentativas - 1;
			
			system("cls");
			printf(" ======================================\n");
			printf(" |                                    |\n");
			printf(" | RECIBO NUMERO %d NÃO EXISTE \n", num);
			printf(" | %d TENTATIVAS RESTANTES             |\n", tentativas);
			printf(" |                                    |\n");
			printf(" ======================================\n\n");
			
			fclose(recibo);
			
			system("pause");
			pesquisar();
		}
	}
}

atualizar(){
	
	FILE *recibo;
	
	recibo = fopen("recibo.bin","rb+");
	
	int num;
	int check = 0;
	
	if(recibo == NULL){
		printf(" ======================================\n");
		printf(" |                                    |\n");
		printf(" | ERRO AO ENCONTRAR OU LER FICHEIRO  |\n");
		printf(" |                                    |\n");
		printf(" ======================================\n");
		return;
	}
	
	system("cls");
	printf("             ATUALIZAR DADOS\n");
	printf(" ======================================\n");
	printf(" |                                    |\n");
	printf(" | Digite o numero de recibo:         |\n");
	printf(" | R: ");
	
	scanf("%d", &num);
	
	printf(" |                                    |\n");
	printf(" ======================================\n");
	
	sleep(1);
	system("cls");
		
	while(fread(&rec, sizeof(rec), 1, recibo)){
		if(rec.numero_recibo == num){
			printf("            ALTERAR DADOS\n");
			printf(" =====================================\n");
			printf(" |                                   |\n");
			printf(" | Digite o numero de recibo:        |\n");
			printf(" | R: ");
			
			scanf("%d", &rec.numero_recibo);
			
			printf(" |                                   |\n");
			printf(" | Digite o nome de cliente:         |\n");
			printf(" | R: ");
			
			scanf("%s", &rec.nome_pessoa);
			
			printf(" |                                   |\n");
			printf(" | Digite o nif de cliente:          |\n");
			printf(" | R: ");
			
			scanf("%d", &rec.nif);
			
			printf(" |                                   |\n");
			printf(" | Digite o preco da compra:         |\n");
			printf(" | R: ");
			
			scanf("%d", &rec.preco);
			
			printf(" |                                   |\n");
			printf(" =====================================\n");
			
			fseek(recibo,-sizeof(rec),1);
			fwrite(&rec,sizeof(rec),1,recibo);
			
			check = 1;
			break;
		}
	}
	
	system("cls");
	
	if(check == 1){
		printf(" ======================================\n");
		printf(" |                                    |\n");
		printf(" | DADOS DO RECIBO %d \n", num);
		printf(" | ATUALIZADOS COM SUCESSO            |\n");
		printf(" |                                    |\n");
		printf(" ======================================\n\n");
	}
	else {
		printf(" ======================================\n");
		printf(" |                                    |\n");
		printf(" | RECIBO %d NÃO EXISTE \n", num);
		printf(" |                                    |\n");
		printf(" ======================================\n\n");
	}

	fclose(recibo);		
	system("pause");
	system("cls");
}

eliminar(){
	
	FILE *recibo;
	FILE *backup;
	
	recibo = fopen("recibo.bin","rb");
	
	int num;
	int check = 0;
	
	if(recibo == NULL){
		printf(" ======================================\n");
		printf(" |                                    |\n");
		printf(" | ERRO AO ENCONTRAR OU LER FICHEIRO  |\n");
		printf(" |                                    |\n");
		printf(" ======================================\n");
		return;
	}
	
	backup = fopen("backup.bin","ab");
	
	system("cls");
	printf(" ======================================\n");
	printf(" |                                    |\n");
	printf(" | Digite o numero de recibo:         |\n");
	printf(" | R: ");
	
	scanf("%d", &num);
	
	printf(" |                                    |\n");
	printf(" ======================================\n");
	
	sleep(1);
	
	while(fread(&rec, sizeof(rec), 1, recibo)){
		if(rec.numero_recibo != num){
			
			fwrite(&rec, sizeof(rec), 1, backup);
		}
	}
	
	fclose(recibo);
	fclose(backup);
	
	remove("recibo.bin");
    rename("backup.bin", "recibo.bin");
    
    system("cls");
	printf(" ======================================\n");
	printf(" |                                    |\n");
	printf(" | RECIBO ELIMINADO                   |\n");
	printf(" |                                    |\n");
	printf(" ======================================\n\n");
	
	system("pause");
	system("cls");
	main();
}
