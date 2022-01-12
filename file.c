#include <stdio.h>
#include <locale.h>
/*
* Projeto Final
* Trabalho realizado por: João Devesa
*/

char file_name[50];
char* ext = ".bin";

int input_number = 0;

struct class_file {	
	char student_name[100];
	char student_number[10];
};

struct class_file cf;

//SEARCH FILE
searchfile() {
	
	system("cls");
	
	printf(" ========== SEARCH FILE ==========\n");
	printf(" | FILE NAME: ");
	
	//READ FILE
	fflush(stdin);
	gets(file_name);

	char* filename = malloc(strlen(file_name) + strlen(ext) + 1);
	sprintf(filename, "Files/%s%s", file_name, ext);
	
	free(filename);
	FILE *nf;
	
	nf = fopen(filename, "rb");
	
	if (nf == NULL) {
    	printf(" | File not found\n");
    	printf(" =================================\n\n");
    	
		system("pause");
   		return searchfile();
    }
	printf(" =================================\n");
}

//SEARCH FILE MENU
searchfile_menu() {
	
	int menu;
	
	system("cls");
	
	//MENU
	printf(" ======== SEARCH FILE MENU ========\n");
	printf(" | [1] - Back to main             |\n");
	printf(" | [2] - Open in Directory        |\n");
	printf(" | [3] - Read File                |\n");
	printf(" | [4] - Edit File                |\n");
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
			readfile();
			break;
		
		case 4:
			editfile();
			
			break;
		
		default:
			printf("Choose a option in the menu");
			system("pause");
			
			searchfile_menu();
			break;
	}
}

//READ FILE
readfile() {
	
	char c;
	
	char* filename = malloc(strlen(file_name) + strlen(ext) + 1);
	sprintf(filename, "Files/%s%s", file_name, ext);
	
	FILE *nf;
	
	nf = fopen(filename, "rb");
	
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
}

//CREATE FILE
newfile() {
		
	setlocale(LC_ALL, "");
	
	int i, menu;
	
	char header[] = " CLASS: \n\n NANE: \t\t\t\t\t\t\t\t\tNUMBER:\n\n";
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
			fwrite(&header, sizeof(header), 1, nf);
			
			system("cls");
			printf(" ============ WRITE THE CLASS LIST ============\n");
			printf(" | Number of students in the class: ");
			scanf("%d", &input_number);
			printf(" |\n");
			for(i = 1; i <= input_number; i++) {
				printf(" | Student name: ");
				fflush(stdin);
				gets(cf.student_name);
				
				fwrite(&cf.student_name, sizeof(struct class_file), 1, nf);
				
				printf(" | Student number: ");
				fflush(stdin);
				gets(cf.student_number);
				
				fwrite(&cf.student_number, sizeof(struct class_file), 1, nf);
				
				printf("\n");
				fwrite(&line, sizeof(line), 1, nf);			
			}
			fclose(nf);
			system("cls");
			printf(" File created and edited successfully\n");
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

editfile() {
	
	main();
}

deletefile() {
	
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
	}
	else {
		printf(" | File not existing or not able to delete    |\n");
		printf(" ==============================================\n");
		sleep(1);
		deletefile();
	}
	printf(" ==============================================\n");
	sleep(1);
	main();
}

