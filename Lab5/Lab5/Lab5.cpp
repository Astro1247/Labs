#include "stdafx.h"
#include "stdlib.h"
#include "math.h"
#include "locale.h"

int main()
{
	int a, t, j1, j2;
	double fx, x = 1.1, arr[501], arr2d[7][4];
	setlocale(LC_ALL, "RUS");
	for (int i = 1; i <= 500; i++)
	{
		t = i - 1;
		a = i;
		fx = a * (cos(x / 50));
		arr[i] = fx;
		printf("%i елемент: %.40f\n", a, fx);
	}
	printf("Нажмите ENTER для продолжения . . . ");
	getchar();
	system("cls");
	for (j1 = 0; j1 <= 6; j1++)
	{
		for (j2 = 0; j2 <= 3; j2++)
		{
			arr2d[j1][j2] = rand() % (1000 + 1 - 1) + 1;
			//printf("Елемент %i|%i : %.0f\n", j1, j2, arr2d[j1][j2]);
		}
	}
	for (int i = 0; i <= 3; i++)
	{
		printf("%i \t", i);
	}
	printf("\n");
	for (j1 = 0; j1 < 7; j1++)
	{
		printf("%i \t", j1);
		for (j2 = 0; j2 < 3; j2++)
		{
			printf("%.0f \t", arr2d[j1][j2]);
		}
		printf("\n");
	}
	printf("Нажмите ENTER для продолжения . . . ");
	getchar();
    return 0;
}

