// ConsoleApplication12.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <locale.h>
#include "locale.h"
#include <stdlib.h>

float ff(float);
int find_max(int *A, int sizeA, int, int);

int main()
{
	float r = 0, s;
	int err, yn = 0, sizeA, *A, i = 0, max = 0, n = 1;
	setlocale(LC_ALL, "RUS");
	printf("Считать радиус круга= 1\nНахождения максимального элемента в массиве= 2");
	/*do {
	do {
	do
	{
	err = 0; // Очистка переменной отвечающей за наличие ошибок (если ошибки будут, программа задаст значание позже)
	printf("Введите радиус круга: ");
	clean_stdin(); // Очистить буфер ввода
	if (scanf("%f[0-9]", &r) == 1) {} // Проверка ввел ли пользователь буквы или цифры
	else
	{
	printf("Вы ввели буквы, повторите ввод\nможно вводить только числа от 0,1 до 1000,0");
	err = 1; // Произошла ошибка.

	}
	if (r > 100 || r <= 0) // Проверка введенного числа на вхождение в допустимый диапазон вводимых чисел
	{
	printf("Введенное число не входит в допустимый диапазон\nДопустимый диапазон: 0,1 - 1000,0\n");
	err = 1; // Произошла ошибка.
	}
	} while (err == 1); // Повторять пока есть ошибка
	s = ff(r);
	printf("Площадь равна : %f\n", s);
	printf("\nВведите 1 если хотите повторить операцию");
	scanf("%i", &yn);
	} while (yn == 1);

	*/	do {
		do
		{
			err = 0; // Очистка переменной отвечающей за наличие ошибок (если ошибки будут, программа задаст значание позже)
			printf("\nВведите размер масива ");
			clean_stdin(); // Очистить буфер ввода 
			if (scanf("%i[0-9]", &sizeA) == 1) {} // Проверка ввел ли пользователь буквы или цифры
			else
			{
				printf("Вы ввели буквы, повторите ввод\nможно вводить только числа от ");
				err = 1; // Произошла ошибка.

			}
			if (sizeA > 20 || sizeA <= 2) // Проверка введенного числа на вхождение в допустимый диапазон вводимых чисел
			{
				printf("Введенное число не входит в допустимый диапазон\nДопустимый диапазон: 2 - 20\n");
				err = 1; // Произошла ошибка.
			}
		} while (err == 1); // Повторять пока есть ошибка

		A = (int*)malloc(sizeA * sizeof(int));

		if (!A) {
			printf("Память не была выделена под даный масив");
			getchar();
			return 1;
		}
		for (i = 0;i < sizeA; i++) {
			do
			{
				err = 0; // Очистка переменной отвечающей за наличие ошибок (если ошибки будут, программа задаст значание позже)
				printf("Введите %i єлемент массива ", i);
				clean_stdin(); // Очистить буфер ввода 
				if (scanf("%i[0-9]", &A[i]) == 1) {} // Проверка ввел ли пользователь буквы или цифры
				else
				{
					printf("Вы ввели буквы, повторите ввод\nМожно вводить только числа от -20000 до 20000");
					err = 1; // Произошла ошибка.
				}
				if (r > 20000 || r <= -20000) // Проверка введенного числа на вхождение в допустимый диапазон вводимых чисел
				{
					printf("Введенное число не входит в допустимый диапазон\nДопустимый диапазон: от -20000 до 20000\n");
					err = 1; // Произошла ошибка.
				}
			} while (err == 1); // Повторять пока есть ошибка
		}
		printf("Даный массив:\n");
		for (i = 0;i < sizeA; i++) {
			printf("%i ", A[i]);
		}
		max = find_max(A, sizeA, 0, 0);
		printf("max= %i", max);
		system("pause");
	} while (yn == 2);
	//	} while (yn);
	return 0;
}

float ff(float n) {
	return 3.14 * n * n;
}

clean_stdin(void) // Функция очистки буфера ввода с клавиатуры
{
	fflush(stdin);
	fseek(stdin, 0, SEEK_END);
}

int find_max(int *A[], int sizeA, int i, int max)
{
	/*int b = A[i];
	printf("mas %i",i);
	getchar();
	system("pause");*/
	/*if (i < sizeA) {
		if (A[i] > max) {
			max = A[i];
		}
		else return 0;
			i++;
		find_max(A, sizeA, i+=1, max);
	}*/
	if (i < sizeA-1)
	{
		int maxx = &A[1];
		if (*maxx < A[i])
			maxx = A[i];
		i++;
		find_max(*A, sizeA, i, max);
	}
	return max;
}


/*int search(int *array, int array_size)
{
static int maxVal = 0;
static int currIndex = 0;
static int memIndex = 0;

if (array_size) {
if (*array > maxVal) {
maxVal = *array;
memIndex = currIndex;
}
currIndex++;
return search(++array, --array_size);
}
return memIndex;
}*/