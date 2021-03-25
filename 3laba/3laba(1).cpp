#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include<io.h>
#include"functions.h"
int main() {
	char name[20];
	int i=0,i1=0;
	char type[5] = ".txt";
	FILE* f;
	printf("Input name of file: ");
	gets_s(name, 20);
	while (name[i]) {
		i++;
	}
	while (type[i1]) {
		name[i] = type[i1];
		i++;
		i1++;
	}
	name[i] = '\0';
	if (!(f = fopen(name, "w+"))) {
		printf("Error\n");
		return 0;
	}
	char text[100];
	do {
		i = 0;
		int error = 0;
		printf("Input words: ");
		gets_s(text, 100);
		while (text[i]) {
			if (text[i] >= '0' && text[i] <= '9') {
				printf("Error\n");
				error = 1;
				break;
			}
			i++;
		}
		if (error == 0) {
			break;
		}
	} while (1);
	fprintf(f, "%s", text);
	rewind(f);
	int choice;
	do {
		printf("Input number of operation\n");
		printf("If you want exit, input 99\n");
		printf("1:Information output\n");
		printf("2:Change information\n");
		printf("3:Find min word\n");
		printf("4:Swap first two words\n");
		while (!scanf("%d", &choice)) {
			rewind(stdin);
			printf("Error\n");
			printf("input correct number ");
		}
		switch (choice) {
		case 1:
			system("cls");
			output(name);
			break;
		case 2:
			system("cls");
			change(name);
			break;
		case 3:
			system("cls");
			minimum(name);
			break;
		case 4:
			system("cls");
			swap(name);
			break;
		case 99:
			break;
		default:
			printf("wrong number\n");
			break;
		}

	} while (choice != 99);
	fclose(f);
	return 0;

}