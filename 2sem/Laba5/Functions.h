#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include<conio.h>
#include"Struct.cpp"

void free_al(Game** h, Game** t) {  // memory deletion
	Game* s;
	do {
		s = *h;
		(*h) = (*h)->pr;
		free(s->name);
		free(s);
		if (!((*h)->pr)) {
			s = *h;
			free(s->name);
			free(s);
			(*h) = (*t) = nullptr;
			return;
		}
		


	} while (*h);
}

void gets_max(char* name, int n) { // I hate gets and i created this function
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
			if (i > n) { // if input more than n
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
void push(Game** h,Game** t) { // add new struct 
	Game *s;
	int c;
	char* chislo;
	int i = 0, trig = 0;
	chislo = (char*)calloc(11, sizeof(char));

	do {
		if (!(s = (Game*)calloc(1, sizeof(Game)))) {
			printf("Error");
			return;
		}

		while (1) {
			i = 0;
			trig = 0;
			printf("Input game price: ");
			gets_max(chislo, 10);
			while (chislo[i]) {
				if (chislo[i] >= '0' && chislo[i] <= '9') {
					i++;
				}
				else {
					trig = 1;
					break;
				}
				if (i == 10) {
					trig = 1;
					break;
				}
			}
			if (!trig) {
				trig = 0;
				(s)->price = atoi(chislo);
				break;
			}
		}

		i = 0;
		rewind(stdin);
		printf("Input game name: ");
		(s)->name = (char*)calloc(30, sizeof(char));
		gets_max((s)->name, 30);
		printf("What do you want to add\n");
		printf("1:Genre\n");
		printf("2:Max player\n");
		while (1) {
			rewind(stdin);
			while (1) {
				i = 0;
				trig = 0;
				gets_max(chislo, 10);
				while (chislo[i]) {
					if (chislo[i] >= '0' && chislo[i] <= '9') {
						i++;
					}
					else {
						trig = 1;
						break;
					}
					if (i == 10) {
						trig = 1;
						break;
					}
				}
				if (!trig) {
					trig = 0;
					(s)->r = atoi(chislo);
					break;
				}
			}
			if ((s)->r == 1) {
				rewind(stdin);
				printf("Input game genre: ");
				gets_max((s)->un.genre, 20);
				break;
			}
			else if ((s)->r == 2) {

				while (1) {
					i = 0;
					trig = 0;
					printf("Input max number of players: ");
					gets_max(chislo, 10);
					while (chislo[i]) {
						if (chislo[i] >= '0' && chislo[i] <= '9') {
							i++;
						}
						else {
							trig = 1;
							break;
						}
						if (i == 10) {
							trig = 1;
							break;
						}
					}
					if (!trig) {
						trig = 0;
						(s)->un.max_players = atoi(chislo);
						break;
					}
				}
				break;
			}
			else {
				printf("Wrong number ");
			}
		}
		if (!(*t) || !(*h)) {
			*t = s;
			*h = s;
		}
		else {
			(*t)->pr = s;
			*t = s;
		}
		printf("do you want to continue?(1/0)\n");
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
		rewind(stdin);

	} while (c == 1);
}

void show(Game* h, Game* t) { // output all structs
	if (!h) {
		printf("no information\n");
		return;
	}
	int i = 0;
	printf("| Game ¹ |  Price  |             Name             |        Genre        |  Max players  |\n");
	printf("-----------------------------------------------------------------------------------------\n");
	do {
		printf("|  %6d", i + 1);
		printf("|%9d|%30s", (h)->price, (h)->name);
		if ((h)->r == 2) {
			printf("|\t\t        |%15d|\n", (h)->un.max_players);
		}
		else if ((h)->r == 1) {
			printf("|%21s|\t\t|\n", (h)->un.genre);
		}
		printf("-----------------------------------------------------------------------------------------\n");
		i++;
		if (!(h->pr)) {
			return;
		}
		h = h->pr;


	} while (h);
}

void del(Game** h, Game** t, int n) { // delete struct number n
	Game* ptr, * buff;
	ptr = *h;
	buff = (*h)->pr;

	int i = 1;
	while (1) {
		if (n == 0) {
			(*h) = (*h)->pr;
			free(ptr->name);
			free(ptr);
			return;
		}
		else if (n == i) {
			(ptr)->pr = buff->pr;
			free(buff->name);
			free(buff);
			return;
		}
		if (!buff->pr) {
			printf("There is no such number\n");
			return;
		}
		ptr = ptr->pr;
		buff = (buff)->pr;
		i++;
	}
}

void menu() {
	printf("1:Price\n");
	printf("2:Name\n");
	printf("3:Genre\n");
	printf("4:Max_players\n");
}
void one_output(Game* s) { // output one struct

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
void search(Game* h, Game* t) {
	system("cls");
	menu();
	int a;
	char se[30];

	int j, r = 0;
	while (!scanf("%d", &a)) {
		rewind(stdin);
		printf("Error\n");
		printf("input correct number: ");

	}
	rewind(stdin);
	switch (a) {
	case 1: // search price
		printf("input search query: ");

		while (!scanf("%d", &j)) {
			rewind(stdin);
			printf("Error\n");
			printf("input correct query: ");

		}
		for (int i = 0; h; h = h->pr) {
			if (j == (h)->price) {
				r = 1;
				one_output(h);
			}
		}
		break;
	case 2: //search name
		printf("input search query: ");

		gets_max(se, 30);
		for (int i = 0; h; h = h->pr) {
			if (!(strcmp((h)->name, se))) {
				r = 1;
				one_output(h);
			}
		}
		break;
	case 3: // search gener
		printf("input search query: ");

		gets_max(se, 30);
		for (int i = 0; h; h = h->pr) {
			if ((h)->r == 1) {
				if (!(strcmp((h)->un.genre, se))) {
					r = 1;
					one_output(h);
				}
			}
		}
		break;
	case 4: // search max players
		printf("input search query: ");

		while (!scanf("%d", &j)) {
			rewind(stdin);
			printf("Error\n");
			printf("input correct query: ");

		}
		for (int i = 0; h; h = h->pr) {
			if ((h)->r == 2) {
				if (j == (h)->un.max_players) {
					r = 1;
					one_output(h);
				}
			}
		}
		break;
	default:
		printf("wrong number\n");
		return;

	}
	if (!r) {
		printf("No information\n\n");
	}

}

int tolowersorting(char* s1, char* s2) { // 
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

void sorting(Game** h, Game** t) { // sorting
	Game* s1, * s2, * s3 = 0, * s4 = nullptr, * s5, * ss; 
	Game* find;
	ss = (Game*)calloc(1, sizeof(Game));
	ss->pr = *h;
	find = *h;
	printf("What parameter do you want to sorting?\n");

	menu();
	int a;

	while (!scanf("%d", &a)) {
		rewind(stdin);
		printf("Error\n");
		printf("input correct number: ");

	}
	switch (a) {
	case 1:// price
		for (; ss->pr->pr;) {
			s1 = ss->pr;
			for (s2 = ss->pr, s5 = ss; s2; s2 = s2->pr, s5 = s5->pr) {
				if ((s1)->price < (s2)->price) {
					s1 = s2;
					s3 = s5;
				}

			}
			if (s1 != ss->pr) {
				s3->pr = s1->pr;
				s1->pr = ss->pr;
				ss->pr = s1;
			}
			ss = ss->pr;
			if (!s4) {
				free(s4);
				*h = s4 = s1;
			}
		}
		*t = ss->pr;
		break;
	case 2: // name
		for (; ss->pr->pr;) {
			s1 = ss->pr;
			for (s2 = ss->pr, s5 = ss; s2; s2 = s2->pr, s5 = s5->pr) {
				if (tolowersorting(s1->name, s2->name) > 0) {
					s1 = s2;
					s3 = s5;
				}

			}
			if (s1 != ss->pr) {
				s3->pr = s1->pr;
				s1->pr = ss->pr;
				ss->pr = s1;
			}

			ss = ss->pr;
			if (!s4) {
				free(s4);
				*h = s4 = s1;
			}
		}
		*t = ss->pr;
		break;
	case 3: //genre
		if (find->r != 1) {
			s3 = find;
			find = find->pr;
			for (s3; find->pr; find = find->pr, s3 = s3->pr) {
				if (find->r == 1) {
					s3->pr = find->pr;
					find->pr = *h;
					*h = find;
					ss->pr = *h;
					break;
				}
			}
		}
		s3 = 0;
		for (; ss->pr->pr;) {
			s1 = ss->pr;
			for (s2 = s1->pr, s5 = s1; s2; s2 = s2->pr, s5 = s5->pr) {
				if (s2->r == 1 && s1->r == 1) {
					if (tolowersorting((s1)->un.genre, (s2)->un.genre) > 0) {
						s1 = s2;
						s3 = s5;
					}
				}

			}
			if (s1 != ss->pr) {
				s3->pr = s1->pr;
				s1->pr = ss->pr;
				ss->pr = s1;
			}

			ss = ss->pr;
			if (!s4) {
				free(s4);
				*h = s4 = s1;
			}

		}
		*t = ss->pr;
		break;
	case 4:// max players
		if (find->r != 2) {
			s3 = find;
			find = find->pr;
			for (s3; find->pr; find = find->pr, s3 = s3->pr) {
				if (find->r == 2) {
					s3->pr = find->pr;
					find->pr = *h;
					*h = find;
					ss->pr = *h;
					break;
				}
			}
		}
		s3 = 0;
		for (; ss->pr->pr;) {

			s1 = ss->pr;

			for (s2 = s1->pr, s5 = s1; s2; s2 = s2->pr, s5 = s5->pr) {

					if ((s1)->un.max_players > (s2)->un.max_players) {
						s1 = s2;
						s3 = s5;
					}
				

			}
			if (s1 != ss->pr) {
				s3->pr = s1->pr;
				s1->pr = ss->pr;
				ss->pr = s1;
			}

			ss = ss->pr;
			if (!s4) {
				free(s4);
				*h = s4 = s1;

			}
		}
		*t = ss->pr;
		break;
	default:
		printf("wrong number\n");
		break;
	}


}
int open_t(Game** h, Game** t) { // open txt file
	FILE* f;
	Game* n = nullptr;
	int l = 0;
	char chislo[100];
	char chislo_m[100];
	char genre[100];
	char name_c[100];
	char name[20];
	char c = ' ', file;
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
		if (!(n = (Game*)calloc(1, sizeof(Game)))) {
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
		(n)->price = atoi(chislo);
		if (!(n)->price) {
			printf("Error\n");
			return 0;
		}
		rewind(stdin);
		(n)->name = (char*)calloc(30, sizeof(char));
		fscanf(f, "%c", &c);
		while (c != '\n') {
			name_c[i] = c;
			fscanf(f, "%c", &c);
			i++;
		}
		name_c[i] = '\0';
		strcpy((n)->name, name_c);
		if (!(n)->name) {
			printf("Error\n");
			return 0;
		}
		fscanf(f, "%c", &c);
		(n)->r = (c - '0');
		if (!(n)->r) {
			printf("Error\n");
			return 0;
		}
		i = 0;
		fscanf(f, "%c", &c);
		fscanf(f, "%c", &c);
		if ((n)->r == 1) {
			while (c != '\n') {
				genre[i] = c;
				i++;
				fscanf(f, "%c", &c);
				if (feof(f)) {
					break;
				}
			}

			genre[i] = '\0';
			strcpy((n)->un.genre, genre);
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
			(n)->un.max_players = atoi(chislo_m);
		}

		if (!(*t) || !(*h)) {
			*t = n;
			*h = n;
		}
		else {
			(*t)->pr = n;
			*t = n;
		}
		fscanf(f, "%c", &c);
		if (feof(f)) {
			break;
		}
		rewind(stdin);
	} while (1);
	fclose(f);
	return 1;
}

void save_t(Game* h) { // save in txt file
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
		fprintf(f, "%d", (h)->price);
		fprintf(f, "%c", '\n');
		fprintf(f, "%s", (h)->name);
		fprintf(f, "%c", '\n');
		if ((h)->r == 1) {
			fprintf(f, "%d", (h)->r);
			fprintf(f, "%c", '\n');
			fprintf(f, "%s\n", (h)->un.genre);
		}
		else {
			fprintf(f, "%d", (h)->r);
			fprintf(f, "%c", '\n');
			fprintf(f, "%d\n", (h)->un.max_players);
		}
		if (!((h)->pr)) {
			break;
		}
		h = (h)->pr;

	}
	fclose(f);
	if (!(f = fopen("Files.txt", "r+"))) {
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
int open_b(Game** h, Game** t) { // open bin file
	FILE* f;
	Game* n = nullptr;
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
		if (!(n = (Game*)calloc(1, sizeof(Game)))) {
			printf("Error");
			return 0;
		}
		fread(&(n)->price, sizeof(int), 1, f);
		while (1) {
			fread(&name_f[i], sizeof(char), 1, f);
			if (name_f[i] == '\0') {
				break;
			}
			i++;
		}
		(n)->name = (char*)calloc(30, sizeof(char));
		strcpy(((n)->name), name_f);
		i = 0;
		fread(&(n)->r, sizeof(int), 1, f);
		if ((n)->r == 1) {
			while (1) {
				fread(&genre_f[i], sizeof(char), 1, f);
				if (genre_f[i] == '\0') {
					break;
				}
				i++;
			}

			strcpy((n)->un.genre, genre_f);
		}
		else {
			fread(&(n)->un.max_players, sizeof(int), 1, f);
		}
		if (!(*t) || !(*h)) {
			*t = n;
			*h = n;
		}
		else {
			(*t)->pr = n;
			*t = n;
		}
		fread(&i, sizeof(int), 1, f);
		if (feof(f)) {
			break;
		}
		rewind(stdin);
	} while (1);
	fclose(f);
	return 1;

}

void save_b(Game* h) { // save in bin file
	FILE* f;
	int i = 0;
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
	while (1) {
		i = 0;
		fwrite(&(h->price), sizeof(int), 1, f);
		strcpy(name_f, h->name);
		while (name_f[i]) {
			fwrite(&name_f[i], sizeof(char), 1, f);
			i++;
		}
		fwrite(&name_f[i], sizeof(char), 1, f);
		i = 0;
		fwrite(&(h->r), sizeof(int), 1, f);
		if (h->r == 1) {
			strcpy(genre_f, h->un.genre);
			while (genre_f[i]) {
				fwrite(&genre_f[i], sizeof(char), 1, f);
				i++;
			}
			fwrite(&genre_f[i], sizeof(char), 1, f);

		}
		else {
			fwrite(&(h->un.max_players), sizeof(int), 1, f);
		}
		if (!((h)->pr)) {
			break;
		}
		h = (h)->pr;

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
		if (!(strcmp("Files(b)", name_w_t))) {
			trig = 1;
			break;
		}
	}
	if (!trig) {
		fprintf(f, "\n%s", name_w_t);
	}
	fclose(f);
}
