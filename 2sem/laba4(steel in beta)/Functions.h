#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include<conio.h>
#include"Functions.cpp"

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
		gets_s((*s)->name, 30);
		printf("What do you want to add\n");
		printf("1:Genre\n");
		printf("2:Max player\n");
		while (1) {
			rewind(stdin);
			scanf("%d", &(*s)->r);
			if ((*s)->r == 1) {
				rewind(stdin);
				printf("Input game genre: ");
				gets_s((*s)->un.genre, 20);
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
	printf("| Game ¹ | Price |    Name    |     Genre     | Max players |\n");
	printf("------------------------------------------------------------------\n");
	while(1) {
		printf("|  %6d", i + 1);
		printf("|%7d|%12s", (s)->price, (s)->name);
		if ((s)->r == 2) {
			printf("|\t\t      |%13d|\n", (s)->un.max_players);
		}
		else if ((s)->r == 1) {
			printf("|%15s|\t\t    |\n", (s)->un.genre);
		}
		printf("------------------------------------------------------------------\n");
		i++;
		if (!(s->point)) {
			return;
		}
		s = s->point;
		
		
	}
}

void del(Game** s,int n) {
	Game* ptr;
	ptr = *s;

	int i = 1;
	while (1) {
		if (n == 0) {
			(*s) = (*s)->point;
			free(ptr->name);
			free(ptr);
			return;
		}
		else if (n == i) {
			ptr = ptr->point;
			if (!((*s)->point)) {
				(*s)->point = nullptr;
				free(ptr->name);
				free(ptr);
				return;
			}

			 
			(*s)->point = ptr->point;
			free(ptr->name);
			free(ptr);
			return;
		}
		ptr = ptr->point;
		*s = (*s)->point;
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
		for (int i = 0; s; s=s->point) {
			if (j == (s)->price) {
				one_output(s);
			}
		}
		break;
	case 2:
		printf("input search query: ");

		gets_s(se, 30);
		for (int i = 0;  s; s = s->point) {
			if (!(strcmp((s)->name, se))) {
				one_output(s);
			}
		}
		break;
	case 3:
		printf("input search query: ");

		gets_s(se, 30);
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
		for (int i = 0;  s; s = s->point) {
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
	Game* s1, * s2, *s3=0, * s4 = nullptr,*s5, * ss;
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
			for (s2 = ss->point,s5=ss; s2; s2 = s2->point,s5=s5->point) {
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
			if (s1->r != 1) {
				continue;
			}
			for (s2 = ss->point, s5 = ss; s2; s2 = s2->point, s5 = s5->point) {
				if (s2->r != 1) {
					continue;
				}
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
			if (s1->r != 2) {
				continue;
			}
			for (s2 = ss->point, s5 = ss; s2; s2 = s2->point, s5 = s5->point) {
				if (s2->r != 2) {
					continue;
				}
				if ((s1)->un.max_players < (s2)->un.max_players) {
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