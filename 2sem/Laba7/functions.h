#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include<conio.h>
#include"Tree.cpp"
void free_all(Node* s) {
	if (s) {
		if (s->left) {
			
			free_all(s->left);

		}
		
		if (s->right) {
			
			free_all(s->right);
		}
		free(s);
	}
	else {
		printf("No informations\n");
	}

}
void gets_max_ru(char* name, int n) { // I hate gets and i created this function
	int i = 0;
	char c;
	do {
		rewind(stdin);
		i = 0;
		c = ' ';
		int error = 0;
		while (c != '\n') {
			scanf("%c", &c);
			if (((c < 'à' || c > 'ÿ') && (c < 'À' || c>'ß')) && c != '\n') {
				printf("error\n");
				error = 1;
				break;
			}
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
void gets_max_eng(char* name, int n) { // I hate gets and i created this function
	int i = 0;
	char c;
	do {
		rewind(stdin);
		i = 0;
		c = ' ';
		int error = 0;
		while (c != '\n') {
			scanf("%c", &c);
			if (((c < 'a' || c > 'z')&&(c<'A'|| c>'Z'))&&c!='\n') {
				printf("error\n");
				error = 1;
				break;
			}
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
void push(Node** head) {
	Node* s1, * s2;
	int c;
	do {
		if (!(s1 = (Node*)calloc(1, sizeof(Node)))) {
			printf("Error");
			return;
		}

		printf("input a word in english\n");
		gets_max_eng(s1->tree.word, 100);
		printf("input a word in russian\n");
		gets_max_ru(s1->tree.ru_word, 100);
		if (!(*head)) {
			(*head) = s1;
			(*head)->tree.n = 0;
			(*head)->left = (*head)->right = nullptr;
		}
		else {
			s2 = *head;
			while (s2) {
				if (!strcmp(s1->tree.word, s2->tree.word)) {
					s2->tree.n++;
					free(s1);
					break;
				}
				else {
					if (strcmp(s1->tree.word, s2->tree.word) < 0) {
						if (s2->left == nullptr) {
							s2->left = s1;
							s2 = nullptr;
						}
						else {
							s2 = s2->left;
						}
					}
					else {
						if (s2->right == nullptr) {
							s2->right = s1;
							s2 = nullptr;
						}
						else {
							s2 = s2->right;
						}
					}
				}
			}
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
void recurs_output(Node* s) {
	if (s) {
		printf("%s\n%s\n", s->tree.word, s->tree.ru_word);
		if (s->left) {
			recurs_output(s->left);

		}
		
		if (s->right) {
			recurs_output(s->right);
		}
		
	}
	else {
		printf("No informations\n");
	}
}
void output(Node* head) {
	struct stek {
		Node* tree;
		stek* next;
	};
	stek* s1, * sl = nullptr;
	if (!head) {
		printf("No information\n");
		return;
	}
	s1 = (stek*)calloc(1, sizeof(stek));
	s1->tree = head;
	s1->next = sl;
	printf("%s\n%s\n", head->tree.word, head->tree.ru_word);
	int right_trigger = 1;
	while (s1 || head->right) {
		do {
			if (right_trigger && head->left) head = head->left;
			else if (head->right) head = head->right;
			right_trigger = 1;
			if (head->left && head->right) {
				sl = s1;
				s1 = (stek*)calloc(1, sizeof(stek));
				s1->tree = head;
				s1->next = sl;
			}
			printf("%s\n%s\n", head->tree.word, head->tree.ru_word);
		} while (head->left || head->right);
		if (s1) {
			head = s1->tree;
			sl = s1->next;		
			free(s1);
		}
		s1 = sl;
		if (head->left && head->right) right_trigger = 0;
		else break;
			
	}

}