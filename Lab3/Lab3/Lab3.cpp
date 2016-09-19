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
		printf("\nNegative number.\n");
	}
	else
	{
		printf("Positive nubmer.\n");
	}
	printf("Press ENTER to continue...");
	getchar();

    return 0;
}

