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
			//printf("S меньше 50, увеличиваем S на 1... (S=%i)\n", s);
			s = s + f;
			printf("Проверка на выполнение условия S<50...\nS= %i\n", s);
		} while (s < 50);
		printf("Остановка цикла..\n");
		printf("Сейчас S равен %i\n", s);
		/*printf("Повторить? (y/n)\n");
		scanf(" %c", &yn);
		if (yn == 'n' || yn == 'N')
		{
			goto func2;
		}
		else if (yn == 'Y' || yn == 'y')
		{
			goto func1;
			printf("\n");
		}
		else
		{
			printf("Некорректный ввод.\n");
			goto check1;
		}*/
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

