#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include<io.h>
#include<conio.h>
#include"functions2.h"

int main() {
	FILE* f;
	int n;
	int* mas;
	char name[20];
	printf("Input name of file\n");
	gets_s(name, 20);
	printf("Input amount of number\n");
	scanf("%d", &n);
	mas = (int*)calloc(n, sizeof(int));
	printf("Input %d numbers\n", n);
	for (int i = 0; i < n; i++) {
		while (!scanf("%d", &mas[i])) {
			rewind(stdin);
			printf("input correct number\n");
		}
	}
	
	rewind(stdin);
	if (!(f = fopen(name, "w+b"))) {
		printf("Error");
		return 0;

	}
	fwrite(mas, sizeof(int),n, f);
	int a;
	do {
		printf("Input number of operation\n");
		printf("If you want exit, input 99\n");
		printf("1:Information output\n");
		printf("2:Output number of negative numbers\n");
		printf("3:Change negative numbers to max\n");
		while (!scanf("%d", &a)) {
			rewind(stdin);
			printf("input correct number\n");
		}
		rewind(stdin);
		switch (a) {
		case 1:
			system("cls");
			output(f);
			break;
		case 2:
			system("cls");
			negative_numbers(f);
			break;
		case 3:
		
			change(f);
			break;
		case 99:
			break;
		default:
			printf("wrong number\n");
		}
	} while (a != 99);



	fclose(f);
	return 0;
}