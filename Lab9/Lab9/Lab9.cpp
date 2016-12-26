#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "math.h"
#include "string.h"
#include "locale.h"
#include "windows.h"

#define MAXPHRASELEN 1000
#define MAXTOKLEN 100


int main()
{
	FILE *fp;//file In
	char str[200], str1[200], str2[200]; //массив для хранения данных входного файла
	char name[54];
	int i, k = 0, m, x, m1 = 0, m2 = 0, m3 = 0;//счётчик 
	int sizeStr;//переменная для хранения значений длины массивов
	setlocale(LC_ALL, "Rus");
	printf("Введите имя входного файла: ");
	//scanf("%s", &name);

	x = strlen(name);


	fp = fopen("C:\\Users\\AstroNB\\Source\\Repos\\Labs\\Lab9\\Debug\\input.txt", "r"); //открываем входной файл в режиме "чтение"
	if (fp == NULL) {
		printf("He могу открыть файл \n"); // стандратная конструкция if-else для валидного выполнения программы
		system("pause");
		return 0;
	}
	else
	{
		char * tmp[1000];
		while (!feof(fp))
		{
			fgets(tmp, 100, fp);//записываемданные файла fp в массив str
		}
		//char * tmp = "This is a test and and another test";
		printf("Начальная  строка: %s\n", tmp);
		char phrase[1000];
		strcpy(phrase, tmp);
		char new_phrase[1000];
		char * lasttok = malloc(1000);
		char * tok = malloc(1000);
		new_phrase[0] = '\0';
		lasttok[0] = '\0';
		lasttok = strtok(phrase, " ");
		if (lasttok != NULL) {
			strcat(new_phrase, lasttok);
			strcat(new_phrase, " ");
			while ((tok = strtok(NULL, " ")) != NULL) {
				if (strcmp(tok, lasttok) != 0) {
					strcat(new_phrase, tok);
					strcat(new_phrase, " ");
					lasttok = tok;
				}
			}
		}
		printf("Полученная строка: %s\n", new_phrase);
		fclose(fp); //закрываем файл
		fp = fopen("C:\\Users\\AstroNB\\Source\\Repos\\Labs\\Lab9\\Debug\\output.txt", "w+");
		fprintf(fp, new_phrase);
		fclose(fp); //закрываем файл
		return 0;
	}
}

