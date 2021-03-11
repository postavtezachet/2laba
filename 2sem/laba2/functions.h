#include<stdio.h>
#include<Windows.h>
struct Game {

	int price;
	char* name;
	int r;
	union {
		char genre[20];
		int max_players;
	}un;
};



void output(struct Game* game, int n) {
	printf("| Game ¹ | Price |    Name    |     Genre     | Max players |\n");
	printf("------------------------------------------------------------------\n");
	for (int i = 0; i < n; i++) {
		
		printf("|  %6d", i+1);
		printf("|%7d|%12s", (game + i)->price, (game + i)->name);
		if ((game + i)->r == 2){
			printf("|\t\t      |%13d|\n", (game + i)->un.max_players);
		}
		else if ((game + i)->r==1) {
			printf("|%15s|\t\t    |\n", (game + i)->un.genre);
		}
		printf("------------------------------------------------------------------\n");
	}
}

void one_output(struct Game* game, int i) {
	printf("Game ¹%d\n", i + 1);
	printf("Price: %d\n", (game + i)->price);
	printf("Name: ");
	puts((game + i)->name);
	if ((game + i)->r == 1) {
		printf("Genre: ");
		puts((game + i)->un.genre);
		printf("\n");
	}
	else {
		printf("Max players: %d\n\n", (game + i)->un.max_players);
	}
}

void add(struct Game* game, int* n) {
	rewind(stdin);
	printf("Input game price: ");
	while (!scanf("%d", &(game + *n-1)->price)) {
			rewind(stdin);
			printf("Error\n");
			printf("input correct price: ");
	}
	rewind(stdin);
	printf("Input game name: ");
	(game + *n-1)->name = (char*)calloc(30, sizeof(char));
	gets_s((game + *n-1)->name, 30);
	while (1) {
		rewind(stdin);
		printf("What do you want to add\n");
		printf("1:Genre\n");
		printf("2:Max player\n");

		scanf("%d", &(game + *n-1)->r);
		if ((game + *n - 1)->r == 1) {
			rewind(stdin);
			printf("Input game genre: ");
			gets_s((game + *n - 1)->un.genre, 20);
			break;
		}
		else if ((game + *n - 1)->r == 2) {
			printf("Input max number of players: ");
			while (!scanf("%d", &(game + *n - 1)->un.max_players)) {
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
}

void menu() {
	printf("1:Price\n");
	printf("2:Name\n");
	printf("3:Genre\n");
	printf("4:Max_players\n");
}

void search(struct Game* game, int n) {
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
		for (int i = 0; i < n; i++) {
			if (j == (game+i)->price) {
				one_output(game, i);
			}
		}
		break;
	case 2:
		printf("input search query: ");

		gets_s(se, 30);
		for (int i = 0; i < n; i++) {
			if (!(strcmp((game + i)->name, se))) {
				one_output(game, i);
			}
		}
		break;
	case 3:
		printf("input search query: ");

		gets_s(se, 30);
		for (int i = 0; i < n; i++) {
			if ((game + i)->r == 1) {
				if (!(strcmp((game + i)->un.genre, se))) {
					one_output(game, i);
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
		for (int i = 0; i < n; i++) {
			if ((game + i)->r == 2) {
				if (j == (game + i)->un.max_players) {
					one_output(game, i);
				}
			}
		}
		break;
	default:
		printf("wrong number");
		break;
	}
}
void algoritm_delete(struct Game* game, int i, int* n){
	if (*n > 1) {
		for (int j = i; j < *n; j++) {
			*(game + j) = *(game + j + 1);
		}
		*n = *n - 1;
		game = (Game*)realloc(game, *n * sizeof(Game));
	}
	else  if (*n == 1) {
		*n = *n - 1;
		game = (Game*)realloc(game, *n * sizeof(Game));
	}
}

void del(struct Game* game, int* n) {
	system("cls");
	printf("What parameter do you want to search by?\n");
	menu();
	printf("5:By number\n");
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
		for (int i = 0; i < *n; i++) {
			if (j == (game + i)->price) {
				algoritm_delete(game, i, n);
				i--;
			}
		}
		break;
	case 2:
		printf("input search query: ");

		gets_s(se, 30);
		for (int i = 0; i < *n; i++) {
			if (!(strcmp((game + i)->name, se))) {
				algoritm_delete(game, i, n);
				i--;
			}
		}
		break;
	case 3:
		printf("input search query: ");

		gets_s(se, 30);
		for (int i = 0; i < *n; i++) {

			if ((game + i)->r == 1) {
				if (!(strcmp((game + i)->un.genre, se))) {
					algoritm_delete(game, i, n);
					i--;
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
		for (int i = 0; i < *n; i++) {
			if ((game + i)->r == 2) {
				if (j == (game + i)->un.max_players) {
					algoritm_delete(game, i, n);
					i--;
				}
			}
		}
		break;
	case 5:
		printf("input number of employee: ");
		while (!scanf("%d", &j)) {
			rewind(stdin);
			printf("Error\n");
			printf("input correct number: ");

		}
		j--;
		algoritm_delete(game, j, n);
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
void change(Game* game, int i,int j) {
	Game* r;
	r = (Game*)calloc(1, sizeof(Game));

	*r = *(game + i);
	*(game + i) = *(game + j);
	*(game + j) = *r;
	free(r);
}
void sorting(Game* game, int n) {
	system("cls");
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
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if ((game + i)->price < (game + j)->price) {
					change(game, i, j);
				}
			}
		}
		break;
	case 2:
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (tolowersorting((game + i)->name, (game + j)->name) > 0) {
					change(game,i, j);
				}
			}
		}
		break;
	case 3:
		for (int i = 0; i < n; i++) {
			if((game + i)->r != 1){
				continue;
			}
			for (int j = i + 1; j < n; j++) {
				if ((game + j)->r != 1) {
					continue;
				}
				if (tolowersorting((game + i)->un.genre, (game + j)->un.genre) > 0) {
					change(game, i, j);
				}
			}
		}
		break;
	case 4:
		for (int i = 0; i < n; i++) {
			
			for (int j = i + 1; j < n; j++) {
				
				if ((game + i)->un.max_players < (game + j)->un.max_players) {
					change(game, i, j);
				}
			}
		}
		break;
	default:
		printf("wrong number\n");
		break;
	}
	

}

void min_players(struct Game* game, int n)
{
	int min;
	int z = 0;
	for (int i = 0; i < n; i++) {
		if ((game + i)->r == 2) {
			min = (game + 0)->un.max_players;
			z = 1;
			break;
			
		}
	}
	if (z == 0) {
		printf("We can't find game with information about max players\n");
		return;
	}


	for (int i = 0; i < n; i++) {
		if ((game + i)->r == 2) {
			if (min > (game + i)->un.max_players) {
				min = (game + i)->un.max_players;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if ((game + i)->r == 2) {
			if (min == (game + i)->un.max_players) {
				one_output(game, i);
			}
		}
	}
}

void delete_gener(struct Game* game, int* n) {
	char se[30];
	printf("input search query: ");

	gets_s(se, 30);
	for (int i = 0; i < *n; i++) {
		if ((game + i)->r == 1) {
			if (!(strcmp((game + i)->un.genre, se))) {
				algoritm_delete(game, i, n);
				i--;
			}
		}
	}
}
