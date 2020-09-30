#include<stdio.h>
#include<locale.h>
#define n 4
#define m 3
int main() {
	setlocale(LC_ALL, "Russian");
	int mas[n][m];
	int k = 0,s;
	printf("¬ведите число которое хотите найти ");
	scanf("%d",&s);
	printf("¬ведите матрицу");
	for (int i = 0; i < n; i++) { // ввод  матрицы с клавиатуры
		for (int j = 0; j < m; j++) {
			scanf("%d" ,&mas[i][j]);
		}
	}
	printf("\n");
	for (int i = 0; i < n; i++) { // вывод матрицы
		for (int j = 0; j < m; j++) {
			printf("%d ", mas[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s == mas[i][j]) { // провер€ем равн€етс€ ли данный элемнт массива введЄнному числу
				k++; // если да увеличиваем счЄтчик на 1
			}
		}
	}
	printf("„исло %d встречаетс€ %d ", s, k);
	return 0;

}