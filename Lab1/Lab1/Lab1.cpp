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
	printf("\nСостояние массива: ");
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
	printf("\nРазмер массива: ");
	scanf("%d", &n);
	getchar();
	clock_t begin = clock();
	int *A = (int*)malloc(n * sizeof(int));
	
	for (k = 0; k<n; k++)
	{
		temp1 = k + 1;
		A[k] = rand() % (500 + 1 - 0) + 0;
		printf("%i элемент: %i\n", temp1, A[k]);
	}
	Shake(A, 1, n, k);
	printf("\nРезультирующий массив: ");
	for (k = 0; k<n; k++) 
		printf("%i, ", A[k]);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nПотраченное время: %f секунд\n", time_spent);
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
		printf("Введите количество элементов в массиве (1-10): ");
		scanf("%d", &numb);
		getchar();
		if (numb > 10 || numb < 1)
		{
			err = 1;
			printf("Введенное число превышает допустимый лимит, повторите ввод.\n");
		}
		else
		{
			err = 0;
		}
	} while (err == 1);
	int *a = (int*)malloc(numb * sizeof(int));
	do
	{
		printf("Заполнить массив случайными числами? (Y/N)\n");
		yn = _getch();
		if (yn == 'y' || yn == 'Y')
		{
			for (int i = 0; i < numb; i++)
			{
				a[i] = rand() % (500 + 1 - 0) + 0;
				printf("%i элемент: %i\n", i + 1, a[i]);
			}
			err = 0;
		}
		else if (yn == 'n' || yn == 'N')
		{
			for (int i = 0; i < numb; i++)
			{
				printf("Введите %i элемент: ", i + 1);
				int Input;
				scanf("%i", &a[i]);
			}
			for (int i = 0; i < numb; i++)
			{
				printf("%i элемент: %i\n", i + 1, a[i]);
			}
			err = 0;
		}
		else
		{
			printf("Недопустимый ввод\n");
			err = 1;
		}
	} while (err == 1);
	printf("Начата сортировка массива...\n");
	merge_sort(a, 0, numb - 1);
	printf("\nРезультующий массив: ");
	for (i = 0; i<numb; i++)
		printf(" %d ", a[i]);
	printf("\n");
}

void CountSort()
{
	int numb, err = 0, MaxInput, j = 0;
	system("cls");
	srand(time(0));
	char yn;
	do
	{
		printf("Введите количество элементов в массиве (2-10): ");
		scanf("%d", &numb);
		getchar();
		if (numb > 10 || numb < 2)
		{
			err = 1;
			printf("Введенное число превышает допустимый лимит, повторите ввод.\n");
		}
		else
		{
			err = 0;
		}
	} while (err == 1);
	int *A = (int*)malloc(numb * sizeof(int));
	int *A_sorted = (int*)malloc(numb * sizeof(int));
	do
	{
		printf("Заполнить массив случайными числами? (Y/N)\n");
		yn = _getch();
		if (yn == 'y' || yn == 'Y')
		{
			for (int i = 0; i < numb; i++)
			{
				A[i] = rand() % (500 + 1 - 0) + 0;
				printf("%i элемент: %i\n", i + 1, A[i]);
			}
			err = 0;
		}
		else if (yn == 'n' || yn == 'N')
		{
			printf("Допускаются только числа от -1000 до 1000\n");
			for (int i = 0; i < numb; i++)
			{
				printf("Введите %i элемент: ", i + 1);
				scanf("%i", &A[i]);
				fflush(stdin);
				getchar();
				if (A[i] > 1000 || A[i] < -1000)
				{
					printf("Значение числа превышает допустимые границы, повторите ввод\n");
					i -= 1;
				}
			}
			for (int i = 0; i < numb; i++)
			{
				printf("%i элемент: %i\n", i + 1, A[i]);
			}
			err = 0;
		}
		else
		{
			printf("Недопустимый ввод\n");
			err = 1;
		}
	} while (err == 1);
	printf("Начата сортировка массива...\n");
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
		{
			A_sorted[j] = i;
			j++;
		}
	}
	printf("Результующий массив: ");
	for (int i = 0; i < numb; i++)
		printf("%i, ", A_sorted[i]);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nПотраченное время: %f секунд\n", time_spent);
}

void Switcher()
{
	int func = 0, err = 0;
	while (func == 0)
	{
		if (err == 1)
		{
			system("cls");
			printf("Некорректный ввод\n\n");
			err = 0;
		}
		printf("Выберите сортировку:\n1.Шейкерная сортировка\n2.Сорировка слиянием\n3.Сортировка подсчетом\nВведите номер выбранной сортировки: ");
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
	int cycles = 0;
	char yn;
	setlocale(LC_ALL, "RUS");
	do
	{
		cycles += 1;
		if (cycles > 5)
			printf("Я уже устал! :(\n");
		Switcher();
		fflush(stdin);
		printf("Вернуться в меню программы? (Y/N) ");
		yn = _getch();
		system("cls");
	} while (yn == 'y' || yn == 'Y');
}
