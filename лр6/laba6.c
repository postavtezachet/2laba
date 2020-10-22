#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
int main() {
	setlocale(LC_ALL, "Russian");
	int n, s = 0;
	float x;
	int** mas;
	int* b;
	printf("Введите количество строк матрицы: ");
	scanf("%d", &n); // Вводим количество строк, а кол-во столбцов равно 2*n
	printf("Введите x ");
	scanf("%f", &x);
	b = (int*)calloc(n, sizeof(int));// создаём динамический массив b
	mas = (int**)calloc(n, sizeof(int));  // создаём динамический двумерный массив
	for (int i = 0; i < n; i++) {
		mas[i] = (int*)calloc(2 * n, sizeof(int));
	}
	printf("Введите элементы массива\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			scanf("%d", (*(mas + i) + j));
		}
	}
	printf("Массив\n");
	for (int i = 0; i < n; i++) {
		printf("\n");
		for (int j = 0; j < 2 * n; j++) {
			printf("%4d", mas[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			if (x < mas[i][j]) {// проверяем привосходит ли x все числа в строчке
				*(b + i) = 0; // если да то b итый равен 0
				s = 1; // s нужна для проверки если мы не зайдём в этот if то s = 0
				break; // выходим из цикла который пробегает по строке
			}
		}
		if (s == 0) { // если ни один элемент строки не превоходит x то s равен 0
			*(b + i) = 1; // и b итый равен 1
		}
		s = 0; // зануляем s для проверки следующей строки
	}
	printf("\nПоследовательность 0 и 1 \n");
	for (int i = 0; i < n; i++) {
		printf("%d ", *(b + i));
	}
	free(b);// удаляем массив b
	free(mas);// удаляем двумерный массив mas
	return 0;
}