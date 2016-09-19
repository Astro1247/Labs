// Lab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main()
{
	int s = 0;
	do
	{
		printf("S<50, increasing S by 1... (S=%i)\n", s);
		s = s + 1;
		printf("Checking if S<50...\n");
	} while (s < 50);
	printf("Stopping loop..\n");
	printf("Now S = %i\n", s);
	printf("Press ENTER to continue...\n");
	getchar();
	return 0;
}

