#include "stdafx.h"															 
#include "math.h"																	 
#include "locale.h"																	 															 


int main()
{
	setlocale(LC_ALL, "RUS");
func1:
	char yn;
	int s = 0, f = 0;
	do
	{
		f = f + 1;
		//printf("S меньше 50, увеличиваем S на 1... (S=%i)\n", s);
		s = s + f;
		printf("Проверка на выполнение условия S<50...\nS= %i\n", s);
	} while (s < 50);
	printf("Остановка цикла..\n");
	printf("Сейчас S равен %i\n", s);
check1:
	printf("Повторить? (y/n)\n");
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
	}
func2:

	printf("Нажмите ENTER чтобы продолжить . . .\n");
	getchar();
	return 0;
}

