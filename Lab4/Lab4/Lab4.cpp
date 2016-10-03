#include "stdafx.h"															 
#include "math.h"																	 
#include "locale.h"																	 															 


int main()
{
	setlocale(LC_ALL, "RUS");
	int s, f, input[5], i, temp, a = 1;
	char yn;
	do
	{
		s = 0;
		f = 0;
		do
		{
			f = f + 1;
			s = s + f;
			printf("Проверка на выполнение условия S<50...\nS= %i\n", s);
		} while (s < 50);
		printf("Остановка цикла..\n");
		printf("Сейчас S равен %i\n", s);
		printf("Повторить? (Y/N)");
		scanf(" %c", &yn);
	}  while (yn == 'y' && yn != 'n');
	printf("Нажмите ENTER чтобы продолжить . . .\n");
	getchar();
	do
	{
		for (i = 0; i < 5; i++)
		{
			printf("Введите число %i: ", i+1);
			scanf("%d", &input[i]);
			a = a * input[i];
		}
		printf("Результат умножения полученных чисел: %i\n", a);
		printf("Повторить? (Y/N)");
		scanf(" %c", &yn);
	} while (yn == 'y' && yn != 'n');
	return 2;
}

