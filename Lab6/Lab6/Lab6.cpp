#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "stdafx.h"
#include "locale.h"

int main() {
	int i, j, menuPoint;
	char str_1[100], str_2[100], str_3[100];  //исходная строка 
	char symbol, YN; //удаляемый символ
	setlocale(LC_ALL, "RUS");
	printf("Выберите алгоритм:\n1. Удаление требуемого символа из введенной строки\n2. Сравнение двух строк");
	scanf("%d", &menuPoint);
	switch (menuPoint)
	{
	case 1:
	{
		do {
			printf("Введите строку: ");
			gets(str_1);	// Ввод строки
			printf("Введите символ который требуется удалить: ");
			scanf("%c", &symbol);
			getchar();
			                // Удаление из строки s всех вхождений символа (c)
			i = 0;          // Индекс для исходной строки
			j = i;          // Индекс для модифицированной строки
				            // Цикл модификации исходной строки
			while (str_1[i])// Пока в строке не нулевой байт
			{
				                           // Проверить текущий символ строки
				if (str_1[i] != symbol)    // Если s[i] не равен (c) переписать текущий символ строки по новому индексу j
					str_1[j++] = str_1[i]; // Увеличить индекс j единицу
				i++;                       // Увеличить индекс i на единицу
			}
			str_1[j] = '\0';              //Запись нулевого байта в конец модифицированной строки
			printf("Строка: %s\n", str_1);//Вывод результата
			printf("Повторить выполнение функции? (Y/N)");
			scanf("%c", &YN);
			getchar();
		} while (YN == 'y' || YN == 'Y');
	}
	case 2:
	{
		do
		{
			printf("Введите строки для сравнения:\n");
			printf("\n1: ");
			gets(str_2);
			printf("\n2: ");
			gets(str_3);
			if (strcmp(str_2, str_3))
				printf("Строки разные");
			else
				printf("Строки одинаковые");
			printf("Повторить выполнение функции? (Y/N)");
			scanf("%c", &YN);
			getchar();
		} while (YN == 'y' || YN == 'Y');
	}
	}
	system("pause");
	return 0;
}