#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "stdafx.h"
#include "locale.h"

int main() {
	int i, j, pov = 0;
	char str_1[100], str_2[100], str_3[100];  //исходная строка 
	char symbol; //удаляемый символ
	setlocale(LC_ALL, "rus");
	do {
		printf("Введите строку : ");
		//scanf("%s",&str_1);
		gets(str_1);	//вывод строки
		printf("\nВведите символ который требуется удалить :");
		scanf("%c", &symbol);
		getchar();
		//Удаление из строки s всех вхождений символа (c)
		i = 0;//индекс для исходной строки
		j = i;//индекс для модифицированной строки

			  //цикл модификации исходной строки
		while (str_1[i])//пока в строке не нулевой байт
		{
			//проверить текущий символ строки
			if (str_1[i] != symbol) //если s[i] не равен (c) переписать текущий символ строки по новому индексу j
				str_1[j++] = str_1[i]; // и  увеличить индекс j единицу
			i++;// и увеличить индекс i на единицу
		}
		str_1[j] = '\0';//запись нулевого байта в конец модифицированной строки

		printf("строка :%s\n", str_1);//вывод результата
		printf("Если хотите повторить введите 1, если нет введите 0 :");
		scanf("%i", &pov);
		getchar();
	} while (pov != 0);

	printf("Введите строчки для сравнения :\n ");
	printf("\n1 :");
	gets(str_2);
	printf("\n2 :");
	gets(str_3);

	if (strcmp(str_2, str_3) == 0)
		printf("Рядок %s дорівнює рядку %s", str_2, str_3);
	else
		if (str_2>str_3)
			printf("Рядок %s > %s\n", str_2, str_3);
		else
			printf("Рядок %s < %s\n", str_2, str_3);

	system("pause");

	return 0;
}