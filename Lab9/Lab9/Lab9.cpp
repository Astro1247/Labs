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
	char str[200], str1[200], str2[200]; //������ ��� �������� ������ �������� �����
	char name[54];
	int i, k = 0, m, x, m1 = 0, m2 = 0, m3 = 0;//������� 
	int sizeStr;//���������� ��� �������� �������� ����� ��������
	setlocale(LC_ALL, "Rus");
	printf("������� ��� �������� �����: ");
	//scanf("%s", &name);

	x = strlen(name);


	fp = fopen("C:\\Users\\AstroNB\\Source\\Repos\\Labs\\Lab9\\Debug\\input.txt", "r"); //��������� ������� ���� � ������ "������"
	if (fp == NULL) {
		printf("He ���� ������� ���� \n"); // ����������� ����������� if-else ��� ��������� ���������� ���������
		system("pause");
		return 0;
	}
	else
	{
		char * tmp[1000];
		while (!feof(fp))
		{
			fgets(tmp, 100, fp);//���������������� ����� fp � ������ str
		}
		//char * tmp = "This is a test and and another test";
		printf("���������  ������: %s\n", tmp);
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
		printf("���������� ������: %s\n", new_phrase);
		fclose(fp); //��������� ����
		fp = fopen("C:\\Users\\AstroNB\\Source\\Repos\\Labs\\Lab9\\Debug\\output.txt", "w+");
		fprintf(fp, new_phrase);
		fclose(fp); //��������� ����
		return 0;
	}
}

