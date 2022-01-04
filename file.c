#include <stdio.h>
#include <locale.h>
/*
* Projeto Final
* Trabalho realizado por: João Devesa
*/
char file_name[50];
char* ext = ".dat";

int input_number;

struct class_file {	
		char student_name[100];
		int student_number;
};


//SEARCH FILE
searchfile() {
	
	system("cls");
	printf(" ========== SEARCH FILE ==========\n");
	printf(" | FILE NAME: ");
	fflush(stdin);
	gets(file_name);
	printf(" =================================\n");
	
	system("cls");
	
}

//SEARCH FILE MENU
searchfile_menu() {
	
	int menu;
	
	system("cls");
	
	//MENU
	printf(" ======== SEARCH FILE MENU ========\n");
	printf(" | [1] - Back to main             |\n");
	printf(" | [2] - Read File                |\n");
	printf(" | [3] - Edit File                |\n");
	printf(" ==================================\n");
	
	printf(" R: ");
	scanf("%d", &menu);
	
	switch(menu) {
		case 1:
			main();
			break;
		
		case 2:
			readfile();
			break;
		
		case 3:
			editfile();
			break;
		
		default:
			printf("Choose a option in the menu");
			system("pause");
			
			searchfile_menu();
	}
}

//READ FILE
readfile() {
	
	char string[20000];
	
	char* filename = malloc(strlen(file_name) + strlen(ext) + 1);
	sprintf(filename, "Files/%s%s", file_name, ext);
	
	FILE *nf;
	
	nf = fopen(filename, "r");
	
	system("cls");
	printf("============ FILE INFORMATION ============\n");
	printf(" %s\n", fgets(string, 20000, nf));
}

//CREATE FILE
newfile() {
		
	setlocale(LC_ALL, "");
	
	//FILE NAME AND EXTENSION
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
	nf = fopen(filename, "wb");
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

newfile_edit() {
	
	struct class_file cf[input_number];
	
	int i;
	
	char* filename = malloc(strlen(file_name) + strlen(ext) + 1);
	sprintf(filename, "Files/%s%s", file_name, ext);
	
	FILE *nf;
	
	nf = fopen(filename, "wb");
	
	fprintf(filename, "LIST: \n\n    Name:\t Number:\n\n");
	
	system("cls");
	printf("============ WRITE THE CLASS LIST ============\n");
	for(i = 0; i <= input_number; i++) {
		printf("| Student name: ");
		gets(cf[i].student_name[i]);
		
		printf("| Student number: ");
		scanf("%d", &cf[i].student_number);
		
		fprintf(filename, "[%d]: %s\t %d \n\n", i, cf[i].student_name[i], cf[i].student_number);
	}
}

editfile() {
	
	main();
}

deletefile() {
	
	searchfile();
	
	char* filename = malloc(strlen(file_name) + strlen(ext) + 1);
	sprintf(filename, "Files/%s%s", file_name, ext);
	
	system("cls");
	if(remove(filename) == 0) {
		printf("File deleted successfully");
	}
	else {
		printf("Unable to delete de file");
	}
}

