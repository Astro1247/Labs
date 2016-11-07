#include "stdafx.h"
#include "locale.h"

void clean_stdin()
{
	fflush(stdin);
	fseek(stdin, 0, SEEK_END);
}

void func1()
{
	long long size = 0;
	int err, x = 0;
	do
	{
		system("cls");
		err = 0;
		printf("Введите размер массива: ");
		clean_stdin();
		//scanf("%i", &size);
		fseek(stdin, 0, SEEK_END);
		if (scanf("%i[0-9]", &size) == 1) {}
		else
		{
			printf("Буквы.\n");
			err = 1;
		}
		if (size > 50 || size < 1 && err != 1)
		{
			printf("Превышен лимит\n");
			err = 1;
		}
		printf("%i\n", size);
	} while (err == 1);
	int *A = (int*)malloc(size * sizeof(int));
	int *B = (int*)malloc(size * sizeof(int));
	int *C = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++)
	{
		do
		{
			printf("Введите %i элемент массива A: ", i + 1);
			clean_stdin();
			err = 0;
			//scanf("%i", &A[i]);
			clean_stdin();
			fseek(stdin, 0, SEEK_END);
			if (scanf("%i[0-9]", &A[i]) == 1) {}
			else
			{
				printf("Буквы.\n");
				err = 1;
			}
			if (A[i] > 1000 || A[i] < -1000 && err != 1)
			{
				printf("Превышен лимит\n");
				err = 1;
			}
		} while (err == 1);
	}
	system("cls");
	for (int i = 0; i < size; i++)
	{
		do
		{
			printf("Введите %i элемент массива B: ", i + 1);
			clean_stdin();
			fseek(stdin, 0, SEEK_END);
			err = 0;
			if (scanf("%i[0-9]", &B[i]) == 1) {}
			else
			{
				printf("Буквы.\n");
				err = 1;
			}
			if (B[i] > 1000 || B[i] < -1000 && err != 1)
			{
				printf("Превышен лимит\n");
				err = 1;
			}
		} while (err == 1);
	}
	system("cls");
	for (int i = 0; i < size; i++)
	{
		printf("A[%i]=%i \t B[%i]=%i\n", i, A[i], i, B[i]);
	}
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (A[i] == B[j])
				break;
			else if (j == size - 1)
			{
				C[k] = A[i];
				k++;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (C[i] > -1000 && C[i] < 1000)
			printf("Элемент массива C[%i]: %i\n", i, C[i]);
	}
	printf("Сортировка массива . . . \n");
	int temp;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			if (C[j] > C[j + 1])
			{
				temp = C[j];
				C[j] = C[j + 1];
				C[j + 1] = temp;
			}
		}
	}
	printf("Отсортированный массив:\n");
	int p = 0;
	for (int i = 0; i < size; i++)
	{
		if (C[i] > -1000 && C[i] < 1000)
		{
			printf("Элемент массива C[%i]: %i\n", p, C[i]);
			p++;
		}
	}
	system("pause");
}

int main()
{
	char yn;
	setlocale(LC_ALL, "RUS");
	do
	{
		func1();
		printf("Повторить выполнение функции? (Y/N) ");
		clean_stdin();
		scanf("%c", &yn);
		getchar();
	} while (yn == 'y' && yn != 'n');
    return 0;
}