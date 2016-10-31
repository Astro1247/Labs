#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "stdafx.h"
#include "locale.h"
#include "conio.h"
#include<Windows.h>

int main() {
	int i, j;		//Счетчики
	int i1, i2, menuPoint = 0, yn;	//Управление программой
	char str_1[100], str_2[100], str_3[100];  //исходные строки 
	char symbol; //удаляемый символ
	setlocale(LC_ALL, "RUS");

	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	i2 = 1;
	do {
		printf("Выберите алгоритм:\n1. Удаление требуемого символа из введенной строки\n2. Сравнение двух строк\n3. Выход из программы\nВаш выбор: ");
		menuPoint = _getch();
		do
		{
			switch (menuPoint)
			{
			case 49:
			{
				system("cls");
				do {
					fflush(stdin);
					i1 = 1;
					do {
						printf("\nВведите строку: ");
						fflush(stdin);
						str_1 == NULL;
						gets(str_1);
						if (strlen(str_1) > 100) {
							system("cls");
							printf("Слишком длинная строка повторите ввод\n");
						}
						else i1 = 0;
					} while (i1);
					printf("\nВведите символ который требуется удалить: ");
					symbol = _getch();
					fflush(stdin);
					printf("\nУдаляемый символ= %c\n", symbol);  // Удаление из строки str_1 всех вхождений символа (symbol)
					i = 0;          // Индекс для исходной строки
					j = i;          // Индекс для модифицированной строки
									// Цикл модификации исходной строки
					while (str_1[i])// Пока в строке не нулевой байт
					{
						// Проверить текущий символ строки
						if (str_1[i] != symbol)    // Если str_1[i] не равен (symbol) переписать текущий символ строки по новому индексу j
							str_1[j++] = str_1[i]; // Увеличить индекс j единицу
						i++;                       // Увеличить индекс i на единицу
					}
					str_1[j] = '\0';              //Запись нулевого байта в конец модифицированной строки
					printf("\nРезультат: %s\n", str_1);//Вывод результата
					printf("Повторить выполнение функции? (Если да нажмите 1)");	//Повторить операцию?
					yn = _getch();
					system("cls");	//Очищение єкрана
				} while (yn == 49);
				break;
			}
			case 50:
			{
				system("cls");
				do
				{
					printf("Введите строки для сравнения:\n");
					do {
						printf("\nВведите строку1: ");
						fflush(stdin);
						gets(str_2);	//Ввод 1 строки для сравнения
						if (strlen(str_2) > 100) {	//Проверка на длину строки
							system("cls");
							printf("\n\tСтрока слишком большая повторите ввод ");
						}
						else i1 = 0;
					} while (i1);
					i1 = 1;
					do {
						printf("Введите строку2: ");
						fflush(stdin);
						gets(str_3);	//Ввод 2 строки для сравнения
						if (strlen(str_3) > 100) {	//Проверка на длину строки
							system("cls");
							printf("\n\tСтрока 2 слишком большая повторите ввод \n");
						}
						else i1 = 0;
					} while (i1);
					printf("\nСтрока 1:%s\nСтрока 2:%s\n", str_2, str_3);	//Вывод 1 и 2 строки
					if (strcmp(str_2, str_3))							  //Сравнение строк
						printf("\nСтроки разные");
					else
						printf("\nСтроки одинаковые");
					printf("\nПовторить выполнение функции? (Если да введите 1)");	//Повтор операции?
					yn = _getch();
					system("cls");
				} while (yn == 49);
				break;
			}
			case 51: {
				return 0;
			}
			default:
			{
				printf("\nНеверный ввод повторите попытку\n"); //Неверный выбор
				system("cls");
				break;
			}
			}
		} while (menuPoint == 0);
	} while (i2);
	return 0;
}
