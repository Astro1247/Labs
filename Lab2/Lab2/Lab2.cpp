// Lab2.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include "stdlib.h" 
#include "stdio.h" 
#include "conio.h" 
#include "math.h" 
#include "locale.h" 
#include "string.h" 
#define cube x*x


int main()
{
	setlocale(LC_ALL, "RUS");
	int x = 0, i, r, a, b, c;
	for (i = 0; i < 5; i++)
	{
		++x;
		r = cube;
		printf("For x=%i => x^2=%i\n", x, r);
	}
	printf("Press ENTER to continue...\n");
	getchar();
	printf("¬ведите 2 числа\nA=");
	scanf("%d", &a);
	printf("\nB=");
	scanf("%d", &b);
	c = a - b;
	printf("\nResult: A-B = %i\n", c);
	printf("Press ENTER to continue...");
	getchar();
	getchar();
    return 0;
}

