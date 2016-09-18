// One.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main()
{
	float v = 50, s = 10, h;
	h = v / s;
	printf("Result usng float (height): %f", h);
	int v1 = 50, s1 = 10, h1;
	h1 = v1 / s1;
	printf("\nResult usng int   (height): %i", h1);
	printf("\nPress ENTER to continue...");
	getchar();
	return 0;
}

