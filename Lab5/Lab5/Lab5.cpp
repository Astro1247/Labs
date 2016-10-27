#include "stdafx.h"
#include "stdlib.h"
#include "math.h"
#include "locale.h"

int main()
{
	int a, t, j1, j2, min, mint, inpt, numb, columns, rows, maxrand, minrand;
	double fx, x = 1.1, arr2d[7][4];
	char yn;
	setlocale(LC_ALL, "RUS");
	do
	{
		printf("���� ��������� ������������� ����, ����������. �������� ��� �����\n1. ��������� ���������� ������� f(x)=a*cos(x/50)\n2. ��������� ���������� ���������� ���������� ���������� � ���������� ������������ ��������\n��������� ��� ����� ������� �� ������� ���������?\n��������� ��������� ��� �������: ");
		scanf("%i", &inpt);
		getchar();
		switch (inpt)
		{
		case 1:
		{
			do
			{
				system("cls");
				printf("����������, ������������� �������� a=");
				scanf("%i", &a);
				getchar();
				printf("������� ��������� ������� ��� ������� �� �����?");
				scanf("%i", &numb);
				getchar();
				if (a < 1 || a > 100 || numb < 1 || numb > 100)
				{
					printf("���� ��������� �� ���������� �������� �� ������ �������� �� ������������ ���������� �������, ��������� ����? (Y/N) ");
					scanf("%c", &yn);
					getchar();
				}
				else
				{
					int *arr = (int*)malloc(numb * sizeof(int));
					for (x = 1; x <= 100; x++)
					{
						t = x - 1;
						fx = a * (cos(x / 50));
						arr[t] = fx;
						printf("%i �������: %.6f\n", a, fx);
					}
					printf("������� �� �� ��������� ���������� ������ ������� ��� ���? (Y/N)");
					scanf("%c", &yn);
					getchar();
				}
			} while (yn == 'y' && yn != 'n');
			break;
		}
		case 2:
		{
			do
			{
				system("cls");
				rows = columns = maxrand = minrand = 0;
				printf("������� ���������� ����� ��� ���������� �������: ");
				scanf("%i", &rows);
				getchar();
				printf("������� ���������� �������� ��� ���������� �������: ");
				scanf("%i", &columns);
				getchar();
				printf("������� ����������� ����� ������������ ��������� �����: ");
				scanf("%i", &minrand);
				getchar();
				printf("������� ������������ ����� ������������ ��������� �����: ");
				scanf("%i", &maxrand);
				getchar();
				printf("�������� ������������ ��������� �������� ���������� �������� ��������...\n");
				if (rows < 1 || rows > 30 || columns < 1 || columns > 30 || minrand < 0 || minrand > 5000 || maxrand < 0 || maxrand > 5000 || minrand > maxrand)
				{
					printf("���� ��������� �� ���������� �������� �� ������ �������� �� ������������ ���������� �������, ��������� ����? (Y/N) ");
					scanf("%c", &yn);
					getchar();
				}
				else
				{
					printf("��� ������:\n");
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
					printf("��� ���� ����������� ����� �� �������: %i\n", min);
					printf("������� �� �� ��������� ���������� ������ ������� ��� ���? (Y/N)");
					scanf("%c", &yn);
					getchar();
				}
			} while (yn == 'y' && yn != 'n');
			break;
		}
		}
		system("cls");
		printf("������� �� �� ��������� � ������� ���� ��������� ��� ������ ������� ���������? (Y/N)");
		scanf("%c", &yn);
		getchar();
	} while (yn == 'y' && yn != 'n');
	printf("����������, ������� ������ ENTER �� ����� ���������� ��� ����������� . . . ");
	getchar();
	return 0;
}

