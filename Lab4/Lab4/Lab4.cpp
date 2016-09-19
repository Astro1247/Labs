// Lab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"																	 
#include "conio.h"																	 
#include "math.h"																	 
#include "locale.h"																	 
#include "string.h"																	 
																					 
																					 
int main()																			 
{
	setlocale(LC_ALL, "RUS");
	int s = 0;																		 
	do																				 
	{
		printf("S меньше 50, увеличиваем S на 1... (S=%i)\n", s);
		s = s + 1;
		printf("Проверка на выполнение условия S<50...\n");
	} while (s < 50);
	printf("Остановка цикла..\n");
	printf("Сейчас S равен %i\n", s);
	printf("Нажмите ENTER чтобы продолжить . . .\n");
	getchar();
	//123
	return 0;
}

