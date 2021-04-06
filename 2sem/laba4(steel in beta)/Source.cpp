#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include"Functions.h"
int main() {
	system("chcp 1251>null");
	Game* game = nullptr;
	int a,number;
	push(&game);
	do {
		printf("Input number of operation\n");
		printf("If you want exit, input 99\n");
		printf("1:Add\n");
		printf("2:Information output\n");
		printf("3:Delete by number\n");
		printf("4:Search\n");
		printf("5:Sorting\n");
		scanf("%d", &a);
		rewind(stdin);
		switch (a) {
		case 1:
			system("cls");
			push(&game);
			break;
		case 2:
			system("cls");
			show(game);
			break;
		case 3:
			system("cls");
			printf("Which number do you want to delete?\n");
			while (!scanf("%d", &number)) {
				rewind(stdin);
				printf("Error\n");
				printf("input correct number: ");
			}
			del(&game,number-1);
			break;
		case 4:
			system("cls");
			search(game);
			break;
		case 5:
			system("cls");
			sorting(&game);
			break;
		case 99:
			break;
		deafult:
			printf("Wrong number\n");
		}

	} while (a != 99);

}