#include "stdafx.h"		
#include "stdlib.h"
#include "math.h"																	 
#include "locale.h"																	 															 


int main()
{
	int s, n, n1, k, f, input[5], i, temp, a = 1;
	char yn;
	setlocale(LC_ALL, "RUS");
	do
	{	
		s = 0;
		f = 0;
		printf("Введите число: ");
		scanf("%i",&n);
		while (s < n)
		{
			f = f + 1;
			s = s + f;
			printf("Проверка на выполнение условия S<%i...\nS= %i\n",n,s);
		}
		printf("Остановка цикла..\n");
		printf("Сейчас S равен %i\n", s);
		printf("Повторить? (Y/N)");
		scanf(" %c", &yn);
	}  while (yn == 'y' && yn != 'n');
	printf("Нажмите ENTER чтобы продолжить . . .\n");
	getchar();
	system("cls");
	do
	{
		i = 0;
		printf("Введите количество умножаемых чисел: ");
		scanf("%i",&n1);
		do
		{
			printf("Введите число %i: ", i+1);
			scanf("%i", &k);
			a = a * k;
			i = i + 1;
		} while (i < n1);
		printf("Результат умножения полученных чисел: %i\n", a);
		printf("Повторить? (Y/N)");
		scanf(" %c", &yn);
	} while (yn == 'y' && yn != 'n');
	return 0;
}

