#include<stdio.h>
#include<math.h> // ���������� math.h ��� ����������� ������������ ������
int main() {
	float a=5, b=-3, c=-2; 
	if (a >= b && b >= c) {
		a *= 2;       // ��� ���������� ������� ����������� ��� �������� � 2 ����
		b *= 2;
		c *= 2;
	}
	else {
		a = abs(a); /*���� �� ����������� ������� �� �� �����������	���� ��������� 
					�� �������� �� ������*/
		b = abs(b);
		c = abs(c);
	}
	printf("a = %.2f", a);
	printf("\nb= %.2f", b);
	printf("\nc= %.2f", c);
	return 0;
	
}