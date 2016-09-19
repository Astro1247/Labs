// Lab3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main()
{
	int input1, input2;
	printf("Input number to check: ");
	scanf("%d", &input1);
	if (input1 < 0)
	{
		printf("That was negative number.\n");
	}
	else
	{
		printf("That was positive nubmer.\n");
	}
	getchar();
	printf("Input number to change to equival symbol: ");
	scanf("%d", &input2);
	printf("Equival symbol: ");
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
	getchar();
	getchar();
    return 0;
}

