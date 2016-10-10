#include "stdafx.h"		
#include "stdlib.h"
#include "math.h"																	 
#include "locale.h"																	 															 


int main()
{
	int s, f, input[5], i, temp, a = 1, numb;
	char yn;
	setlocale(LC_ALL, "RUS");
	do
	{
		printf("Установите лимит числа S: ");
		scanf("%i", &numb);
		getchar();
		s = 0;
		f = 0;
		while (s < numb)
		{
			f = f + 1;
			s = s + f;
			printf("Проверка на выполнение условия S<%i...\nS= %i\n", numb, s);
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
	return 0;
}

