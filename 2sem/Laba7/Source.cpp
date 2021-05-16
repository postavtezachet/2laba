#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include"functions.h"
int main() {
	system("chcp 1251>null");
	Node* head = nullptr;
	int a, number, c;
	do {// main menu
		printf("Input number of operation\n");
		printf("If you want exit, input 99\n");
		printf("1:Add\n");
		printf("2:Output(recurs)\n");
		printf("3:Output\n");
		printf("4:Delete all\n");
		scanf("%d", &a);
		rewind(stdin);
		switch (a) {
		case 1:
			system("cls");
			push(&head);
			break;
		case 2:
			system("cls");
			recurs_output(head);
			break;
		case 3:
			system("cls");
			output(head);
			break;
		case 4:
			system("cls");
			free_all(head);
			head = nullptr;
			break;
		case 99:
			break;
		default:

			printf("Wrong number\n");
			break;
		}
		
	} while (a != 99);
	free_all(head);
	return 0;
}