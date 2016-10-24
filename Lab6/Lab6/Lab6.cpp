#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "stdafx.h"
#include "locale.h"
#include "conio.h"

int main() {
	int i, j, menuPoint=0;
	char str_1[100], str_2[100], str_3[100],s;  //исходная строка 
	char symbol, yn; //удаляемый символ
	setlocale(LC_ALL, "RUS");
	printf("Выберите алгоритм:\n1. Удаление требуемого символа из введенной строки\n2. Сравнение двух строк\nВаш выбор: ");
	menuPoint=_getch();//scanf("%d", &menuPoint);
	//getchar();
	do
	{
		switch (menuPoint)
		{
		case 49:
		{
			system("cls");
			do {
				printf("Введите строку: ");
				fgets(str_1, 100, stdin);	// Ввод строки
					//getchar();
				if (sizeof(str_1) / sizeof(char*) > 100)
				{
					printf("\nToo big dick\n");
					break;
				}
				printf("Введите символ который требуется удалить: ");
				scanf("%c", &symbol);
				printf("\nsymbol= %d",symbol);
				getchar();
				// Удаление из строки s всех вхождений символа (c)
				i = 0;          // Индекс для исходной строки
				j = i;          // Индекс для модифицированной строки
								// Цикл модификации исходной строки
				printf("\nstr_1= %s", str_1);
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
				scanf("%c", &yn);
				getchar();
			} while (yn == 'y' || yn == 'Y');
			break;
		}
		case 50:
		{
			system("cls");
			do
			{
				printf("Введите строки для сравнения:\n");
				printf("\n1: ");
				gets(str_2);										  //Получение строки 1
				printf("\n2: ");
				gets(str_3);										  //Получение строки 2
				if (strcmp(str_2, str_3))							  //Сравнение строк
					printf("Строки разные");
				else
					printf("Строки одинаковые");
				printf("Повторить выполнение функции? (Y/N)");
				scanf("%c", &yn);
				getchar();
			} while (yn == 'y' || yn == 'Y');
			break;
		}
		default:
		{
			printf("\nUnknown exception (0x0)\n");
			break;
		}
		}
	} while (menuPoint == 0);
	system("pause");
	return 0;
}