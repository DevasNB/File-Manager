#include <stdio.h>
#include <locale.h>
/*
* Projeto Final
* Trabalho realizado por: João Devesa
*/
char file_name[50];
char* ext = ".dat";
	
newfile() {
		
	setlocale(LC_ALL, "");
	
	//FILE NAME AND EXTENSION
	int input_number;

	FILE *nf;
	
	system("cls");
	printf(" ============== NEW CLASS ==============\n");
	printf(" | Class name: ");
	
	//INSERT FILE NAME
	fflush(stdin);
	gets(file_name);
	
	char* filename = malloc(strlen(file_name) + strlen(ext) + 1);
	sprintf(filename, "Files/%s%s", file_name, ext);
	
	//CREATE FILE
	nf = fopen(filename, "w");
	free(filename);
	
	if (nf == NULL) {
    	printf(" Problems in file creation\n");
    	printf(" =======================================\n\n");
    	system("pause");
   		return newfile();
    }
	
	printf(" | Number of students in the class: ");
	scanf("%d", &input_number);
	printf(" =======================================\n\n");
	
	fclose(nf);
	system("pause");
	//NEW FILE EDIT MENU
	newfile_edit_menu();
}

newfile_edit_menu() {
	
	int menu;
	
	system("cls");
	
	//MENU
	printf(" ========== NEW FILE MENU =========\n");
	printf(" | [1] - Back to main             |\n");
	printf(" | [2] - Add information to file  |\n");
	printf(" ==================================\n");
	
	printf(" R: ");
	scanf("%d", &menu);
	
	switch(menu) {
		case 1:
			main();
			break;
		
		case 2:
			newfile_edit();
			break;
		
		default:
			printf("Choose a option in the menu");
			system("pause");
			
			newfile_edit_menu();
	}
}

struct class_file {	
		char class_name[50];
		char students_name[100];
		int students_number;
};

newfile_edit() {
	
	char string[20000];
	
	char* filename = malloc(strlen(file_name) + strlen(ext) + 1);
	sprintf(filename, "Files/%s%s", file_name, ext);
	
	FILE *nf;
	
	nf = fopen(filename, "w");
	
	printf("============ FILE INFORMATION ============\n");
	printf(" %s\n", fgets(string, 20000, nf));
}

