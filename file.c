#include <stdio.h>
#include <locale.h>
/*
* Projeto Final
* Trabalho realizado por: João Devesa
*/

char file_name[50];
char* ext = ".bin";

struct class_file {	
	char student_name[50];
	int student_number;
};
struct class_file cf;

//SEARCH FILE
searchfile() {
	
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
			
			c = fgetc(nf);
		    while (c != EOF){
		        printf ("%c", c);
		        c = fgetc(nf);
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
	nf = fopen(filename, "wb");
	
	if (nf == NULL) {
    	printf(" Problems in file creation\n");
    	printf(" =======================================\n\n");
    	
    	system("pause");
   		return newfile();
    }
	printf(" =======================================\n\n");

	fclose(nf);
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
			/*fclose(nf);*/
			main();
			break;
		
		case 2:
			
			system("cls");
			printf(" ============ WRITE THE CLASS LIST ============\n");
			printf(" | Number of students in the class: ");
			scanf("%d", &input_number);
			printf(" |\n");
			for(i = 0; i < input_number; i++) {
				
				nf = fopen(filename, "ab");
				
				/*fwrite(&header, sizeof(header), 1, nf);*/
				
				printf(" | Student name: ");
				fflush(stdin);
				gets(cf.student_name);
				
				printf(" | Student number: ");
				fflush(stdin);
				scanf("%d", &cf.student_number);
				
				printf("\n");
				
				fwrite(&cf, sizeof(struct class_file), 1, nf);
				//fwrite(&line, sizeof(line), 1, nf);
				fclose(nf);		
			}
			
			
			
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
	
	int i, rows = 0;
	
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
	printf(" | How many lines do you want to change: ");
	fflush(stdin);
	scanf("%d", &rows);
	printf(" =============================================\n");
	
	for(i = 0; i < rows; i++) {
		
		system("cls");
		printf(" ================ UPDATE FILE ================\n");
		printf(" | Name of student: ");
		fflush(stdin);
		fscanf(uf, "%s", &cf.student_name);
		
		printf(" | Number of the same student: ");
		fflush(stdin);
		fscanf(uf, "%s", &cf.student_number);
		
		printf(" |                                           |\n");
		
		printf(" =============================================\n");
	}
	
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
	
