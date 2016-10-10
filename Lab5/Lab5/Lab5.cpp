#include "stdafx.h"
#include "stdlib.h"
#include "math.h"
#include "locale.h"

int main()
{
	int a, t, j1, j2, min = 100, mint, inpt, numb, columns, rows, maxrand, minrand;
	double fx, x = 1.1, arr2d[7][4];
	char yn;
	setlocale(LC_ALL, "RUS");
	do
	{
		printf("���� ��������� ������������� ����, ����������. �������� ��� �����\n1. ��������� ���������� ������� f(x)=a*cos(x/50)\n2. ��������� ���������� ���������� ���������� ���������� 1-100 � ���������� ������������ ��������\n��������� ��� ����� ������� �� ������� ���������?\n��������� ��������� ��� �������: ");
		scanf("%i", &inpt);
		getchar();
		switch (inpt)
		{
		case 1:
		{
			do
			{
				system("cls");
				printf("����������, ������������� �������� x=");
				scanf("%i", &x);
				getchar();
				printf("������� ��������� ������� ��� ������� �� �����? a=");
				scanf("%i", &numb);
				getchar();
				int *arr = new int[numb];
				for (int i = 1; i <= numb; i++)
				{
					t = i - 1;
					a = i;
					fx = a * (cos(x / 50));
					arr[i] = fx;
					printf("%i �������: %.40f\n", a, fx);
				}
				printf("������� �� �� ��������� ���������� ������ ������� ��� ���? (Y/N)");
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
					printf("%i \t", i); //����������� �������
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
				min = 100;
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
			} while (yn == 'y' && yn != 'n');
			break;
		}
		}
		system("cls");
		printf("������� �� �� ��������� � ������� ���� ��������� ��� ������ ������� ���������? (Y/N)");
		scanf("%c", &yn);
		getchar();
	} while (yn == 'y' && yn != 'n');
	//system("pause");
	printf("����������, ������� ������ ENTER �� ����� ���������� ��� ����������� . . . ");
	getchar();
    return 0;
}

