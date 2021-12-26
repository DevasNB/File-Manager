#include <stdio.h>
#include <locale.h>
#include <conio.h>
/*
* Projeto Final
* Trabalho realizado por: João Devesa
*/
main() {
	
	setlocale(LC_ALL, "");
	
	int menu;
	
	system("cls");
	
	//START
	printf("\n\n\n\n");
	printf("\t\t ********    ********    **    **    ********    ********    **          **    **\n");
	printf("\t\t ********    ********    **    **    ********    ********    **          **    **\n");
	printf("\t\t **          **          **    **    **    **    **    **    **           **  **\n");
	printf("\t\t **          **          **    **    **    **    **    **    **           **  **\n");
	printf("\t\t ********    **          ********    **    **    **    **    **            ****\n");
	printf("\t\t ********    **          ********    **    **    **    **    **            ****\n");
	printf("\t\t       **    **          **    **    **    **    **    **    **           **  **\n");
	printf("\t\t       **    **          **    **    **    **    **    **    **           **  **\n");
	printf("\t\t ********    ********    **    **    ********    ********    ********    **    **\n");
	printf("\t\t ********    ********    **    **    ********    ********    ********    **    **\n");
	
	printf("\n\n\t\t\t\t\t     CLICK ENTER TO CONTINUE\n\n\n\n");
	
	system("pause");
	sleep(1);
	system("cls");
	
	//MENU
	printf(" ============= MENU =============\n");
	printf(" | [1] - Search Class           |\n");
	printf(" | [2] - Create Class           |\n");
	printf(" | [3] - Edit Class             |\n");
	printf(" | [4] - Delete Class           |\n");
	printf(" |                              |\n");
	printf(" | [0] - Information            |\n");
	printf(" ================================\n");
	
	printf(" R: ");
	scanf("%d", &menu);
	
	switch(menu) {
		case 1:;
			searchfile();
			break;
		
		case 2:
			newfile();
			break;
			
		case 3:
			editfile();
			break;
		
		case 4:
			deletefile();
			break;
			
		case 0:
			system("cls");
			printf(" ==================================== INFORMATION ========================================\n");
			printf(" |\t\t\t   This program was created by João Devesa                       |\n");
			printf(" | Their role is to create files/lists of each class at the institute/school they are in |\n");
			printf(" =========================================================================================\n\n");
			
			system("pause");
			main();
			break;
			
		default: 
			printf("Choose a MENU option!");
			sleep(1);
			system("cls");
			main();
	}
}
