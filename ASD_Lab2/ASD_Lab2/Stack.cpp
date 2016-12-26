#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include "stdafx.h"
#include <Windows.h>

#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101

#define INIT_SIZE 2
#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY   -102
#define MULTIPLIER 2

#define STACK_MAX_SIZE 20
typedef int T;
typedef struct Stack_tag {
	T *data;
	size_t size;
	size_t top;
} Stack_t;

Stack_t* createStack(int size) {	//Создание стака
	Stack_t *out = NULL;
	out = malloc(sizeof(Stack_t));
	if (out == NULL) {
		exit(OUT_OF_MEMORY);
	}
	out->size = size;
	out->data = malloc(out->size * sizeof(T));
	if (out->data == NULL) {
		free(out);
		exit(OUT_OF_MEMORY);
	}
	out->top = 0;
	return out;
}

void deleteStack(Stack_t **stack) {
	free((*stack)->data);
	free(*stack);
	*stack = NULL;
}

void resize(Stack_t *stack) {
	stack->size *= MULTIPLIER;
	stack->data = realloc(stack->data, stack->size * sizeof(T));
	if (stack->data == NULL) {
		exit(STACK_OVERFLOW);
	}
}

void push(Stack_t *stack, T value) {		//Вставка елемента в стак
	if (stack->top >= stack->size) {
		resize(stack);
	}
	stack->data[stack->top] = value;
	stack->top++;
	stack->size++;
}

T pop(Stack_t *stack) {				//Удаление последнего елемента из стака
	if (stack->top == 0) {
		exit(STACK_UNDERFLOW);
	}
	stack->top--;
	stack->size--;
	return stack->data[stack->top];
}

T peek_(const Stack_t *stack) {
	if (stack->top <= 0) {
		exit(STACK_UNDERFLOW);
	}
	return stack->data[stack->top - 1];
}

void printStackValue(const T value) {	//Печать значение стака
	printf("%d", value);
}

void printStack(const Stack_t *stack, void(*printStackValue)(const T)) {	//Печать стака
	int i;
	int len = stack->size - 1;
	printf("стек %d > ", stack->size - 1);
	for (i = 0; i < len; i++) {
		printStackValue(stack->data[i]);
		printf("  ");
	}
	/*if (stack->size != 0) {
	printStackValue(stack->data[i]);
	}*/
	printf("\n");
}

void printStack1(const Stack_t *stack, void(*printStackValue)(const T)) {	//Печать стака
	int i;
	int len = stack->size - 1;
	printf("stack %d > ", stack->size - 1);
	for (i = 0; i < len; i++) {
		if (i == 0) {
			printStackValue(stack->data[i]);
		}
	}
	/*if (stack->size != 0) {
	printStackValue(stack->data[i]);
	}*/
	printf("\n");
}

void clean_stdin_() // Функция очистки буфера ввода с клавиатуры
{
	fflush(stdin);
	fseek(stdin, 0, SEEK_END);
}

int getInt() {
	int err, a;
	do
	{
		err = 0; // Очистка переменной отвечающей за наличие ошибок (если ошибки будут, программа задаст значание позже)
		printf("\nВведите  єлемент ");
		clean_stdin_(); // Очистить буфер ввода 
		if (scanf("%i[0-9]", &a) == 1) {} // Проверка ввел ли пользователь буквы или цифры
		else
		{
			printf("Вы ввели буквы, повторите ввод");
			err = 1; // Произошла ошибка.
		}
		if (a > 10000 || a < -10000) // Проверка введенного числа на вхождение в допустимый диапазон вводимых чисел
		{
			printf("Введенное число не входит в допустимый диапазон\nДопустимый диапазон: -10000 - 10000");
			err = 1; // Произошла ошибка.
		}
	} while (err == 1); // Повторять пока есть ошибка

	return a;
}

int stack_main() {
	int a, b, i, size = 1, error;

	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	/*printf("Введите размер стека");
	scanf("%i",&size);*/
	Stack_t *s = createStack(size);
	int f = s->size;

	do {
		printf("Єлементом сруктуры является точка в пространстве");
		printf("\n\n1) Добавление елемента в стек");
		printf("\n2) Удаление елемента из стека");
		printf("\n3) Чтение первого элемента стека");
		printf("\n4) Проверить на пустоту стек");
		printf("\n5) Получить размер стека");
		printf("\n0) Выйти");

		//printf("\nВведите число : ");
		//scanf("%i[0-9]", &b);
		b = getInt();

		switch (b)
		{
		case 1:
			if (s->size < 4) {
				printf("\nВведите новый єлемент:");
				a = getInt();
				push(s, a);
				printStack(s, printStackValue, f);
				//f--;
				getchar();
			}
			else printf("Стек полн");
			break;
		case 2:
			if (s->size - 1) {
				pop(s);
				f++;
				printStack(s, printStackValue);
			}
			printf("\nСтек пуст");
			break;
		case 3:
			printStack1(s, printStackValue);
			break;
		case 4:
			if (s->size == 1) {
				printf("\nСтек пуст");
			}
			else
				printf("\nСтек не пуст уго размер =%i", s->size - 1);
			break;
		case 5:
			printf("\nРазмер стека=%i", s->size - 1);
			break;
		case 0:
			return 0;
		default:
			break;
		}
	} while (b);

	system("pause");

	return 0;
}
