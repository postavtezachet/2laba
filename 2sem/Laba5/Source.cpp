#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include"functions.h"
int main() {
	system("chcp 1251>null");
	Game* h  = nullptr, *t = nullptr;
	int a, number, c;
	do {// when we start programm we can choose what to do
		int w = 0;
		printf("1:Create new stek\n");
		printf("2:Open txt file\n");
		printf("3:Open bin file\n");
		scanf("%d", &a);
		rewind(stdin);
		switch (a){
		case 1:// create
			system("cls");
			push(&h,&t);
			w = 1;
			break;
		case 2:// open txt file
			system("cls");
			if (open_t(&h,&t)) {
				w = 1;
			}
			break;
		case 3://open bin file
			system("cls");
			if (open_b(&h,&t)) {
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
	do {// main menu
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
			push(&h,&t);
			break;
		case 2:
			system("cls");
			show(h,t);
			break;
		case 3:
			system("cls");
			show(h,t);
			printf("Which number do you want to delete?\n");
			while (!scanf("%d", &number)) {
				rewind(stdin);
				printf("Error\n");
				printf("input correct number: ");
			}
			del(&h,&t, number -1);
			break;
		case 4:
			system("cls");
			search(h,t);
			break;
		case 5:
			system("cls");
			sorting(&h, &t);
			break;
		case 6:
			system("cls");
			save_t(h);
			break;
		case 7:
			system("cls");
			save_b(h);
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
				free_al(&h, &t);
			}
			open_t(&h,&t);
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
				free_al(&h, &t);
			}
			open_b(&h,&t);
			break;
		case 99:
			break;
		default:

			printf("Wrong number\n");
			break;
		}

	} while (a != 99);
	free_al(&h, &t);
	return 0;
}