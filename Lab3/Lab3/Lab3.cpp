#include "stdafx.h"
#include "stdlib.h"
#include "math.h"
#include "locale.h"


int main()
{
	int input1, input2, input3;
	setlocale(LC_ALL, "RUS");
	func1:
	printf("Введите число для проверки: ");
	scanf("%d", &input1);
	if (input1 < 0)
	{
		printf("Это было отрицательное число.\n");
	}
	else if (input1 > 0)
	{
		printf("Это было положительное число.\n");
	}
	else
	{
		printf("Это был ноль.\n");
	}
	printf("Повторить проверку? (0 - нет/1 - да)");
	scanf("%d", &input3);
	if (input3 == 1)
	{
		goto func1;
	}
	getchar();
	func2:
	printf("Введите число для замены на еквивалентный символ: ");
	scanf("%d", &input2);
	printf("Еквивалентный символ: ");
	switch (input2)
	{
		case 1:
		{
			printf("!");
			break;
		}
		case 2:
		{
			printf("@");
			break;
		}
		case 3:
		{
			printf("#");
			break;
		}
		case 4:
		{
			printf("$");
			break;
		}
		case 5:
		{
			printf("%%");
			break;
		}
		case 6:
		{
			printf("^");
			break;
		}
		case 7:
		{
			printf("&");
			break;
		}
		case 8:
		{
			printf("*");
			break;
		}
		case 9:
		{
			printf("(");
			break;
		}
		case 0:
		{
			printf(")");
			break;
		}
	}
	printf("\nПовторить проверку? (0 - нет/1 - да)");
	scanf("%d", &input3);
	if (input3 == 1)
	{
		goto func2;
	}
	printf("\nДля продолжения нажмите ENTER . . . ");
	getchar();
	getchar();
    return 0;
}

