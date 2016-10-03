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
		while (s < 50)
		{
			f = f + 1;
			s = s + f;
			printf("Проверка на выполнение условия S<50...\nS= %i\n", s);
		}
		printf("Остановка цикла..\n");
		printf("Сейчас S равен %i\n", s);
		printf("Повторить? (Y/N)");
		scanf(" %c", &yn);
	}  while (yn == 'y' && yn != 'n');
	printf("Нажмите ENTER чтобы продолжить . . .\n");
	getchar();
	do
	{
		i = 0;
		do
		{
			printf("Введите число %i: ", i+1);
			scanf("%d", &input[i]);
			a = a * input[i];
			i = i + 1;
		} while (i < 5);
		printf("Результат умножения полученных чисел: %i\n", a);
		printf("Повторить? (Y/N)");
		scanf(" %c", &yn);
	} while (yn == 'y' && yn != 'n');
	return 2;
}

