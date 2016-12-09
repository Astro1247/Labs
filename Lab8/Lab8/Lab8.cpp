// ConsoleApplication12.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <locale.h>
#include "locale.h"
#include <stdlib.h>

float ff(float n);
void clean_stdin();
int maximum(int ar[], int n);
void func1();
void func2();

int main()
{
	char yn = 'n';
	int menuPoint = 0, error = 0;
	setlocale(LC_ALL, "RUS");
	do
	{
		do
		{
			menuPoint = 0;
			system("cls");
			printf("Меню:\n1. Вычисление радиуса круга\n2. Нахождение максимального элемента в массиве\n0. Выйти из программы\n");
			if (error == 1)
			{
				printf("При вводе была допущена ошибка, повторите попытку...\n");
				error = 0;
			}
			printf("Выберите алгоритм: ");
			if (scanf("%i[0-9]", &menuPoint) == 1) {}
			else
			{
				error = 1;
			}
			if (menuPoint < 0 || menuPoint > 2) { error = 1; }
			clean_stdin();
		} while (error == 1);
		switch (menuPoint)
		{
		case 0:
			break;
		case 1:
			system("cls");
			func1();
			break;
		case 2:
			system("cls");
			func2();
			break;
		default:
			break;
		}
		if (menuPoint == 0) {}
		else
		do
		{
			printf("Вернуться в главное меню программы? (Y/N) ");
			clean_stdin(); //Очистка буфера ввода
			scanf("%c", &yn);
			getchar();
			if (yn == 'y' || yn == 'Y' || yn == 'n' || yn == 'N') { error = 0; }
			else error = 1;
		} while (error == 1);
	} while (yn == 'y' && yn != 'n'); // Если пользователь ввел "Y" то повторить выполнение алгоритма
	return 0;
}


float ff(float n) {
	return 3.14 * n * n;
}

void clean_stdin() // Функция очистки буфера ввода с клавиатуры
{
	fflush(stdin);
	fseek(stdin, 0, SEEK_END);
}

int i = 0, max;

int maximum(int ar[], int n)
{
	int max;
	if (!n)
		return ar[n];
	max = maximum(ar, n - 1);
	return ar[n]>max ? ar[n] : max;
}

void func1()
{
	char yn;
	float r = 0, s;
	int error;
	do {
		do
		{
			system("cls");
			error = 0; // Очистка переменной отвечающей за наличие ошибок (если ошибки будут, программа задаст значание позже)
			printf("Радиус может быть от 0,1 до 1000\nВведите радиус круга: ");
			clean_stdin(); // Очистить буфер ввода
			if (scanf("%f[0-9]", &r) == 1) {} // Проверка ввел ли пользователь буквы или цифры
			else
			{
				printf("Вы ввели буквы, повторите ввод");
				error = 1; // Произошла ошибка.

			}
			if (r > 100 || r <= 0) // Проверка введенного числа на вхождение в допустимый диапазон вводимых чисел
			{
				printf("Введенное число не входит в допустимый диапазон\nДопустимый диапазон: 0,1 - 1000\n");
				error = 1; // Произошла ошибка.
			}
			clean_stdin();
		} while (error == 1); // Повторять пока есть ошибка
		s = ff(r);
		printf("Площадь равна : %f\n", s);
		do
		{
			printf("Повторить выполнение функции? (Y/N) ");
			clean_stdin(); //Очистка буфера ввода
			scanf("%c", &yn);
			getchar();
			if (yn == 'y' || yn == 'Y' || yn == 'n' || yn == 'N') { error = 0; }
			else error = 1;
		} while (error == 1);
	} while (yn == 'y' && yn != 'n'); // Если пользователь ввел "Y" то повторить выполнение алгоритма
	//return 0;
}

void func2()
{
	char yn;
	int error = 0, sizeA, *A, i = 0, max = 0, n = 1;
	do {
		do
		{
			system("cls");
			printf("Допустимый диапазон от 2 до 20\n");
			if (error == 1)
			{
				printf("При вводе была допущена ошибка, повторите попытку ввода...\n");
				error = 0; // Очистка переменной отвечающей за наличие ошибок (если ошибки будут, программа задаст значание позже)
			}
			printf("Введите размер масива: ");
			clean_stdin(); // Очистить буфер ввода 
			if (scanf("%i[0-9]", &sizeA) == 1) {} // Проверка ввел ли пользователь буквы или цифры
			else
			{
				printf("Вы ввели буквы, повторите ввод\n");
				error = 1; // Произошла ошибка.

			}
			if (sizeA > 20 || sizeA < 2) // Проверка введенного числа на вхождение в допустимый диапазон вводимых чисел
			{
				printf("Введенное число не входит в допустимый диапазон\n");
				error = 1; // Произошла ошибка.
			}
		} while (error == 1); // Повторять пока есть ошибка

		A = (int*)malloc(sizeA * sizeof(int));

		if (!A) {
			printf("Память не была выделена под даный масив");
			getchar();
			return;
		}
		printf("Можно вводить только числа от -20000 до 20000\n");
		for (i = 0; i < sizeA; i++) {
			do
			{
				error = 0; // Очистка переменной отвечающей за наличие ошибок (если ошибки будут, программа задаст значание позже)
				printf("Введите %i єлемент массива ", i+1);
				clean_stdin(); // Очистить буфер ввода 
				if (scanf("%i[0-9]", &A[i]) == 1) {} // Проверка ввел ли пользователь буквы или цифры
				else
				{
					printf("Вы ввели буквы, повторите ввод\n");
					error = 1; // Произошла ошибка.
				}
				if (A[i] > 20000 || A[i] <= -20000) // Проверка введенного числа на вхождение в допустимый диапазон вводимых чисел
				{
					printf("Введенное число не входит в допустимый диапазон\n");
					error = 1; // Произошла ошибка.
				}
			} while (error == 1); // Повторять пока есть ошибка
		}
		printf("Даный массив: \n");
		for (i = 0; i < sizeA; i++) {
			printf("%i ", A[i]);
		}
		max = A[0];
		max = maximum(A, sizeA);
		printf("\nМаксимальный элемент в массиве: %i\n", max);
		system("pause");
		do
		{
			printf("Повторить выполнение функции? (Y/N) ");
			clean_stdin(); //Очистка буфера ввода
			scanf("%c", &yn);
			getchar();
			if (yn == 'y' || yn == 'Y' || yn == 'n' || yn == 'N') { error = 0; }
			else error = 1;
		} while (error == 1);
	} while (yn == 'y' && yn != 'n'); // Если пользователь ввел "Y" то повторить выполнение алгоритма
	//return 0;
}