#include "stdafx.h"
#include "stdlib.h"
#include "math.h"
#include "locale.h"

int main()
{
	int a, t, j1, j2, min, mint, inpt, numb, columns, rows, maxrand, minrand, err = 0;
	double fx, x = 1.1, arr2d[50][50];
	char yn;
	setlocale(LC_ALL, "RUS");
	do
	{
		do
		{
			printf("Меню программы представленно ниже, пожалуйста. сделайте Ваш выбор\n1. Программа вычисления функции f(x)=a*cos(x/50)\n2. Программа заполнения двумерного случайными элементами 1-100 и нахождение минимального значения\nПрограмму под каким пунктом Вы желаете выполнить?\nЗапустить программу под пунктом: ");
			inpt = _getch();
			switch (inpt)
			{
			case 49:
			{
				err = 0;
				do
				{
					int *arr;
					system("cls");
					printf("Пожалуйста, предоствавьте значение x=");
					scanf("%i", &x);
					fflush(stdin);
					printf("Сколько элементов вывести Вам вывести на экран?");
					scanf("%i", &numb);
					fflush(stdin);
					arr = (int*)malloc(numb * sizeof(int));
					for (int i = 1; i <= numb; i++)
					{
						t = i - 1;
						a = i;
						fx = a * (cos(x / 50));
						arr[i] = fx;
						printf("%i елемент: %.6f\n", a, fx);
					}
					printf("Желаете ли Вы повторить выполнение данной функции еще раз? (Y/N)");
					scanf("%c", &yn);
					getchar();
					//fflush(stdin);
				} while (yn == 'y' && yn != 'n');
				break;
			}
			case 50:
			{
				err = 0;
				do
				{
					system("cls");
					rows = columns = maxrand = minrand = 0;
					do
					{
						printf("Задайте количество строк для двумерного массива: ");
						scanf("%i", &rows);
						fflush(stdin);
						if (rows < 1 || rows > 50)
						{
							err = 1;
							printf("Неверный ввод\n");
						}
						else
							err = 0;
					} while (err == 1);
					do
					{
						printf("Задайте количество столбцов для двумерного массива: ");
						scanf("%i", &columns);
						fflush(stdin);
						if (columns < 1 || columns > 50)
						{
							err = 1;
							printf("Неверный ввод\n");
						}
						else
							err = 0;
					} while (err == 1);
					do
					{
						printf("Введите минимальное число генерируемых случайных чисел: ");
						scanf("%i", &minrand);
						fflush(stdin);
						if (minrand < -1000 || minrand > 1000)
						{
							err = 1;
							printf("Неверный ввод\n");
						}
						else
							err = 0;
					} while (err == 1);
					do
					{
						printf("Введите максимальное число генерируемых случайных чисел: ");
						scanf("%i", &maxrand);
						fflush(stdin);
						if (maxrand < -1000 || maxrand > 1000)
						{
							err = 1;
							printf("Неверный ввод\n");
						}
						else
							err = 0;
					} while (err == 1);
					printf("Вот массив:\n");
					for (j1 = 0; j1 < rows; j1++)
					{
						for (j2 = 0; j2 < columns; j2++)
						{
							arr2d[j1][j2] = rand() % (maxrand + 1 - minrand) + minrand;
						}
					}
					printf(" \t");
					for (int i = 0; i < columns; i++)
					{
						printf("%i \t", i);
					}
					printf("\n");
					for (j1 = 0; j1 < rows; j1++)
					{
						printf("%i \t", j1);
						for (j2 = 0; j2 < columns; j2++)
						{
							printf("%.0f \t", arr2d[j1][j2]);
						}
						printf("\n");
					}
					min = maxrand;
					for (j1 = 0; j1 < rows; j1++)
					{
						for (j2 = 0; j2 < columns; j2++)
						{
							mint = arr2d[j1][j2];
							if (mint < min) min = mint;
						}
					}
					printf("Вот Ваше минимальное число из массива: %i", min);
					printf("\nЖелаете ли Вы повторить выполнение данной функции еще раз? (Y/N)");
					yn = _getch();
				} while (yn == 'y' || yn == 'Y');
				break;
			}
			default:
			{
				err = 1;
				system("cls");
				printf("Неверный ввод, повторите попытку\n\n");
				break;
			}
			}
		} while (err = 1);
		system("cls");
		printf("Желаете ли Вы вернуться в главное меню программы для выбора другого алгоритма? (Y/N)");
		scanf("%c", &yn);
		getchar();
	} while (yn == 'y' && yn != 'n');
	printf("Пожалуйста, нажмине кнопку ENTER на вашей клавиатуре для продолжения . . . ");
	getchar();
    return 0;
}

