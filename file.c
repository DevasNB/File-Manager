#include <stdio.h>
#include <locale.h>
/*
* Projeto Final
* Trabalho realizado por: João Devesa
*/

char file_name[50];
char* ext = ".bin";

struct recipt {	
	int number_receipt;
	int nif;
	float price;
};
struct recipt rec;

//SEARCH FILE
listfile() {
	
	int menu;
	char c;
	
	system("cls");
	printf(" ========== SEARCH FILE ==========\n");
	printf(" | FILE NAME: ");
	fflush(stdin);
	gets(file_name);

	char* filename = malloc(strlen(file_name) + strlen(ext) + 1);
	sprintf(filename, "Files/%s%s", file_name, ext);
	
	free(filename);
	
	FILE *nf;
	nf = fopen(filename, "rb");
	
	if (nf == NULL) {
    	printf(" | File not found                |\n");
    	printf(" =================================\n\n");
    	
		system("pause");
   		return searchfile();
    }
	printf(" =================================\n");
	
	//MENU
	system("cls");
	printf(" ======== SEARCH FILE MENU ========\n");
	printf(" | [1] - Back to main             |\n");
	printf(" | [2] - Open in Directory        |\n");
	printf(" | [3] - Read File                |\n");
	printf(" ==================================\n");
	
	printf(" R: ");
	scanf("%d", &menu);
	
	switch(menu) {
		case 1:
			main();
			break;
		
		case 2: 
			system("start \"\" \"\Files\"");
			main();
			break;
			
		case 3:
			system("cls");
			printf(" ============ FILE INFORMATION ============\n\n");
			
			while(fread(&rec, sizeof(rec), 1, nf)){
				
				printf(" | Number reciept: %d \n", rec.number_receipt);
				printf(" | Quantidade de pecas: %d \n", rec.nif);
				printf(" | Preco da peca: %.2f \n", rec.price);
			}

			printf("\n\n ==========================================\n");
			system("pause");
			main();
			break;
		
		default:
			printf("Choose a option in the menu");
			system("pause");
			
			searchfile();
			break;
	}
}

//CREATE FILE
newfile() {
		
	setlocale(LC_ALL, "");
	
	int i, menu;
	
	int input_number = 0;
	
	char header[] = " CLASS: \n\n NAME: \t\t\t\t\t\t\t\tNUMBER:\n\n";
	char line[] = "____________________________________________________________________________________________________\n";
	
	//FILE NAME AND EXTENSION
	system("cls");
	printf(" ============== NEW CLASS ==============\n");
	printf(" | Class name: ");
	
	//INSERT FILE NAME
	fflush(stdin);
	gets(file_name);
	
	char* filename = malloc(strlen(file_name) + strlen(ext) + 1);
	sprintf(filename, "Files/%s%s", file_name, ext);
	
	free(filename);
	
	//CREATE FILE
	FILE *nf;	
	nf = fopen(filename, "ab");
	
	if (nf == NULL) {
    	printf(" Problems in file creation\n");
    	printf(" =======================================\n\n");
    	
    	system("pause");
   		return newfile();
    }
	printf(" =======================================\n\n");

	//NEW FILE EDIT MENU
	system("pause");
	system("cls");
	
	//MENU
	printf(" ========== NEW FILE MENU =========\n");
	printf(" | [1] - Back to main             |\n");
	printf(" | [2] - Add information to file  |\n");
	printf(" ==================================\n");
	
	printf(" R: ");
	fflush(stdin);
	scanf("%d", &menu);
	
	switch(menu) {
		case 1:
			fclose(nf);
			main();
			break;
		
		case 2:
			
			system("cls");
			printf(" ============ WRITE THE CLASS LIST ============\n");			
			printf(" | Reciept number: ");
			fflush(stdin);
			scanf("%d", &rec.number_receipt);
				
			printf(" | NIF number: ");
			fflush(stdin);
			scanf("%d", &rec.nif);
			
			printf(" | Price: ");
			fflush(stdin);
			scanf("%f", &rec.price);
			
			fwrite(&rec, sizeof(rec), 1, nf);
			
			fclose(nf);	
					
			system("cls");
			printf(" File created and edited successfully\n\n");
			system("pause");
			main();
			break;
		
		default:
			system("cls");
			printf("\n Choose a option in the menu\n\n");
			system("pause");
			
			remove(filename);
			newfile();
			break;
	}
}

updatefile() {
	
	system("cls");
	printf(" ========== UPDATE FILE ==========\n");
	printf(" | FILE NAME: ");
	fflush(stdin);
	gets(file_name);

	char* filename = malloc(strlen(file_name) + strlen(ext) + 1);
	sprintf(filename, "Files/%s%s", file_name, ext);
	
	free(filename);
	
	FILE *uf;
	uf = fopen(filename, "rb+");
	
	if (uf == NULL) {
    	printf(" | File not found                |\n");
    	printf(" =================================\n\n");
    	
		system("pause");
   		return updatefile();
    }
	printf(" =================================\n");
	
	system("cls");
	printf(" ================ UPDATE FILE ================\n");
	printf(" | Reciept number: ");
	fflush(stdin);
	fscanf(uf, "%d", &rec.number_receipt);
	printf(" =============================================\n");
}

deletefile() {
	
	int i = 0, trys = 3;
	
	for (i = 0; i < 3; i++) {
		
		system("cls");
		printf(" ================= DELETE FILE ================\n");
		printf(" | FILE NAME: ");
		
		fflush(stdin);
		gets(file_name);
	
		char* filename = malloc(strlen(file_name) + strlen(ext) + 1);
		sprintf(filename, "Files/%s%s", file_name, ext);
		
		free(filename);
		
		if(remove(filename) == 0) {
			printf(" | File deleted successfull                   |\n");
			printf(" ==============================================\n");
			
			sleep(1);
			main();
		}
		else {
			printf(" | File not existing or not able to delete    |\n");
			printf(" ==============================================\n\n");
			
			trys = trys - 1;
			
			if(trys == 0) {
				printf("  Back to main!");
			}
			else {
				printf("  %d more attemptions!", trys);
			}
			
			
			sleep(1);
		}
	}
	sleep(1),
	main();
}
	
