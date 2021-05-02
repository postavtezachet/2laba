#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include<conio.h>
#include"struct.cpp"
void free_all(Node** h) {  // memory deletion
	Node* s;
	Node* head = *h;
	(*h) = (*h)->right;
	if (head == *h) {
		s = *h;
		free(s->game.name);
		free(s);
		(*h) = nullptr;
		return;
	}
	do {
		s = (*h);
		(*h) = (*h)->right;
		free(s->game.name);
		free(s);
		if (*h == head) {
			s = *h;
			free(s->game.name);
			free(s);
			(*h) = nullptr;
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
void push(Node** head) { // add new struct 
	Node* s1,*s2 = nullptr;
	if ((*head)) {
		s2 = (*head)->left;
	}
	int c;
	char* number;
	int i = 0, trig = 0;
	number = (char*)calloc(11, sizeof(char));

	do {
		if (!(s1 = (Node*)calloc(1, sizeof(Node)))) {
			printf("Error");
			return;
		}

		while (1) {
			i = 0;
			trig = 0;
			printf("Input game price: ");
			gets_max(number, 10);
			while (number[i]) {
				if (number[i] >= '0' && number[i] <= '9') {
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
				s1->game.price = atoi(number);
				break;
			}
		}

		i = 0;
		rewind(stdin);
		printf("Input game name: ");
		s1->game.name = (char*)calloc(30, sizeof(char));
		gets_max(s1->game.name, 30);
		printf("What do you want to add\n");
		printf("1:Genre\n");
		printf("2:Max player\n");
		while (1) {
			rewind(stdin);
			while (1) {
				i = 0;
				trig = 0;
				gets_max(number, 10);
				while (number[i]) {
					if (number[i] >= '0' && number[i] <= '9') {
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
					(s1)->game.union_trigger = atoi(number);
					break;
				}
			}
			if ((s1)->game.union_trigger == 1) {
				rewind(stdin);
				printf("Input game genre: ");
				gets_max((s1)->game.un.genre, 20);
				break;
			}
			else if ((s1)->game.union_trigger == 2) {

				while (1) {
					i = 0;
					trig = 0;
					printf("Input max number of players: ");
					gets_max(number, 10);
					while (number[i]) {
						if (number[i] >= '0' && number[i] <= '9') {
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
						(s1)->game.un.max_players = atoi(number);
						break;
					}
				}
				break;
			}
			else {
				printf("Wrong number ");
			}
		}
		if (!(*head)) {
			(*head) = s1;
			s2 = s1;
			(*head)->left = (*head)->right = *head;
		}
		else {
			s1->left = s2;
			s2->right = s1;
			s2 = s1;
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
	s1->right = *head;
	(*head)->left = s1;
}

void show(Node* head) { // output all structs
	if (!head) {
		printf("no information\n");
		return;
	}
	Node* h = head;
	int i = 0;
	printf("| Game ¹ |  Price  |             Name             |        Genre        |  Max players  |\n");
	printf("-----------------------------------------------------------------------------------------\n");
	do {
		printf("|  %6d", i + 1);
		printf("|%9d|%30s", h->game.price, (h)->game.name);
		if ((h)->game.union_trigger == 2) {
			printf("|\t\t        |%15d|\n", (h)->game.un.max_players);
		}
		else if ((h)->game.union_trigger == 1) {
			printf("|%21s|\t\t|\n", (h)->game.un.genre);
		}
		printf("-----------------------------------------------------------------------------------------\n");
		i++;
		h = h->right;
		if ((h == head)) {
			return;
		}


	} while (1);
}
void del(Node** h,int n) { // delete struct number n
	Node* ptr, * buff;
	if (!*h) {
		printf("Error\n");
		return;
	}
	ptr = *h;
	buff = (*h)->right;
	int i = 1;
	while (1) {
		if (buff->right == buff && i!=1) {
			free(buff->game.name);
			free(buff);
			(*h) = nullptr;
			return;
		}
		else if (n == 0) {
			
			(*h) = (*h)->right;
			ptr->left->right = ptr->right;
			ptr->right->left = ptr->left;
			free(ptr->game.name);
			free(ptr);
			return;
		}
		else if (n == i) {
			ptr->right = buff->right;
			buff->right->left = ptr;
			free(buff->game.name);
			free(buff);
			return;
		}
		if (buff == *h) {
			printf("There is no such number\n");
			return;
		}
		ptr = ptr->right;
		buff = (buff)->right;
		i++;
	}
}

void menu() {
	printf("1:Price\n");
	printf("2:Name\n");
	printf("3:Genre\n");
	printf("4:Max_players\n");
}

void one_output(Node* h, int r, int i) { // output one struct
	if (r == 0) {
		printf("| Game ¹ |  Price  |             Name             |        Genre        |  Max players  |\n");
	}
	printf("-----------------------------------------------------------------------------------------\n");
		printf("|  %6d", i + 1);
		printf("|%9d|%30s", h->game.price, (h)->game.name);
		if ((h)->game.union_trigger == 2) {
			printf("|\t\t        |%15d|\n", (h)->game.un.max_players);
		}
		else if ((h)->game.union_trigger == 1) {
			printf("|%21s|\t\t|\n", (h)->game.un.genre);
		}
		printf("-----------------------------------------------------------------------------------------\n");
		i++;
		


	
}
void search(Node* h) {
	system("cls");
	menu();
	Node* head = h;
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
		for (int i = 0; h!=head || i==0; h = h->right) {
			if (j == (h)->game.price) {	
				one_output(h,r,i);
				r = 1;

			}
			i++;
		}
		break;
	case 2: //search name
		printf("input search query: ");

		gets_max(se, 30);
		for (int i = 0; h != head || i == 0; h = h->right) {
			if (!(strcmp((h)->game.name, se))) {
				one_output(h, r,i);
				r = 1;
			}
			i++;
		}
		break;
	case 3: // search gener
		printf("input search query: ");

		gets_max(se, 30);
		for (int i = 0; h != head || i == 0; h = h->right) {
			if ((h)->game.union_trigger == 1) {
				if (!(strcmp((h)->game.un.genre, se))) {
					one_output(h, r,i);
					r = 1;
				}
			}
			i++;
		}
		break;
	case 4: // search max players
		printf("input search query: ");

		while (!scanf("%d", &j)) {
			rewind(stdin);
			printf("Error\n");
			printf("input correct query: ");

		}
		for (int i = 0; h != head || i == 0; h = h->right) {
			if ((h)->game.union_trigger == 2) {
				if (j == (h)->game.un.max_players) {
					one_output(h, r,i);
					r = 1;
				}
			}
			i++;
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
int open_t(Node** h) { // open txt file
	FILE* f;
	Node* n = nullptr;
	Node* n2 = nullptr;
	if ((*h)) {
		n2 = (*h)->left;
	}
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
		if (!(n = (Node*)calloc(1, sizeof(Node)))) {
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
		(n)->game.price = atoi(chislo);
		if (!(n)->game.price) {
			printf("Error\n");
			return 0;
		}
		rewind(stdin);
		(n)->game.name = (char*)calloc(30, sizeof(char));
		fscanf(f, "%c", &c);
		while (c != '\n') {
			name_c[i] = c;
			fscanf(f, "%c", &c);
			i++;
		}
		name_c[i] = '\0';
		strcpy((n)->game.name, name_c);
		if (!(n)->game.name) {
			printf("Error\n");
			return 0;
		}
		fscanf(f, "%c", &c);
		(n)->game.union_trigger = (c - '0');
		if (!(n)->game.union_trigger) {
			printf("Error\n");
			return 0;
		}
		i = 0;
		fscanf(f, "%c", &c);
		fscanf(f, "%c", &c);
		if ((n)->game.union_trigger == 1) {
			while (c != '\n') {
				genre[i] = c;
				i++;
				fscanf(f, "%c", &c);
				if (feof(f)) {
					break;
				}
			}

			genre[i] = '\0';
			strcpy((n)->game.un.genre, genre);
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
			(n)->game.un.max_players = atoi(chislo_m);
		}

		if (!(*h)) {
			(*h) = n;
			n2 = n;
			(*h)->left = (*h)->right = *h;
		}
		else {
			n->left = n2;
			n2->right = n;
			n2 = n;
		}
		fscanf(f, "%c", &c);
		if (feof(f)) {
			break;
		}
		rewind(stdin);
	} while (1);
	n->right = *h;
	(*h)->left = n;
	fclose(f);
	return 1;
}

void save_t(Node* h) { // save in txt file
	FILE* f;
	Node* head = h;
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
		fprintf(f, "%d", (h)->game.price);
		fprintf(f, "%c", '\n');
		fprintf(f, "%s", (h)->game.name);
		fprintf(f, "%c", '\n');
		if ((h)->game.union_trigger == 1) {
			fprintf(f, "%d", (h)->game.union_trigger);
			fprintf(f, "%c", '\n');
			fprintf(f, "%s\n", (h)->game.un.genre);
		}
		else {
			fprintf(f, "%d", (h)->game.union_trigger);
			fprintf(f, "%c", '\n');
			fprintf(f, "%d\n", (h)->game.un.max_players);
		}
		h = (h)->right;
		if (h == head) {
			break;
		}
		

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
int open_b(Node** h) { // open bin file
	FILE* f;
	Node* n = nullptr;
	Node* n2 = nullptr;
	if ((*h)) {
		n2 = (*h)->left;
	}
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
		if (!(n = (Node*)calloc(1, sizeof(Node)))) {
			printf("Error");
			return 0;
		}
		fread(&(n)->game.price, sizeof(int), 1, f);
		while (1) {
			fread(&name_f[i], sizeof(char), 1, f);
			if (name_f[i] == '\0') {
				break;
			}
			i++;
		}
		(n)->game.name = (char*)calloc(30, sizeof(char));
		strcpy(((n)->game.name), name_f);
		i = 0;
		fread(&(n)->game.union_trigger, sizeof(int), 1, f);
		if ((n)->game.union_trigger == 1) {
			while (1) {
				fread(&genre_f[i], sizeof(char), 1, f);
				if (genre_f[i] == '\0') {
					break;
				}
				i++;
			}

			strcpy((n)->game.un.genre, genre_f);
		}
		else {
			fread(&(n)->game.un.max_players, sizeof(int), 1, f);
		}
		if (!(*h)) {
			(*h) = n;
			n2 = n;
			(*h)->left = (*h)->right = *h;
		}
		else {
			n->left = n2;
			n2->right = n;
			n2 = n;
		}
		fread(&i, sizeof(int), 1, f);
		if (feof(f)) {
			break;
		}
		rewind(stdin);
	} while (1);
	n->right = *h;
	(*h)->left = n;
	fclose(f);
	return 1;

}

void save_b(Node* h) { // save in bin file
	FILE* f;
	Node* head = h;
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
		fwrite(&(h->game.price), sizeof(int), 1, f);
		strcpy(name_f, h->game.name);
		while (name_f[i]) {
			fwrite(&name_f[i], sizeof(char), 1, f);
			i++;
		}
		fwrite(&name_f[i], sizeof(char), 1, f);
		i = 0;
		fwrite(&(h->game.union_trigger), sizeof(int), 1, f);
		if (h->game.union_trigger == 1) {
			strcpy(genre_f, h->game.un.genre);
			while (genre_f[i]) {
				fwrite(&genre_f[i], sizeof(char), 1, f);
				i++;
			}
			fwrite(&genre_f[i], sizeof(char), 1, f);

		}
		else {
			fwrite(&(h->game.un.max_players), sizeof(int), 1, f);
		}
		h = (h)->right;
		if (h == head) {
			break;
		}
		

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
