#include "stdafx.h"															 
#include "math.h"																	 
#include "locale.h"																	 															 


int main()
{
	setlocale(LC_ALL, "RUS");
	int s, f, input[4], i, temp;
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
			printf("Введите число %i: ", i);

			scanf("%d", &input[i]);
		}
		printf("Повторить? (Y/N)");
		scanf(" %c", &yn);
	} while (yn == 'y' && yn != 'n');
	return 0;
}

