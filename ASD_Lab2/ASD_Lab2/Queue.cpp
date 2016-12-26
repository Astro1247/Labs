#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 3

int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;
int full = 0;
int count = 0;

int fullList(int count)
{
	return intArray[count];
}

int peek() {
	return intArray[front];
}

bool isEmpty() {
	return itemCount == 0;
}

bool isFull() {
	return itemCount == MAX;
}

int size() {
	return itemCount;
}

void insert(int data) {

	if (!isFull()) {

		if (rear == MAX - 1) {
			rear = -1;
		}

		intArray[++rear] = data;
		itemCount++;
	}
}

int removeData() {
	int data = intArray[front++];

	if (front == MAX) {
		front = 0;
	}

	itemCount--;
	return data;
}

void queue()
{
	count = 0;
	full = 0;
	while (1)
	{
	int menuPoint = 1, currentSelect = 1;
	bool isSwitching = true, isError = 0;
	while (isSwitching == true)
	{
		clean();
		int pressedkey = "";
		printf("Меню управления очередью:\n=> 1. Добавить элемент\n   2. Вывести очередь\n   3. Считать первый элемент\n   4. Проверить очередь на пустоту\n   5. Получить размер очереди\n   6. Удалить первый элемент из очереди");
		{
			int pressedkey;
			int i = 0;
			int counter = 0;
			while (isSwitching)
				if ((pressedkey = getch()) != -1)
				{
					counter += 1;
					if (pressedkey == 80)
					{
						if (menuPoint < 6)
							menuPoint += 1;
						isError = false;
					}
					else if (pressedkey == 72)
					{
						if (menuPoint > 1)
							menuPoint -= 1;
						isError = false;
					}
					else if (pressedkey == 13)
						isSwitching = false;
					else if (pressedkey == 27)
						return;
					else if (counter > 1)
						break;
					if (counter > 1)
					{
						if (isError == false)
						{
							currentSelect = menuPoint;
							system("cls");
							printf("Меню управления очередью:\n");
							switch (currentSelect)
							{
							case 1:
								printf("=> 1. Добавить элемент\n   2. Вывести очередь\n   3. Считать первый элемент\n   4. Проверить очередь на пустоту\n   5. Получить размер очереди\n   6. Удалить первый элемент из очереди");
								break;
							case 2:
								printf("   1. Добавить элемент\n=> 2. Вывести очередь\n   3. Считать первый элемент\n   4. Проверить очередь на пустоту\n   5. Получить размер очереди\n   6. Удалить первый элемент из очереди");
								break;
							case 3:
								printf("   1. Добавить элемент\n   2. Вывести очередь\n=> 3. Считать первый элемент\n   4. Проверить очередь на пустоту\n   5. Получить размер очереди\n   6. Удалить первый элемент из очереди");
								break;
							case 4:
								printf("   1. Добавить элемент\n   2. Вывести очередь\n   3. Считать первый элемент\n=> 4. Проверить очередь на пустоту\n   5. Получить размер очереди\n   6. Удалить первый элемент из очереди");
								break;
							case 5:
								printf("   1. Добавить элемент\n   2. Вывести очередь\n   3. Считать первый элемент\n   4. Проверить очередь на пустоту\n=> 5. Получить размер очереди\n   6. Удалить первый элемент из очереди");
								break;
							case 6:
								printf("   1. Добавить элемент\n   2. Вывести очередь\n   3. Считать первый элемент\n   4. Проверить очередь на пустоту\n   5. Получить размер очереди\n=> 6. Удалить первый элемент из очереди");
								break;
							}
						}
						counter = 0;
					}
				}
		}
	}
	isError = false;
	switch (currentSelect)
	{
	case 1:
	{
		clean();
		int data = 0, err = 0;
		do
		{
			if (count > 2)
			{
				printf("Очередь переполнена.\n");
				full = 1;
				err = 2;
				system("pause");
				break;
			}
			else
			{
				full = 0;
				count += 1;
				err = 0; // Очистка переменной отвечающей за наличие ошибок (если ошибки будут, программа задаст значание позже)
				printf("Введите число для добавления в очередь: ");
				clean_stdin(); // Очистить буфер ввода 
				if (scanf("%i[0-9]", &data) == 1) {} // Проверка ввел ли пользователь буквы или цифры
				else
				{
					printf("Буквы.\n");
					err = 1; // Произошла ошибка.
				}
				if (data > 1000 || data < -1000 && err == 0) // Проверка введенного числа на вхождение в допустимый диапазон вводимых чисел
				{
					printf("Введенное число не входит в допустимый диапазон вводимыъ чисел!\nДопустимый диапазон: от -1000 до 1000\n");
					err = 1; // Произошла ошибка.
				}
			}
		} while (err == 1); // Повторять пока есть ошибка
		if (full == 0)
			insert(data);
		clean();
		if (full == 0)
		{
			printf("Операция выполнена успешно, нажмите любую клавишу для продолжения...");
			getch();
		}
		break;
	}
	case 2:
	{
		clean();
		if (!isEmpty())
		{
			int temp = 0;
			/*int removedNum = removeData();
			count = count - 1;
			full = 0;
			printf("Элемент '%i' удален из очереди, нажмите любую клавишу для продолжения...", removedNum);*/
			printf("Текущее состояние очереди: ");
			for (int j = 0; j < 3; j++)
			{
				temp = fullList(j);
				if (j == 0)
					printf("%i", temp);
				else
					printf(", %i", temp);
			}
			printf("\n");
			getch();
			break;
		}
		if (isEmpty())
		{
			printf("Очередь пустая!");
			getch();
			break;
		}
		getch();
		break;
	}
	case 3:
	{
		clean();
		int front = peek();
		if (!isEmpty()) {
			printf("Первый элемент: %i", front);
			int removedNum = removeData();
			count = count - 1;
			full = 0;
			printf("Элемент '%i' удален из очереди, нажмите любую клавишу для продолжения...", removedNum);
		}
		else
			printf("Очередь пустая!");
		//removeData();
		count = count - 1;
		full = 0;
		getch();
		break;
	}
	case 4:
		{
		clean();
		if (isEmpty())
			printf("Очередь пустая!");
		else
			printf("Очередь не пустая!");
		getch();
		break;
		}
	case 5:
		{
		clean();
		int queueSize = size();
		printf("Размер очереди: %i", queueSize);
		getch();
		break;
		}

	case 6:
		{
		clean();
		if (!isEmpty())
		{
			int temp = 0;
			int removedNum = removeData();
			count = count - 1;
			full = 0;
			printf("Элемент '%i' удален из очереди, нажмите любую клавишу для продолжения...", removedNum);
			getch();
			break;
		}
		if (isEmpty())
		{
			printf("Очередь пустая!");
			getch();
			break;
		}
		getch();
		break;
		}
	default:
	{

		break;
	}
	}
}
}

