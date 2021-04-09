#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include<conio.h>
#include"Functions.cpp"


void gets_max(char* name, int n) {
	int i = 0;
	char c;
	do {
		rewind(stdin);
		i = 0;
		c = ' ';
		int error = 0;
		while (c != '\n') {
			scanf("%c", &c);

			if (c != '\n') {
				name[i] = c;
				i++;
			}
			if (i > n) {
				printf("error\n");
				error = 1;
				break;
			}

		}
		if (error == 0) {
			break;
		}
	} while (1);
	name[i] = '\0';
}
void push(Game** s) {
	Game* sl = *s;
	do {
		if (!(*s = (Game*)calloc(1, sizeof(Game)))) {
			printf("Error");
			return;
		}
		printf("Input game price: ");
		while (!scanf("%d", &(*s)->price)) {
			rewind(stdin);
			printf("Error\n");
			printf("input correct price: ");
		}
		rewind(stdin);
		printf("Input game name: ");
		(*s)->name = (char*)calloc(30, sizeof(char));
		gets_max((*s)->name, 30);
		printf("What do you want to add\n");
		printf("1:Genre\n");
		printf("2:Max player\n");
		while (1) {
			rewind(stdin);
			scanf("%d", &(*s)->r);
			if ((*s)->r == 1) {
				rewind(stdin);
				printf("Input game genre: ");
				gets_max((*s)->un.genre, 20);
				break;
			}
			else if ((*s)->r == 2) {
				printf("Input max number of players: ");
				while (!scanf("%d", &(*s)->un.max_players)) {
					rewind(stdin);
					printf("Error\n");
					printf("input correct number: ");
				}
				break;
			}
			else {
				printf("Wrong number ");
			}
		}
		(*s)->point = sl;
		sl = *s;
		printf("do you want to continue?(y/n)\n");
		rewind(stdin);
	} while (getch() == 'y');
}

void show(Game* s) {
	if (!s) {
		printf("no information\n");
		return;
	}
	int i = 0;
	printf("| Game № | Price |             Name             |        Genre        |  Max players  |\n");
	printf("---------------------------------------------------------------------------------------\n");
	while (1) {
		printf("|  %6d", i + 1);
		printf("|%7d|%30s", (s)->price, (s)->name);
		if ((s)->r == 2) {
			printf("|\t\t      |%15d|\n", (s)->un.max_players);
		}
		else if ((s)->r == 1) {
			printf("|%21s|\t\t      |\n", (s)->un.genre);
		}
		printf("---------------------------------------------------------------------------------------\n");
		i++;
		if (!(s->point)) {
			return;
		}
		s = s->point;


	}
}

void del(Game** s, int n) {
	Game* ptr, *buff;
	ptr = *s;
	buff = (*s)->point;

	int i = 1;
	while (1) {
		if (n == 0) {
			(*s) = (*s)->point;
			free(ptr->name);
			free(ptr);
			return;
		}
		else if (n == i) {
			if (!((buff)->point)) {
				(ptr)->point = buff->point;
				free(buff->name);
				free(buff);
				return;
			}


			(ptr)->point = buff->point;
			free(buff->name);
			free(buff);
			return;
		}
		ptr = ptr->point;
		buff = (buff)->point;
		i++;
	}
}

void menu() {
	printf("1:Price\n");
	printf("2:Name\n");
	printf("3:Genre\n");
	printf("4:Max_players\n");
}
void one_output(Game* s) {

	printf("Price: %d\n", (s)->price);
	printf("Name: ");
	puts((s)->name);
	if ((s)->r == 1) {
		printf("Genre: ");
		puts((s)->un.genre);
		printf("\n");
	}
	else {
		printf("Max players: %d\n\n", (s)->un.max_players);
	}
}
void search(Game* s) {
	system("cls");
	menu();
	int a;
	char se[30];
	int j;
	while (!scanf("%d", &a)) {
		rewind(stdin);
		printf("Error\n");
		printf("input correct number: ");

	}
	rewind(stdin);
	switch (a) {
	case 1:
		printf("input search query: ");

		while (!scanf("%d", &j)) {
			rewind(stdin);
			printf("Error\n");
			printf("input correct query: ");

		}
		for (int i = 0; s; s = s->point) {
			if (j == (s)->price) {
				one_output(s);
			}
		}
		break;
	case 2:
		printf("input search query: ");

		gets_max(se, 30);
		for (int i = 0; s; s = s->point) {
			if (!(strcmp((s)->name, se))) {
				one_output(s);
			}
		}
		break;
	case 3:
		printf("input search query: ");

		gets_max(se, 30);
		for (int i = 0; s; s = s->point) {
			if ((s)->r == 1) {
				if (!(strcmp((s)->un.genre, se))) {
					one_output(s);
				}
			}
		}
		break;
	case 4:
		printf("input search query: ");

		while (!scanf("%d", &j)) {
			rewind(stdin);
			printf("Error\n");
			printf("input correct query: ");

		}
		for (int i = 0; s; s = s->point) {
			if ((s)->r == 2) {
				if (j == (s)->un.max_players) {
					one_output(s);
				}
			}
		}
		break;
	default:
		printf("wrong number");
		break;
	}
}

int tolowersorting(char* s1, char* s2) {
	char f[50];
	char f1[50];
	int i = 0, j = 0;
	while (s1[i]) {
		f[j] = tolower(s1[i]);
		i++;
		j++;
	}
	i = 0;
	j = 0;
	while (s2[i]) {
		f1[j] = tolower(s2[i]);
		i++;
		j++;
	}
	return strcmp(f, f1);
}

void sorting(Game** s) {
	Game* s1, * s2, * s3 = 0, * s4 = nullptr, * s5, * ss;
	ss = (Game*)calloc(1, sizeof(Game));
	ss->point = *s;
	printf("What parameter do you want to sorting?\n");

	menu();
	int a;

	while (!scanf("%d", &a)) {
		rewind(stdin);
		printf("Error\n");
		printf("input correct number: ");

	}
	switch (a) {
	case 1:
		for (; ss->point->point;) {
			s1 = ss->point;
			for (s2 = ss->point, s5 = ss; s2; s2 = s2->point, s5 = s5->point) {
				if ((s1)->price < (s2)->price) {
					s1 = s2;
					s3 = s5;
				}

			}
			if (s1 != ss->point) {
				s3->point = s1->point;
				s1->point = ss->point;
				ss->point = s1;
			}
			if (!s4)s2 = ss;
			ss = ss->point;
			if (!s4) {
				free(s4);
				*s = s4 = s1;
			}
		}
		break;
	case 2:
		for (; ss->point->point;) {
			s1 = ss->point;
			for (s2 = ss->point, s5 = ss; s2; s2 = s2->point, s5 = s5->point) {
				if (tolowersorting(s1->name, s2->name) > 0) {
					s1 = s2;
					s3 = s5;
				}

			}
			if (s1 != ss->point) {
				s3->point = s1->point;
				s1->point = ss->point;
				ss->point = s1;
			}
			if (!s4)s2 = ss;
			ss = ss->point;
			if (!s4) {
				free(s4);
				*s = s4 = s1;
			}
		}
		break;
	case 3:
		for (; ss->point->point;) {
			s1 = ss->point;
			for (s2 = ss->point, s5 = ss; s2; s2 = s2->point, s5 = s5->point) {
				if (tolowersorting((s1)->un.genre, (s2)->un.genre) > 0) {
					s1 = s2;
					s3 = s5;
				}

			}
			if (s1 != ss->point) {
				s3->point = s1->point;
				s1->point = ss->point;
				ss->point = s1;
			}
			if (!s4)s2 = ss;
			ss = ss->point;
			if (!s4) {
				free(s4);
				*s = s4 = s1;
			}

		}
		break;
	case 4:
		for (; ss->point->point;) {

			s1 = ss->point;
			
			for (s2 = ss->point, s5 = ss; s2; s2 = s2->point, s5 = s5->point) {
				
				if ((s1)->un.max_players > (s2)->un.max_players) {
					s1 = s2;
					s3 = s5;
				}

			}
			if (s1 != ss->point) {
				s3->point = s1->point;
				s1->point = ss->point;
				ss->point = s1;
			}
			if (!s4)s2 = ss;
			ss = ss->point;
			if (!s4) {
				free(s4);
				*s = s4 = s1;

			}
		}
		break;
	default:
		printf("wrong number\n");
		break;
	}


}		
int open_t(Game** s) {
	FILE* f;
	Game* sl = *s;
	int l = 0;
	char chislo[100];
	char chislo_m[100];
	char genre[100];
	char name_c[100];
	char name[20];
	char c = ' ',file;
	int i = 0, i1 = 0;
	if (!(f = fopen("Files.txt", "r"))) {
		printf("Error\n");
		return 0;
	}
	printf("Files\n");
	rewind(f);
	while (1) {
		fscanf(f, "%c", &file);
		
		if (feof(f)) {
			break;
		}
		printf("%c", file);
	}
	fclose(f);
	
	printf("\nInput name of file: ");
	gets_max(name, 20);
	char type[5] = ".txt";
	i = 0;
	while (name[i]) {
		i++;
	}
	while (type[i1]) {
		name[i] = type[i1];
		i++;
		i1++;
	}
	name[i] = '\0';
	if (!(f = fopen(name, "r"))) {
		printf("Error\n");
		return 0;
	}
	i = 0;
	rewind(f);
	do {
		i = 0;
		c = ' ';
		fseek(f, -1, 1);
		if (!(*s = (Game*)calloc(1, sizeof(Game)))) {
			printf("Error");
			return 0;
		}
		while (c != '\n') {
			chislo[i] = c;
			fscanf(f, "%c", &c);
			i++;
		}
		chislo[i] = '\0';
		i = 0;
		(*s)->price = atoi(chislo);
		if (!(*s)->price) {
			printf("Error\n");
			return 0;
		}
		rewind(stdin);
		(*s)->name = (char*)calloc(30, sizeof(char));
		fscanf(f, "%c", &c);
		while (c != '\n') {
			name_c[i] = c;
			fscanf(f, "%c", &c);
			i++;
		}
		name_c[i] = '\0';
		strcpy((*s)->name, name_c);
		if (!(*s)->name) {
			printf("Error\n");
			return 0;
		}
		fscanf(f, "%c", &c);
		(*s)->r = (c - '0');
		if (!(*s)->r) {
			printf("Error\n");
			return 0;
		}
		i = 0;
		fscanf(f, "%c", &c);
		fscanf(f, "%c", &c);
		if ((*s)->r == 1) {
			while (c != '\n' ) {
				genre[i] = c;
				i++;
				fscanf(f, "%c", &c);
				if (feof(f)) {
					break;
				}
			}

			genre[i] = '\0';
			strcpy((*s)->un.genre, genre);
		}
		else {
			while (c != '\n') {
				chislo_m[i] = c;
				i++;
				fscanf(f, "%c", &c);
				if (feof(f)) {
					break;
				}
			}

			chislo_m[i] = '\0';
			(*s)->un.max_players = atoi(chislo_m);
		}
		
		(*s)->point = sl;
		sl = *s;
		fscanf(f, "%c", &c);
		if (feof(f)) {
			break;
		}
		rewind(stdin);
	} while (1);
	fclose(f);
	return 1;
}

void save_t(Game* s) {
	FILE* f;
	int i = 0, i1 = 0;
	char c;
	char name[20];
	char name_w_t[20];
	printf("\nInput name of file: ");
	gets_max(name, 20);
	char type[5] = ".txt";
	i = 0;
	while (name[i]) {
		name_w_t[i] = name[i];
		i++;
	}
	name_w_t[i] = '\0';
	while (type[i1]) {
		name[i] = type[i1];
		i++;
		i1++;
	}
	name[i] = '\0';
	if (!(f = fopen(name, "w+"))) {
		printf("Error\n");
		return;
	}
	while (1) {
		fprintf(f, "%d", (s)->price);
		fprintf(f, "%c", '\n');
		fprintf(f, "%s", (s)->name);
		fprintf(f, "%c", '\n');
		if ((s)->r == 1) {
			fprintf(f, "%d", (s)->r);
			fprintf(f, "%c", '\n');
			fprintf(f, "%s\n", (s)->un.genre);
		}
		else {
			fprintf(f, "%d", (s)->r);
			fprintf(f, "%c", '\n');
			fprintf(f, "%d\n", (s)->un.max_players);
		}
		if (!((s)->point)) {
			break;
		}
		s = (s)->point;
		
	}
	fclose(f);
	if (!(f = fopen("Files.txt", "r+"))) {
		printf("Error\n");
		return;
	}
	rewind(f);
	char* copy;
	int trig=0;
	while (!feof(f)) {
		copy = (char*)calloc(20, sizeof(char));
		i = 0;
		c = ' ';
		while (1) {
			fscanf(f, "%c", &c);
			if (c == '\n'|| feof(f)) {
				break;
			}
			copy[i] = c;
			i++;
		}
		copy[i] = '\0';
		if (!(strcmp(copy, name_w_t))) {
			trig = 1;
			break;
		}
		if (!(strcmp("Files", name_w_t))) {
			trig = 1;
			break;
		}
	}
	if (!trig) {
		fprintf(f, "\n%s", name_w_t);
	}
	fclose(f);
}
int open_b(Game** s) {
	FILE* f;
	Game* sl = *s;
	char file, c;
	int i = 0;
	char name[20];
	char name_f[100], genre_f[100];

	if (!(f = fopen("Files(b).txt", "r"))) {
		printf("Error");
		return 0;
	}
	printf("Files\n");
	rewind(f);
	while (1) {
		fscanf(f, "%c", &file);

		if (feof(f)) {
			break;
		}
		printf("%c", file);
	}
	fclose(f);

	printf("\nInput name of file: ");
	gets_max(name, 20);
	if (!(f = fopen(name, "r+b"))) {
		printf("Error\n");
		return 0;
	}
	i = 0;
	rewind(f);
	do {
		c = ' ';
		i = 0;
		fseek(f, -4, 1);
		if (!(*s = (Game*)calloc(1, sizeof(Game)))) {
			printf("Error");
			return 0;
		}
		fread(&(*s)->price, sizeof(int), 1, f);
		while (1) {
			fread(&name_f[i], sizeof(char), 1, f);
			if (name_f[i] == '\0') {
				break;
			}
			i++;
		}
		(*s)->name = (char*)calloc(30, sizeof(char));
		strcpy(((*s)->name), name_f);
		i = 0;
		fread(&(*s)->r, sizeof(int), 1, f);
		if ((*s)->r == 1) {
			while (1) {
				fread(&genre_f[i], sizeof(char), 1, f);
				if (genre_f[i] == '\0') {
					break;
				}
				i++;
			}

			strcpy((*s)->un.genre, genre_f);
		}
		else {
			fread(&(*s)->un.max_players, sizeof(int), 1, f);
		}
		(*s)->point = sl;
		sl = *s;
		fread(&i, sizeof(int), 1, f);
		if (feof(f)) {
			break;
		}
		rewind(stdin);
	} while (1);
	fclose(f);
	return 1;

}

void save_b(Game* s) {
	FILE* f;
	int i=0;
	char c, name[20], name_w_t[20];
	char name_f[100];
	char genre_f[100];
	printf("\nInput name of file: ");
	gets_max(name, 20);
	if (!(f = fopen(name, "w+b"))) {
		printf("Error");
		return;
	}
	
	i = 0;
	while (name[i]) {
		name_w_t[i] = name[i];
		i++;
	}
	
	name_w_t[i] = '\0';
	i = 0;
	while(1) {
		i = 0;
		fwrite(&(s->price), sizeof(int), 1, f);
		strcpy(name_f, s->name);
		while (name_f[i]) {
			fwrite(&name_f[i], sizeof(char), 1, f);
			i++;
		}
		fwrite(&name_f[i], sizeof(char), 1, f);
		i = 0;
		fwrite(&(s->r), sizeof(int), 1, f);
		if (s->r == 1) {
			strcpy(genre_f, s->un.genre);
			while (genre_f[i]) {
				fwrite(&genre_f[i], sizeof(char), 1, f);
				i++;
			}
			fwrite(&genre_f[i], sizeof(char), 1, f);

		}
		else {
			fwrite(&(s->un.max_players), sizeof(int), 1, f);
		}
		if (!((s)->point)) {
			break;
		}
		s = (s)->point;

	}
	fclose(f);
	if (!(f = fopen("Files(b).txt", "r+"))) {
		printf("Error\n");
		return;
	}
	rewind(f);
	char* copy;
	int trig = 0;
	while (!feof(f)) {
		copy = (char*)calloc(20, sizeof(char));
		i = 0;
		c = ' ';
		while (1) {
			fscanf(f, "%c", &c);
			if (c == '\n' || feof(f)) {
				break;
			}
			copy[i] = c;
			i++;
		}
		copy[i] = '\0';
		if (!(strcmp(copy, name_w_t))) {
			trig = 1;
			break;
		}
		if (!(strcmp("Files", name_w_t))) {
			trig = 1;
			break;
		}
	}
	if (!trig) {
		fprintf(f, "\n%s", name_w_t);
	}
	fclose(f);
}
