#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include<io.h>
#include<conio.h>

void output(FILE* f) {
	int j;
	rewind(f);
	while (2) {
		fread(&j, sizeof(int), 1, f);
		if (feof(f)) break;
		printf("%d ", j);
	}
	printf("\n");
}

void negative_numbers(FILE* f) {
	int i = 0, j;
	rewind(f);
	while (2) {
		fread(&j, sizeof(int), 1, f);
		if (feof(f)) break;
		if (j < 0) {
			i++;
		}
	}
	printf("Number of negative numbers = %d\n", i);
}

void change(FILE* f) {
	int max = 0, j, trigger = 0;
	rewind(f);
	while (2) {
		fread(&j, sizeof(int), 1, f);
		if (feof(f)) break;
		if (j > 0) {
			max = j;
			trigger = 1;
			break;
		}
	}
	if (trigger = 0) {
		printf("There are not positive numbers in this file\n");
		return;
	}
	rewind(f);
	while (2) {
		fread(&j, sizeof(int), 1, f);
		if (feof(f)) break;
		if (j > max) {
			max = j;
		}
	}
	rewind(f);
	while (2) {
		fread(&j, sizeof(int), 1, f);
		if (feof(f)) break;
		if (j < 0) {
			fseek(f, -4, 1);
			fwrite(&max, sizeof(int), 1, f);
			fseek(f, 4, 1);
		}
	}
}