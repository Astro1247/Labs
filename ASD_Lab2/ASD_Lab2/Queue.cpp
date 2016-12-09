#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

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
	while (1)
	{
	int menuPoint = 1, currentSelect = 1;
	bool isSwitching = true, isError = 0;
	while (isSwitching == true)
	{
		clean();
		int pressedkey = "";
		printf("Меню управления очередью:\n=> 1. Добавить элемент\n   2. Удалить элемент\n   3. Считать первый элемент\n   4. Проверить очередь на пустоту\n   5. Получить размер очереди\n");
		//while (pressedkey != '\r')
		{
			int pressedkey;
			int i = 0;
			int counter = 0;
			while (isSwitching)
				if ((pressedkey = getch()) != -1)
				{
					counter += 1;
					//printf("%i\n", pressedkey);
					if (pressedkey == 80)
					{
						if (menuPoint < 5)
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
								printf("=> 1. Добавить элемент\n   2. Удалить элемент\n   3. Считать первый элемент\n   4. Проверить очередь на пустоту\n   5. Получить размер очереди\n");
								break;
							case 2:
								printf("   1. Добавить элемент\n=> 2. Удалить элемент\n   3. Считать первый элемент\n   4. Проверить очередь на пустоту\n   5. Получить размер очереди\n");
								break;
							case 3:
								printf("   1. Добавить элемент\n   2. Удалить элемент\n=> 3. Считать первый элемент\n   4. Проверить очередь на пустоту\n   5. Получить размер очереди\n");
								break;
							case 4:
								printf("   1. Добавить элемент\n   2. Удалить элемент\n   3. Считать первый элемент\n=> 4. Проверить очередь на пустоту\n   5. Получить размер очереди\n");
								break;
							case 5:
								printf("   1. Добавить элемент\n   2. Удалить элемент\n   3. Считать первый элемент\n   4. Проверить очередь на пустоту\n=> 5. Получить размер очереди\n");
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
		} while (err == 1); // Повторять пока есть ошибка
		insert(data);
		clean();
		printf("Операция выполнена успешно, нажмите любую клавишу для продолжения...");
		getch();
		break;
	}
	case 2:
	{
		clean();
		if (!isEmpty())
		{
			int removedNum = removeData();
			printf("Элемент '%i' удален из очереди, нажмите любую клавишу для продолжения...", removedNum);
			getch();
			break;
		}
		if (isEmpty())
		{
			//error();
			printf("Очередь уже пустая!");
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
		if (!isEmpty())
			printf("Первый элемент: %i", front);
		else
			printf("Очередь пустая!");
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
	default:
	{

		break;
	}
	}
}
}

int queue_example() {
	/* insert 5 items */
	insert(3);
	insert(5);
	insert(9);
	insert(1);
	insert(12);

	// front : 0
	// rear  : 4
	// ------------------
	// index : 0 1 2 3 4 
	// ------------------
	// queue : 3 5 9 1 12
	insert(15);

	// front : 0
	// rear  : 5
	// ---------------------
	// index : 0 1 2 3 4  5 
	// ---------------------
	// queue : 3 5 9 1 12 15

	if (isFull()) {
		printf("Queue is full!\n");
	}

	// remove one item 
	int num = removeData();

	printf("Element removed: %d\n", num);
	// front : 1
	// rear  : 5
	// -------------------
	// index : 1 2 3 4  5
	// -------------------
	// queue : 5 9 1 12 15

	// insert more items
	insert(16);

	// front : 1
	// rear  : -1
	// ----------------------
	// index : 0  1 2 3 4  5
	// ----------------------
	// queue : 16 5 9 1 12 15

	// As queue is full, elements will not be inserted. 
	insert(17);
	insert(18);

	// ----------------------
	// index : 0  1 2 3 4  5
	// ----------------------
	// queue : 16 5 9 1 12 15
	printf("Element at front: %d\n", peek());

	printf("----------------------\n");
	printf("index : 5 4 3 2  1  0\n");
	printf("----------------------\n");
	printf("Queue:  ");

	while (!isEmpty()) {
		int n = removeData();
		printf("%d ", n);
	}
}