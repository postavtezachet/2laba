#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include"functions.h"
int main() {
	system("chcp 1251>null");
	Game* game = nullptr;
	int a, number, c;
	do {
		int w = 0;
		printf("1:Create new stek\n");
		printf("2:Open txt file\n");
		printf("3:Open bin file\n");
		scanf("%d", &a);
		rewind(stdin);
		switch (a) {
		case 1:
			system("cls");
			push(&game);
			w = 1;
			break;
		case 2:
			system("cls");
			if (open_t(&game)) {
				w = 1;
			}
			break;
		case 3:
			system("cls");
			if (open_b(&game)) {
				w = 1;
			}
			break;
		default:
			printf("Error\n");
			break;
		}
		if (w) {
			break;
		}
	} while (1);
	do {
		printf("Input number of operation\n");
		printf("If you want exit, input 99\n");
		printf("1:Add\n");
		printf("2:Information output\n");
		printf("3:Delete by number\n");
		printf("4:Search\n");
		printf("5:Sorting\n");
		printf("6:Save in txt file\n");
		printf("7:Save in bin file\n");
		printf("8:Open txt file\n");
		printf("9:Open bin file\n");
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
			show(game);
			printf("Which number do you want to delete?\n");
			while (!scanf("%d", &number)) {
				rewind(stdin);
				printf("Error\n");
				printf("input correct number: ");
			}
			del(&game, number - 1);
			break;
		case 4:
			system("cls");
			search(game);
			break;
		case 5:
			system("cls");
			sorting(&game);
			break;
		case 6:
			system("cls");
			save_t(game);
			break;
		case 7:
			system("cls");
			save_b(game);
			break;
		case 8:

			system("cls");
			printf("Do you want to add or overwrite?(1/0)");
			while (1) {
				if (scanf("%d", &c)) {
					if (c == 1 || c == 0) {
						break;
					}
				}
				rewind(stdin);
				printf("Error\n");
				printf("input correct number: ");
			}
			if (c == 0) {
				game = nullptr;
			}
			open_t(&game);
			break;
		case 9:
			system("cls");
			printf("Do you want to add or overwrite?(1/0)");
			while (1) {
				if (scanf("%d", &c)) {
					if (c == 1 || c == 0) {
						break;
					}
				}
				rewind(stdin);
				printf("Error\n");
				printf("input correct number: ");
			}
			if (c == 0) {
				game = nullptr;
			}
			open_b(&game);
			break;
		case 99:
			break;
		default:
			
			printf("Wrong number\n");
			break;
		}

	} while (a != 99);
	return 0;
}