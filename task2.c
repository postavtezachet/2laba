#include<stdio.h>
#include<math.h> // подключаем math.h для возможности использовать модуль
int main() {
	float a=5, b=-3, c=-2; 
	if (a >= b && b >= c) {
		a *= 2;       // при выполнении условий увеличиваем все значения в 2 раза
		b *= 2;
		c *= 2;
	}
	else {
		a = abs(a); /*если не выполняются условия то мы присваеваем	всем значениям 
					их значения по модулю*/
		b = abs(b);
		c = abs(c);
	}
	printf("a = %.2f", a);
	printf("\nb= %.2f", b);
	printf("\nc= %.2f", c);
	return 0;
	
}