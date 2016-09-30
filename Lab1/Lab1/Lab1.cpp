// Lab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "locale.h"
#include <stdlib.h>
#include <time.h>


void Swap(int *Mas, int i, int N2, int K2)
{
	int temp;
	temp = Mas[i];
	Mas[i] = Mas[i - 1];
	Mas[i - 1] = temp;
	printf("\nСостояние массива: ");
	for (K2 = 0; K2<N2; K2++)
		printf("%i, ", Mas[K2]);
}

void ShakerSort(int *Mas, int Start, int N, int K)
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

void main()
{
	int n, k, temp1;
	setlocale(LC_ALL, "RUS");
	printf("Размер массива: ");
	scanf("%d", &n);
	clock_t begin = clock();
	int *A = new int[n];
	for (k = 0; k<n; k++)
	{
		temp1 = k + 1;
		/*printf("%i элемент: ", tt1);
		scanf("%d", &A[k]);
		getchar();*/
		A[k] = rand() % (500 + 1 - 0) + 0;
		printf("%i элемент: %i\n", temp1, A[k]);
	}
	ShakerSort(A, 1, n, k);
	printf("\nРезультирующий массив: ");
	for (k = 0; k<n; k++) 
		printf("%i, ", A[k]);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nПотраченное время: %f секунд\n", time_spent);
	printf("Нажмите ENTER для продолжения  . . . ");
	getchar();
	getchar();
}

