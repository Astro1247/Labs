#include "stdafx.h"
#include "stdlib.h"
#include "math.h"
#include "locale.h"

int main()
{
	int a, t, j1, j2, min = 100, mint, inpt;
	double fx, x = 1.1, arr[501], arr2d[7][4];
	char yn;
	setlocale(LC_ALL, "RUS");
	do
	{
		system("cls");
		printf("Меню программы\n1. Программа вычисления функции\n2. Программа заполнения двумерного случайными элементами 1-100 и нахождение минимального значения\nЗапустить программу №");
		scanf("%i", &inpt);
		getchar();
		switch (inpt)
		{
		case 1:
		{
			system("cls");
			do
			{
				for (int i = 1; i <= 500; i++)
				{
					t = i - 1;
					a = i;
					fx = a * (cos(x / 50));
					arr[i] = fx;
					printf("%i елемент: %.40f\n", a, fx);
				}
				printf("Повторить? (Y/N)");
				scanf("%c", &yn);
				getchar();
			} while (yn == 'y' && yn != 'n');
			break;
		}
		case 2:
		{
			system("cls");
			do
			{
				for (j1 = 0; j1 < 6; j1++)
				{
					for (j2 = 0; j2 < 3; j2++)
					{
						arr2d[j1][j2] = rand() % (100 + 1 - 1) + 1;
						//printf("Елемент %i|%i : %.0f\n", j1, j2, arr2d[j1][j2]);
					}
				}
				printf(" \t");
				for (int i = 0; i < 3; i++)
				{
					printf("%i \t", i); //ПОдписываем колонки
				}
				printf("\n");
				for (j1 = 0; j1 < 6; j1++)
				{
					printf("%i \t", j1);
					for (j2 = 0; j2 < 3; j2++)
					{
						printf("%.0f \t", arr2d[j1][j2]);
					}
					printf("\n");
				}
				min = 100;
				for (j1 = 0; j1 < 6; j1++)
				{
					for (j2 = 0; j2 < 3; j2++)
					{
						mint = arr2d[j1][j2];
						if (mint < min) min = mint;
					}
				}
				printf("Минимальное число из массива: %i\n", min);
				printf("Повторить? (Y/N)");
				scanf("%c", &yn);
				getchar();
			} while (yn == 'y' && yn != 'n');
			break;
		}
		}
		system("cls");
		printf("Вернуться в меню программы? (Y/N)");
		scanf("%c", &yn);
		getchar();
	} while (yn == 'y' && yn != 'n');
	printf("Нажмите ENTER для продолжения . . . ");
	getchar();
    return 0;
}

