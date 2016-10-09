#include "stdafx.h"
#include "stdlib.h"
#include "math.h"
#include "locale.h"


int main()
{
	int input1, input2, input3;
	char yn;
	setlocale(LC_ALL, "RUS");
	do
	{
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
		printf("Повторить? (Y/N)");
		scanf(" %c", &yn);
	} while (yn == 'y' && yn != 'n');
	getchar();
	system("cls");
	do
	{
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
		printf("\nПовторить? (Y/N)");
		scanf(" %c", &yn);
	} while (yn == 'y' && yn != 'n');
	printf("\nДля продолжения нажмите ENTER . . . ");
	getchar();
	getchar();
    return 0;
}

