#include "stdafx.h"
#include "stdio.h" 
#include "locale.h" 
#include "stdlib.h"
#include "time.h"

void show(int *data, size_t count)
{

}

int main()
{
	srand(time(0));
	int *arr1, n, inptsize, a, b, c, temp, temp1, size, midsize, intsize;
	setlocale(LC_ALL, "RUS");
	printf("Size : ");
	scanf(" %d", &n);
	size = n;
	arr1 = (int*)malloc(n * sizeof(int));
	printf("������ �������: %i\n", size);
	midsize = size / 2;
	int *arrpart1, *arrpart2;
	arrpart1 = (int*)malloc(midsize * sizeof(int));
	arrpart2 = (int*)malloc(midsize * sizeof(int));
	for (int i = 0; i<size; i++)
	{
		temp1 = i + 1;
		arr1[i] = rand() % 500;
		printf("%i �������: %i\n", temp1, arr1[i]);
	}
	printf("%i", arr1[2]);
	for (int i = 0; i < midsize; i++)
	{
		//	arrpart1[i] = arr1[i];
	}
	printf("������ ����� �������� � ����� ������...\n");
	size -= 1;
	for (int i = midsize; i < size - 1; i++)
	{
		arrpart2[i] = arr1[i];
	}
	printf("������ ����� �������� � ����� ������...\n");
	getchar();
	system("pause");
}