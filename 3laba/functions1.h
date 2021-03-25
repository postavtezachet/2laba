#include<stdio.h>
#include<Windows.h>
#include<io.h>
#include<string.h>

void output(char* name) {
	FILE* f;
	if (!(f = fopen(name, "r"))) {
		printf("Error");
		return;
	}
	char s;
	printf("File %s\n", name);
	while (!feof(f)) {
		fscanf(f, "%c", &s);
		if (feof(f)) {
			break;
		}
		printf("%c", s);
	}
	printf("\n");
	fclose(f);
}
void change(char* name) {
	FILE* f;
	int choice, i=0;
	char text[100];
	printf("What do you want to do\n");
	printf("1:Add information\n");
	printf("2:Rewrite\n");
	while (!scanf("%d", &choice)) {
		rewind(stdin);
		printf("Error\n");
		printf("input correct number ");
	}
	rewind(stdin);
	switch (choice) {
	case 1:
		if (!(f = fopen(name, "a"))) {
			printf("Error");
			return;
		}
		do {
			i = 0;
			int error = 0;
			printf("Input what do you want to add: ");
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
		fclose(f);
		break;
	case 2:
		if (!(f = fopen(name, "w+"))) {
			printf("Error");
			return;
		}
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
		fclose(f);
		break;
	default:
		return;
	}
	
	
}

void minimum(char* name) {
	FILE* f;
	int min,lon=0;
	char s;
	if (!(f = fopen(name, "r+"))) {
		printf("Error\n");
		return;
	}
	rewind(f);
	fpos_t i1, i2, imin;
	printf("File %s\n", name);
	while (!feof(f)) {
		fscanf(f, "%c", &s);
		if (feof(f)) {
			break;
		}
		printf("%c", s);
	}
	printf("\n");
	rewind(f);
	fgetpos(f, &imin);
	while (!feof(f)) {
		
		fscanf(f, "%c", &s);
		if (s == ' ') break;
		lon++;
	}
	min = lon;
	lon = 0;
	while (1) {
		if (feof(f)) {
			break;
		}
		while (!feof(f) && s == ' ') {
			lon = 0;
			fgetpos(f, &i1);
			fscanf(f, "%c", &s);
			if (s != ' ') break;
		}
		while (!feof(f) && s!=' ') {
			fgetpos(f, &i2);
			fscanf(f, "%c", &s);
			lon++;
		}
		if (lon < min) {
			imin = i1;
			min = lon;
		}
	}
	if (lon < min) {
		imin = i1;
		min = lon;
	}
	rewind(f);
	printf("min word\n");
	fsetpos(f, &imin);
	while (1) {
		fscanf(f, "%c", &s);
		if ((feof(f)) || s == ' ') break;
		printf("%c", s);
	}
	printf("\n");
	fclose(f);


}
void revers(char* name, fpos_t i1, fpos_t i2) {
	FILE* f;
	char s1, s2;
	if (!(f = fopen(name, "r+"))) {
		printf("Error\n");
		return;
	}
	while (i2 > i1) {
		fsetpos(f, &i1);
		fscanf(f, "%c", &s1);
		fsetpos(f, &i2);
		fscanf(f, "%c", &s2);
		fseek(f, -1, 1);
		fprintf(f, "%c", s1);
		fsetpos(f, &i1);
		fprintf(f, "%c", s2);
		i2--;
		i1++;
	}
	fclose(f);
}
void swap(char* name) {
	FILE* f;
	if (!(f = fopen(name, "r+"))) {
		printf("Error\n");
		return;
	}
	rewind(f);
	fpos_t ifirst1,ilast1, ifirst2,ilast2;
	char s;
	fscanf(f, "%c", &s);
	ifirst1 = 0;
	while (!feof(f) && s != ' ') {
		fgetpos(f, &ilast1);
		fscanf(f, "%c", &s);
	}
	ilast1--;
	fgetpos(f, &ifirst2);
	fscanf(f, "%c", &s);
	while (!feof(f) && s != ' ') {
		fgetpos(f, &ilast2);
		fscanf(f, "%c", &s);
	}
	ilast2--;
	revers(name, ifirst1, ilast2);
	revers(name, ifirst1, (ifirst1 + (ilast2 - ifirst2)));
	revers(name, (ilast2 - (ilast1 - ifirst1)), ilast2);

	fclose(f);
}