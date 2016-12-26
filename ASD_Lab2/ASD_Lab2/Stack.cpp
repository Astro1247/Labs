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

Stack_t* createStack(int size) {	//�������� �����
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

void push(Stack_t *stack, T value) {		//������� �������� � ����
	if (stack->top >= stack->size) {
		resize(stack);
	}
	stack->data[stack->top] = value;
	stack->top++;
	stack->size++;
}

T pop(Stack_t *stack) {				//�������� ���������� �������� �� �����
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

void printStackValue(const T value) {	//������ �������� �����
	printf("%d", value);
}

void printStack(const Stack_t *stack, void(*printStackValue)(const T)) {	//������ �����
	int i;
	int len = stack->size - 1;
	printf("���� %d > ", stack->size - 1);
	for (i = 0; i < len; i++) {
		printStackValue(stack->data[i]);
		printf("  ");
	}
	/*if (stack->size != 0) {
	printStackValue(stack->data[i]);
	}*/
	printf("\n");
}

void printStack1(const Stack_t *stack, void(*printStackValue)(const T)) {	//������ �����
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

void clean_stdin_() // ������� ������� ������ ����� � ����������
{
	fflush(stdin);
	fseek(stdin, 0, SEEK_END);
}

int getInt() {
	int err, a;
	do
	{
		err = 0; // ������� ���������� ���������� �� ������� ������ (���� ������ �����, ��������� ������ �������� �����)
		printf("\n�������  ������� ");
		clean_stdin_(); // �������� ����� ����� 
		if (scanf("%i[0-9]", &a) == 1) {} // �������� ���� �� ������������ ����� ��� �����
		else
		{
			printf("�� ����� �����, ��������� ����");
			err = 1; // ��������� ������.
		}
		if (a > 10000 || a < -10000) // �������� ���������� ����� �� ��������� � ���������� �������� �������� �����
		{
			printf("��������� ����� �� ������ � ���������� ��������\n���������� ��������: -10000 - 10000");
			err = 1; // ��������� ������.
		}
	} while (err == 1); // ��������� ���� ���� ������

	return a;
}

int stack_main() {
	int a, b, i, size = 1, error;

	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	/*printf("������� ������ �����");
	scanf("%i",&size);*/
	Stack_t *s = createStack(size);
	int f = s->size;

	do {
		printf("��������� �������� �������� ����� � ������������");
		printf("\n\n1) ���������� �������� � ����");
		printf("\n2) �������� �������� �� �����");
		printf("\n3) ������ ������� �������� �����");
		printf("\n4) ��������� �� ������� ����");
		printf("\n5) �������� ������ �����");
		printf("\n0) �����");

		//printf("\n������� ����� : ");
		//scanf("%i[0-9]", &b);
		b = getInt();

		switch (b)
		{
		case 1:
			if (s->size < 4) {
				printf("\n������� ����� �������:");
				a = getInt();
				push(s, a);
				printStack(s, printStackValue, f);
				//f--;
				getchar();
			}
			else printf("���� ����");
			break;
		case 2:
			if (s->size - 1) {
				pop(s);
				f++;
				printStack(s, printStackValue);
			}
			printf("\n���� ����");
			break;
		case 3:
			printStack1(s, printStackValue);
			break;
		case 4:
			if (s->size == 1) {
				printf("\n���� ����");
			}
			else
				printf("\n���� �� ���� ��� ������ =%i", s->size - 1);
			break;
		case 5:
			printf("\n������ �����=%i", s->size - 1);
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
