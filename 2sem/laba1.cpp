#include<stdio.h>
#include<Windows.h>
#include<string.h>

struct Employee {
	char first_name[20];
	char last_name[20];
	char patronymic[20];
	char position[50];
	int year_of_birthday;
	int salary;
}*s, *r;


void chang(int i,int j) {
	*(r + 0) = *(s + i);
	*(s + i) = *(s + j);
	*(s + j) = *(r + 0);
}
void menu() {
	printf("1:First name\n");
	printf("2:Last name\n");
	printf("3:Patronymic\n");
	printf("4:Position\n");
	printf("5:Year of birthday\n");
	printf("6:Salary\n");

}

void del1(int i, int* n) {
	if (*n > 1) {
		for (int j = i; j < *n; j++) {
			*(s + j) = *(s + j + 1);
		}
		*n = *n - 1;
		s = (struct Employee*)realloc(s, *n * sizeof(struct Employee));
	}
	else  if (*n == 1) {
		r = (struct Employee*)calloc(1, sizeof(struct Employee));
		*(s + i) = *r;
		*n = *n - 1;
		s = (struct Employee*)realloc(s, *n * sizeof(struct Employee));
	}
}

void output1a(int i) {
	printf("Employee ¹%d\n", i + 1);
	printf("First name: ");
	puts((s + i)->first_name);
	printf("Last name: ");
	puts((s + i)->last_name);
	printf("Patronymic: ");
	puts((s + i)->patronymic);
	printf("Position: ");
	puts((s + i)->position);
	printf("Year of birthday: %d\n", (s + i)->year_of_birthday);
	printf("Salary: %d", (s + i)->salary);
	printf("\n\n");
}

void search(int n) {
	system("cls");
	menu();
	int a;
	int j;

	char se[50];
	if (!scanf("%d", &a)) {
		return 0;
	}
	switch (a) {
		case 1:
			printf("input search query: ");		
			gets_s(se, 50);
			gets_s(se,50);
			for (int i = 0; i < n; i++) {
				if (!(strcmp((s+i)->first_name, se))) {
					output1a(i);
				}
			}
			break;
		case 2:
			printf("input search query: ");
			gets_s(se, 50);
			gets_s(se,50);
			for (int i = 0; i < n; i++) {
				if (!(strcmp((s + i)->last_name, se))) {
					output1a(i);
				}
			}
			break;
		case 3:
			printf("input search query: ");
			gets_s(se, 50);
			gets_s(se,50);
			for (int i = 0; i < n; i++) {
				if (!(strcmp((s + i)->patronymic, se))) {
					output1a(i);
				}
			}
			break;
		case 4:
			printf("input search query: ");
			gets_s(se, 50);
			gets_s(se,50);
			for (int i = 0; i < n; i++) {
				if (!(strcmp((s + i)->position, se))) {
					output1a(i);
				}
			}
			break;
		case 5:
			printf("input search query: ");
			if (!scanf("%d", &j)) {
				return 0;
			}
			for (int i = 0; i < n; i++) {
				if ((s+i)->year_of_birthday == j) {
					output1a(i);
				}
			}
			break;
		case 6:
			printf("input search query: ");
			if (!scanf("%d", &j)) {
				return 0;
			}
			for (int i = 0; i < n; i++) {
				if ((s + i)->salary == j) {
					output1a(i);
				}
			}
			break;
		default:
			printf("wrong number\n");
			break;
	}
}



void output(int n) {
	system("cls");
	for (int i = 0; i < n; i++) {
		
		printf("Employee ¹%d\n", i + 1);
		printf("First name: ");
		puts((s + i)->first_name);
		printf("Last name: ");
		puts((s + i)->last_name);
		printf("Patronymic: ");
		puts((s + i)->patronymic);
		printf("Position: ");
		puts((s + i)->position);
		printf("Year of birthday: %d\n", (s+i) -> year_of_birthday);	
		printf("Salary: %d", (s+i) -> salary);
		printf("\n\n");

	}
}

void change_info(int n) {
	int b;
	printf("\nWhich employee do you want to change ? \n");
	if (!scanf("%d", &b)) {
		return;
	}
	b--;
	if (b >= n) {
		printf("wrong number\n");
		return;
	}
	printf("What parameter do you want to change?\n");

	system("cls");
	menu();
	int a;
	if (!scanf("%d", &a))
	{
		return;
	}
	switch (a) {
		case 1:
			printf("Input new first name: ");
			gets_s((s + b)->first_name, 20);
			gets_s((s + b)->first_name,20);
			break;
		case 2:
			printf("Input new Last name: ");
			gets_s((s + b)->last_name, 20);
			gets_s((s + b)->last_name,20);
			break;
		case 3:
			printf("Input new patronymic: ");	
			gets_s((s + b)->patronymic, 20);
			gets_s((s + b)->patronymic,20);
			break;
		case 4:
			printf("Input new position: ");
			gets_s((s + b)->position, 50);
			gets_s((s + b)->position,50);
			break;
		case 5:
			printf("Input new year of birthday: ");
			if (!scanf("%d", &(s + b)->year_of_birthday)) {
				return;
			}
			break;
		case 6:
			printf("Input new salary: ");
			if (!scanf("%d", &(s + b)->salary)) {
				return;
			}
			break;
		default:
			printf("wrong number\n");
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

void sorting(int n) {
	system("cls");
	printf("What parameter do you want to sorting?\n");
	menu();
	int a;
	
	if (!scanf("%d", &a)) {
		return 0;
	}
	switch (a) {
		case 1:
			for (int i = 0; i < n; i++) {
				for (int j = i+1; j < n; j++) {
					if (tolowersorting((s+i)->first_name,(s+j)->first_name) > 0) {
						chang(i, j);
					}
				}
			}
			break;
		case 2:
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (tolowersorting((s + i)->last_name, (s + j)->last_name) > 0) {
						chang(i, j);
					}
				}
			}
			break;
		case 3:
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (tolowersorting((s + i)->patronymic, (s + j)->patronymic) > 0) {
						chang(i, j);
					}
				}
			}
			break;
		case 4:
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (tolowersorting((s + i)->position, (s + j)->position) > 0) {
						chang(i, j);
					}
				}
			}
			break;
		case 5:
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if ((s+i)->year_of_birthday>(s+j)->year_of_birthday) {
						chang(i, j);
					}
				}
			}
			break;
		case 6:
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if ((s + i)->salary < (s + j)->salary) {
						chang(i, j);
					}
				}
			}
			break;
		default:
			printf("wrong number\n");
			break;
		
	}

}

void del(int *n) {
	system("cls");
	printf("What parameter do you want to search by?\n");
	menu();
	
	int a;
	int j;
	char se[50];
	scanf("%d", &a);
	switch (a) {
	case 1:
		printf("input search query: ");
		gets_s(se, 50);
		gets_s(se, 50);
		for (int i = 0; i < *n; i++) {
			if (!(strcmp((s + i)->first_name, se))) {
				del1(i, n);			
				i--;
			}
		}
		break;
	case 2:
		printf("input search query: ");
		gets_s(se, 50);
		gets_s(se, 50);
		for (int i = 0; i < *n; i++) {
			if (!(strcmp((s + i)->last_name, se))) {
				del1(i, n);
				i--;
			}
		}
		break;
	case 3:
		printf("input search query: ");
		gets_s(se, 50);
		gets_s(se, 50);
		for (int i = 0; i < *n; i++) {
			if (!(strcmp((s + i)->patronymic, se))) {
				del1(i, n);
				i--;
			}
		}
		break;
	case 4:
		printf("input search query: ");
		gets_s(se, 50);
		gets_s(se, 50);
		for (int i = 0; i < *n; i++) {
			if (!(strcmp((s + i)->position, se))) {
				del1(i, n);
				i--;
			}
		}
		break;
	case 5:
		printf("input search query: ");
		if (!scanf("%d", &j)) {
			return 0;
		}
		for (int i = 0; i < *n; i++) {
			if ((s + i)->year_of_birthday == j) {
				del1(i, n);
				i--;
			}
		}
		break;
	case 6:
		printf("input search query: ");
		if (!scanf("%d", &j)) {
			return 0;
		}
		for (int i = 0; i < *n; i++) {
			if ((s + i)->salary == j) {
				del1(i, n);
				i--;
			}
		}
		break;
	default:
		printf("wrong number\n");
		break;
	}
}

int psearch1(char* se,char* s1) {
	int r = 0, i = 0, j = 0, k=0;
	while (se[i]) {
		if (se[i] != '*') {
			r++;
		}
		i++;
	}
	if (r == 0) {
		return 0;
	}
	i = 0;
	while (s1[i]) {
		while (se[j] == '*') {
			j++;
		}
		if ((se[j] == s1[i]) && (se[j-1] == '*' || s1[i-1] ==se[j-1] || (i==0 && j==0) ))  {
			j++;
			k++;
		}
		i++;
	}
	if (k == r) {
		return 1;
	}
	else {
		return 0;
	}
}

void psearch(int n) {
	system("cls");
	menu();
	int i, a;
	int j;
	char se[50];
	char* p;
	char buff[20];
	if (!scanf("%d", &a)) {
		return 0;
	}
	fflush(stdin);
	switch (a) {
		case 1:
			printf("input search query: ");
			gets_s(se, 50);
			gets_s(se,50);
			for (int i = 0; i < n; i++) {
				if (psearch1(se,(s+i)->first_name)) {
					output1a(i);
				}
			}
			break;
		case 2:
			printf("input search query: ");
			gets_s(se, 50);
			gets_s(se, 50);
			for (int i = 0; i < n; i++) {
				if (psearch1(se, (s + i)->last_name)) {
					output1a(i);
				}
			}
			break;
		case 3:
			printf("input search query: ");
			gets_s(se, 50);
			gets_s(se, 50);
			for (int i = 0; i < n; i++) {
				if (psearch1(se, (s + i)->patronymic)) {
					output1a(i);
				}
			}
			break;
		case 4:
			printf("input search query: ");
			gets_s(se, 50);
			gets_s(se, 50);
			for (int i = 0; i < n; i++) {
				if (psearch1(se, (s + i)->position)) {
					output1a(i);
				}
			}
			break;
		case 5:
			printf("input search query: ");
			gets_s(se, 50);
			gets_s(se, 50);
			
			for (int i = 0; i < n; i++) {
				p = itoa((s + i)->year_of_birthday, buff, 10);
				if (psearch1(se, p)) {
					output1a(i);
				}
			}
			break;
		case 6:
			printf("input search query: ");
			gets_s(se, 50);
			gets_s(se, 50);

			for (int i = 0; i < n; i++) {
				p = itoa((s + i)->salary, buff, 10);
				if (psearch1(se, p)) {
					output1a(i);
				}
			}
			break;
		default:
			printf("wrong number\n");

	}
}

int main() {
	system("chcp 1251 > null");
	int n;
	printf("Enter the number of employees: ");
	if (!scanf("%d", &n)) {
		return 0;
	}
	s = (struct Employee*)calloc(n, sizeof(struct Employee));
	r = (struct Employee*)calloc(1, sizeof(struct Employee));
	for (int i = 0; i < n; i++) {
		printf("Employee ¹%d\n", i+1);
		printf("Input first name: ");
		gets_s((s + i)->first_name, 20);
		gets_s((s + i)->first_name,20);
		printf("Input last name: ");
		gets_s((s + i)->last_name,20);
		printf("Input patronymic: ");
		gets_s((s + i)->patronymic,20);
		printf("Input position: ");
		gets_s((s + i)->position,50);
		printf("Input year of birthday: ");
		if (!scanf("%d", &(s + i)->year_of_birthday)) {
			return 0;
		}
		printf("Input salary: ");
		if (!scanf("%d", &(s + i)->salary)) {
			return 0;
		}

		printf("\n");
	}
	
	int a;
	do {
		printf("Input number of operation\n");
		printf("If you want exit, input 99\n");
		printf("1:Information output\n");
		printf("2:Change information\n");
		printf("3:Search\n");
		printf("4:Sorting\n");
		printf("5:Delete\n");
		printf("6:Partial search\n");
		if (!scanf("%d", &a)) {
			return 0;
		}
		printf("\n");
		switch (a) {
			case 1:
				output(n);
				break;
			case 2:	
				change_info(n);
				break;
			case 3:
				search(n);
				break;
			case 4:
				sorting(n);
				break;
			case 5:
				del(&n);
				break;
			case 6:
				psearch(n);
				break;
			default:
				printf("wrong number\n");
				break;
		}	
		
	} while (a != 99);
	free(s);
	free(r);
	return 0;
}