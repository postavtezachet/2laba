#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include"functions.h"

int main() {
	system("chcp 1251 > null");
	Game* game;
	int n;
	printf("Input number of games: ");
	while (!scanf("%d", &n)) {
		rewind(stdin);
		printf("Error\n");
		printf("input correct number: ");
	}
	if (n < 1) {
		printf("Error");
		return 0;
	}
	game = (Game*)calloc(n, sizeof(Game));
	for (int i = 0; i < n; i++) {
		rewind(stdin);
		printf("Input game price: ");
		while (!scanf("%d", &(game + i)->price)) {
			rewind(stdin);
			printf("Error\n");
			printf("input correct price: ");
		}
		rewind(stdin);
		printf("Input game name: ");
		(game + i)->name = (char*)calloc(30, sizeof(char));
		gets_s((game+i)->name, 30);
		printf("What do you want to add\n");
		printf("1:Genre\n");
		printf("2:Max player\n");
		
		
		while(1) {
			rewind(stdin);
			scanf("%d", &(game + i)->r);
			if ((game + i)->r == 1) {
				rewind(stdin);
				printf("Input game genre: ");
				gets_s((game + i)->un.genre, 20);
				break;
			}
			else if((game + i)->r == 2) {
				printf("Input max number of players: ");
				while (!scanf("%d", &(game + i)->un.max_players)) {
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
	int a;
	do {
		printf("Input number of operation\n");
		printf("If you want exit, input 99\n");
		printf("1:Information output\n");
		printf("2:Add new game\n");
		printf("3:Search\n");
		printf("4:Delete\n");
		printf("5:Sorting\n");
		printf("6:Additional task 1 (min numbers of players)\n");
		printf("7:Additional task 2 (Delete gener)\n");
		while (!scanf("%d", &a)) {
			rewind(stdin);
			printf("Error\n");
			printf("input correct number: ");

		}
		rewind(stdin);
		printf("\n");
		switch (a) {
		case 1:
			output(game, n);
			break;
		case 2:
			n = n + 1;
			game = (Game*)realloc(game, n * sizeof(Game));
			add(game, &n);
			break;
		case 3:
			search(game, n);
			break;
		case 4:
			del(game, &n);
			break;
		case 5:
			sorting(game, n);
			break;
		case 6:
			min_players(game, n);
			break;
		case 7:
			delete_gener(game, &n);
		case 99:
			break;
		default:
			printf("wrong number\n");
			break;
		}
	} while (a != 99);
	if (n > 0) {
		for (int i = 0; i < n; i++) {
			free((game + i)->name);
		}
		free(game);
	}

	return 0;
}