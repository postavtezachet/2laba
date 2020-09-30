#include<stdio.h>
#include<locale.h>
#define n 10
int main() {
	setlocale(LC_ALL, "Russian");
	int k=0,r;
	int mas[n];
	for (int i = 0; i < n; i++) { //Вводим массив
		scanf("%d", &mas[i]);
	}
	int min[n];
	for (int i = 0; i < n; i++) { /* копируем масив для выполнения сравнений или каких-нибудь
								  операций чтобы не потерять изначальной последовательности*/
		min[i] = mas[i];
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", mas[i]);

	}
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < n -1; j++) { // Сортировка копии массива по убыванию
			if (min[j]<min[j+1]) {
					r = min[j];
					min[j] = min[j + 1];
					min[j + 1] = r;
				}
			}
		}
		for (int i = n-5; i < n; i++) { // считаем только последнии пять элементов отсортированного массива
			for (int j = 0; j < n-1; j++) {
					if (min[i] == mas[j] || mas[j]==0) { //находим 5 минимальных элементов массива
						mas[j] = 0;  // заменяем 5 минимальных на 0
						r = mas[j];         //сортируем методом пузырика
						mas[j] = mas[j + 1];
						mas[j + 1] = r;
					}	
			}
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", mas[i]);
		
	}
	return 0;
}