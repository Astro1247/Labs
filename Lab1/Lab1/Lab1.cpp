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

int merge_sort(int *a, int l, int r)
{
	if (l == r) return 0;
	int mid = (l + r) / 2;
	merge_sort(a, l, mid);
	merge_sort(a, mid + 1, r);
	int * tmp;
	int i = l;
	int j;
	j = mid + 1;
	tmp = (int*)malloc(r * sizeof(int));
	for (int step = 0; step < r - l + 1; step++) {
		if ((j > r) || ((i <= mid) && (a[i] < a[j]))) {
			tmp[step] = a[i];
			i++;
		}
		else {
			tmp[step] = a[j];
			j++;
		}
	}
	for (int step = 0; step < r - l + 1; step++)
		a[l + step] = tmp[step];
	return 0;
}

void MergeSort()
{
	system("cls");
	char yn;
	int i, numb, err = 0;
	do
	{
		printf("������� ���������� ��������� � ������� (1-10): ");
		scanf("%d", &numb);
		getchar();
		if (numb > 10 || numb < 1)
		{
			err = 1;
			printf("��������� ����� ��������� ���������� �����, ��������� ����.\n");
		}
		else
		{
			err = 0;
		}
	} while (err == 1);
	int *a = (int*)malloc(numb * sizeof(int));
	do
	{
		printf("��������� ������ ���������� �������? (Y/N)\n");
		yn = _getch();
		if (yn == 'y' || yn == 'Y')
		{
			for (int i = 0; i < numb; i++)
			{
				a[i] = rand() % (500 + 1 - 0) + 0;
				printf("%i �������: %i\n", i + 1, a[i]);
			}
			err = 0;
		}
		else if (yn == 'n' || yn == 'N')
		{
			for (int i = 0; i < numb; i++)
			{
				printf("������� %i �������: ", i + 1);
				int Input;
				scanf("%i", &a[i]);
			}
			for (int i = 0; i < numb; i++)
			{
				printf("%i �������: %i\n", i + 1, a[i]);
			}
			err = 0;
		}
		else
		{
			printf("������������ ����\n");
			err = 1;
		}
	} while (err == 1);
	printf("������ ���������� �������...\n");
	merge_sort(a, 0, numb - 1);
	printf("\n������������ ������: ");
	for (i = 0; i<numb; i++)
		printf(" %d ", a[i]);
	printf("\n");
}

void CountSort()
{
	int numb, err = 0, MaxInput;
	system("cls");
	srand(time(0));
	char yn;
	do
	{
		printf("������� ���������� ��������� � ������� (1-10): ");
		scanf("%d", &numb);
		getchar();
		if (numb > 10 || numb < 1)
		{
			err = 1;
			printf("��������� ����� ��������� ���������� �����, ��������� ����.\n");
		}
		else
		{
			err = 0;
		}
	} while (err == 1);
	int *A = (int*)malloc(numb * sizeof(int));
	do
	{
		printf("��������� ������ ���������� �������? (Y/N)\n");
		yn = _getch();
		if (yn == 'y' || yn == 'Y')
		{
			for (int i = 0; i < numb; i++)
			{
				A[i] = rand() % (500 + 1 - 0) + 0;
				printf("%i �������: %i\n", i + 1, A[i]);
			}
			err = 0;
		}
		else if (yn == 'n' || yn == 'N')
		{
			for (int i = 0; i < numb; i++)
			{
				printf("������� %i �������: ", i + 1);
				int Input;
				scanf("%i", &A[i]);
			}
			for (int i = 0; i < numb; i++)
			{
				printf("%i �������: %i\n", i + 1, A[i]);
			}
			err = 0;
		}
		else
		{
			printf("������������ ����\n");
			err = 1;
		}
	} while (err == 1);
	printf("������ ���������� �������...\n");
	clock_t begin = clock();
	MaxInput = A[0];
	for (int i = 0; i < numb; i++)
	{
		if (MaxInput < A[i])
			MaxInput = A[i];
	}
	int *B = (int*)malloc(MaxInput * sizeof(int));
	for (int i = 0; i <= MaxInput; i++)
	{
		B[i] = 0;
	}
	for (int i = 0; i < numb; i++)
	{
		int temp1 = A[i];
		B[temp1] += 1;
	}
	for (int i = 0; i <= MaxInput; i++)
	{
		if (B[i] != 0)
			printf("%i, ", i);
	}
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n����������� �����: %f ������\n", time_spent);
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
		printf("�������� ����������:\n1.��������� ����������\n2.��������� ��������\n3.���������� ���������\n������� ����� ��������� ����������: ");
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
			MergeSort();
			//printf("������� � ����������...");
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
