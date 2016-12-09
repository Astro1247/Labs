// ASD_Lab2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "stdio.h"
#include <time.h>
#include <stdlib.h>
#include "windows.h"
#include "locale.h"
#include <stdbool.h>
#define STACK_MAX_SIZE 100
#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101

void mainMenu(int menuPoint);
void clean();

int main()
{
	setlocale(LC_ALL, "RUS");
	clean();
	mainMenu(0);
	//queue();
	//func1();
	system("pause");
    return 0;
}

int clean_stdin() // Функция очистки буфера ввода с клавиатуры
{
	fflush(stdin);
	fseek(stdin, 0, SEEK_END);
	return 0;
}

void clean()
{
	system("cls");
}

typedef int T;

typedef struct Stack {
	T data[STACK_MAX_SIZE];
	size_t stackSize;
} Stack;
typedef struct Stack Stack;

int Stack_Top(Stack *S)
{
	if (S->stackSize == 0) {
		fprintf(stderr, "Error: stack empty\n");
		return -1;
	}

	return S->data[S->stackSize - 1];
}

void Stack_Push(Stack *S, int d)
{
	if (S->stackSize < STACK_MAX_SIZE)
		S->data[S->stackSize++] = d;
	else
		fprintf(stderr, "Error: stack full\n");
}

void Stack_Pop(Stack *S)
{
	if (S->stackSize == 0)
		fprintf(stderr, "Error: stack empty\n");
	else
		S->stackSize--;
}

int stackSize = 1;

void Stack_Init(Stack *S)
{
	S->stackSize = 0;
}

int func1()
{
	printf("Введите размер стека: ");
	scanf("%i", &stackSize);
	return 0;
}