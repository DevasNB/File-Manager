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
	printf("\t\t ********    ********    **    **    ********    ********    **            **    **\n");
	printf("\t\t ********    ********    **    **    ********    ********    **            **    **\n");
	printf("\t\t **          **          **    **    **    **    **    **    **             **  **\n");
	printf("\t\t **          **          **    **    **    **    **    **    **             **  **\n");
	printf("\t\t ********    **          ********    **    **    **    **    **              ****\n");
	printf("\t\t ********    **          ********    **    **    **    **    **              ****\n");
	printf("\t\t       **    **          **    **    **    **    **    **    **             **  **\n");
	printf("\t\t       **    **          **    **    **    **    **    **    **             **  **\n");
	printf("\t\t ********    ********    **    **    ********    ********    ********      **    **\n");
	printf("\t\t ********    ********    **    **    ********    ********    ********      **    **\n");
	
	printf("\n\n\t\t\t\t\t     CLICK ENTER TO CONTINUE\n\n\n\n");
	
	system("pause");
	sleep(1);
	system("cls");
	
	//MENU
	printf(" ============= MENU =============\n");
	printf(" | [1] - Search Class           |\n");
	printf(" | [2] - List Class             |\n");
	printf(" | [3] - Create Class           |\n");
	printf(" | [4] - Update Class           |\n");
	printf(" | [5] - Delete Class           |\n");
	printf(" |                              |\n");
	printf(" | [0] - Information            |\n");
	printf(" ================================\n");
	
	printf(" R: ");
	fflush(stdin);
	scanf("%d", &menu);
	
	switch(menu) {
		case 1:
			searchfile();
			break;
		
		case 2:
			main();
			break;
		case 3:
			newfile();
			break;
			
		case 4:
			updatefile();
			break;
		
		case 5:
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
