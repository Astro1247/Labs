#include "stdafx.h"
#include "locale.h"
#include "stdlib.h"
#include "time.h"
#include "conio.h"


int Swap(int *Mas, int i, int N2, int K2)
{
	int temp;
	temp = Mas[i];
	Mas[i] = Mas[i - 1];
	Mas[i - 1] = temp;
	printf("\n��������� �������: ");
	for (K2 = 0; K2<N2; K2++)
		printf("%i, ", Mas[K2]);
}

int Shake(int *Mas, int Start, int N, int K)
{
	int Left, Right, i, N1 = N, K1 = K;
	Left = Start;
	Right = N - 1;
	while (Left <= Right)
	{
		for (i = Right; i >= Left; i--)
		{
			if (Mas[i - 1] > Mas[i]) Swap(Mas, i, N1, K1);
		}
		Left++;
		for (i = Left; i <= Right; i++)
		{
			if (Mas[i - 1] > Mas[i]) Swap(Mas, i, N1, K1);
		}
		Right--;
	}
}

int ShakerSort()
{
	int n, k, temp1;
	srand(time(0));
	printf("\n������ �������: ");
	scanf("%d", &n);
	getchar();
	clock_t begin = clock();
	//int *A = new int[n];
	int *A = (int*)malloc(n * sizeof(int));
	
	for (k = 0; k<n; k++)
	{
		temp1 = k + 1;
		/*printf("%i �������: ", temp1);
		scanf("%d", &A[k]);
		getchar();*/
		A[k] = rand() % (500 + 1 - 0) + 0;
		printf("%i �������: %i\n", temp1, A[k]);
	}
	Shake(A, 1, n, k);
	printf("\n�������������� ������: ");
	for (k = 0; k<n; k++) 
		printf("%i, ", A[k]);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n����������� �����: %f ������\n", time_spent);
	free(A);
}

void CountSort()
{
	int numb, err = 0, MaxInput;
	system("cls");
	srand(time(0));
	char yn;
	do
	{
		printf("������� ���������� ��������� � �������: ");
		scanf("%d", &numb);
		getchar();
		if (numb > 10 || numb < 0)
		{
			err = 1;
			printf("��������� ����� ��������� ���������� �����, ��������� ����.\n");
		}
		else
		{
			err = 0;
		}
	} while (err == 1);
	//clock_t begin = clock();
	int *A = (int*)malloc(numb * sizeof(int));
	printf("��������� ������ ���������� �������? (Y/N)\n");
	yn = _getch();
	if (yn == 'y' || yn == 'Y')
	{
		for (int i = 0; i < numb; i++)
		{
			A[i] = rand() % (500 + 1 - 0) + 0;
			printf("%i �������: %i\n", i+1, A[i]);
		}
	}
	else if (yn == 'n' || yn == 'N')
	{
		for (int i = 0; i < numb; i++)
		{
			printf("������� %i �������: ", i+1);
			int Input;
			scanf("%i", &A[i]);
			printf("%i\n", A[i]);
			//A[i] = Input;
		}
		for (int i = 0; i < numb; i++)
		{
			printf("%i �������: %i\n", i + 1, A[i]);
		}
	}
	MaxInput = A[0];
	for (int i = 0; i < numb; i++)
	{
		if (MaxInput < A[i])
			MaxInput = A[i];
	}
	int *B = (int*)malloc(MaxInput * sizeof(int));
	for (int i = 0; i < numb; i++)
	{
		int temp1 = A[i];
		B[temp1] += 842150452;
	}
	for (int i = 0; i <= MaxInput-1; i++)
	{
		if (B[i] != -842150451)
			printf("%d\n", B[i]);
		for (int j = 0; j < B[i]; j++)
		{
			printf("%i, ", i);
		}
	}
	//clock_t end = clock();
	//double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	//printf("\n����������� �����: %f ������\n", time_spent);
	free(A);
}

void Switcher()
{
	int func = 0, err = 0;
	while (func == 0)
	{
		if (err == 1)
		{
			system("cls");
			printf("������������ ����\n\n");
			err = 0;
		}
		else
			system("cls");
		system("cls");
		printf("�������� ���������.\n");
		printf("�������� ����������:\n1.��������� ����������\n-2.��������� ��������    // � ����������\n3.���������� ���������\n������� ����� ��������� ����������: ");
		func = _getch();
		switch (func)
		{
		case 49:
		{
			ShakerSort();
			break;
		}
		case 50:
		{
			printf("������� � ����������...");
			break;
		}
		case 51:
		{
			CountSort();
			break;
		}
		default:
		{
			err = 1;
			func = 0;
			break;
		}
		}
	}
}

int main()
{
	char yn;
	setlocale(LC_ALL, "RUS");
	do
	{
		Switcher();
		fflush(stdin);
		printf("��������� � ���� ���������? (Y/N) ");
		yn = _getch();
	} while (yn == 'y' || yn == 'Y');
}
