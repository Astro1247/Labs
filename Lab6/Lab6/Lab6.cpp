#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "stdafx.h"
#include "locale.h"
#include "conio.h"
#include<Windows.h>

int main() {
	int i, j, a, menuPoint = 0;
	char str_1[100], str_2[100], str_3[100], s;  //�������� ������ 
	char symbol, yn; //��������� ������
	setlocale(LC_ALL, "RUS");

	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������

	printf("�������� ��������:\n1. �������� ���������� ������� �� ��������� ������\n2. ��������� ���� �����\n��� �����: ");
	menuPoint = _getch();//scanf("%d", &menuPoint);
	//getchar();
	do
	{
		switch (menuPoint)
		{
		case 49:
		{
			system("cls");
			do {
				printf("������� ������: ");
				//fgets(str_1, 100, stdin);	// ���� ������
				gets(str_1);
				a = strlen(str_1);
				if (a > 100) {
					printf("\nbig str\n");
					//getchar();
					break;
				}

				printf("stroka= %s", str_1);
				printf("������� ������ ������� ��������� �������: ");
				fflush(stdin);
				scanf("%c", &symbol);
				//printf("\nsymbol= %�",symbol);
				getchar();
				// �������� �� ������ s ���� ��������� ������� (c)
				i = 0;          // ������ ��� �������� ������
				j = i;          // ������ ��� ���������������� ������
								// ���� ����������� �������� ������
				printf("\nstr_1= %s", str_1);
				while (str_1[i])// ���� � ������ �� ������� ����
				{
					// ��������� ������� ������ ������
					if (str_1[i] != symbol)    // ���� s[i] �� ����� (c) ���������� ������� ������ ������ �� ������ ������� j
						str_1[j++] = str_1[i]; // ��������� ������ j �������
					i++;                       // ��������� ������ i �� �������
				}
				str_1[j] = '\0';              //������ �������� ����� � ����� ���������������� ������
				printf("������: %s\n", str_1);//����� ����������
				printf("��������� ���������� �������? (���� �� ������� 1)");
				scanf("%c", &yn);
				getchar();
			} while (yn == '1');
			break;
		}
		case 50:
		{
			system("cls");
			do
			{
				printf("������� ������ ��� ���������:\n");
				printf("\n1: ");
				gets(str_2);										  //��������� ������ 1
				printf("\n2: ");
				gets(str_3);										  //��������� ������ 2
				if (strcmp(str_2, str_3))							  //��������� �����
					printf("������ ������");
				else
					printf("������ ����������");
				printf("��������� ���������� �������? (Y/N)");
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
