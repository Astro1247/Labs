#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "stdafx.h"
#include "locale.h"
#include "conio.h"
#include<Windows.h>

int main() {
	int i, j, a, i1, menuPoint = 0;
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
				i1 = 1;
				/*gets(str_1);
				a = strlen(str_1);
				if (a > 100) {
				printf("\nbig str\n");
				break;
				}
				fgets(str_1,100,stdin);
				fflush(stdin);*/
				do {
					printf("������� ������: ");

					fflush(stdin);
					scanf("%s", &str_1);
					if (strlen(str_1) > 100)	printf("\n Veri bog str\n");
					else i1 = 0;
				} while (i1 != 0);
				printf("\n������� ������ ������� ��������� �������: ");
				fflush(stdin);
				//free(symbol);
				//symbol = 'a';
				//scanf("%c", &symbol);
				symbol = _getch();
				printf("\nsymbol= %�\n",symbol);
				getchar();
				// �������� �� ������ s ���� ��������� ������� (c)
				i = 0;          // ������ ��� �������� ������
				j = i;          // ������ ��� ���������������� ������
								// ���� ����������� �������� ������
				//printf("\nstr_1= %s", str_1);
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
				system("cls");
			} while (yn == '1');
			break;
		}
		case 50:
		{
			system("cls");
			do
			{
				printf("������� ������ ��� ���������:\n");
				do {
					printf("\n������� ������1: ");
					fflush(stdin);
					scanf("%s", &str_2);
					if (strlen(str_2) > 100) {
						system("cls");
						printf("\n\t������ ������� ������� ��������� ���� ");
					}
					else i1 = 0;
				} while (i1);										  //��������� ������ 1
				i1 = 1;
				do {
					printf("������� ������2: ");
					fflush(stdin);
					scanf("%s", &str_3);
					if (strlen(str_3) > 100) {
						system("cls");
						printf("\n\t������ 2 ������� ������� ��������� ���� \n");
					}
					else i1 = 0;
				} while (i1);				//��������� ������ 2
				printf("\n������ 1:%s\n������ 2:%s\n", str_2,str_3);
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
