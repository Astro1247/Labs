#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "stdafx.h"
#include "locale.h"
#include "conio.h"
#include <Windows.h>

int main() {
	int i, j;		//��������
	int i1, i2, menuPoint = 0, yn;	//���������� ����������
	char str_1[100], str_2[100], str_3[100];  //�������� ������ 
	char symbol; //��������� ������
	setlocale(LC_ALL, "RUS");

	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
	i2 = 1;
	do {
		printf("�������� ��������:\n1. �������� ���������� ������� �� ��������� ������\n2. ��������� ���� �����\n3. ����� �� ���������\n��� �����: ");
		menuPoint = _getch();
		do
		{
			switch (menuPoint)
			{
			case 49:
			{
				system("cls");
				do {
					printf("������� ������ (�������, ��������� �� ������ 100 �������� ����� ���������������): ");
					fseek(stdin, 0, SEEK_END);
					str_1[0] = "\0";
					fgets(str_1, sizeof str_1, stdin);
					printf("������� ������ ������� ��������� �������: ");
					symbol = _getch();
					printf("\n��������� ������= %c\n", symbol);  // �������� �� ������ str_1 ���� ��������� ������� (symbol)
					i = 0;          // ������ ��� �������� ������
					j = i;          // ������ ��� ���������������� ������
									// ���� ����������� �������� ������
					while (str_1[i])// ���� � ������ �� ������� ����
					{
						// ��������� ������� ������ ������
						if (str_1[i] != symbol)    // ���� str_1[i] �� ����� (symbol) ���������� ������� ������ ������ �� ������ ������� j
							str_1[j++] = str_1[i]; // ��������� ������ j �������
						i++;                       // ��������� ������ i �� �������
					}
					str_1[j] = '\0';              //������ �������� ����� � ����� ���������������� ������
					printf("���������: %s", str_1);//����� ����������
					printf("\n��������� ���������� �������? (���� �� ������� 1)");	//��������� ��������?
					yn = _getch();
					system("cls");	//�������� ������
				} while (yn == 49);
				break;
			}
			case 50:
			{
				system("cls");
				do
				{
					printf("������� ������ ��� ���������\n");
					printf("������� ������ 1: ");
					fseek(stdin, 0, SEEK_END);
					fgets(str_2, sizeof str_1, stdin);	//���� 1 ������ ��� ���������
					printf("������� ������ 2: ");
					fseek(stdin, 0, SEEK_END);
					fgets(str_3, sizeof str_1, stdin);	//���� 2 ������ ��� ���������
					printf("������ 1:%s������ 2:%s", str_2, str_3);	//����� 1 � 2 ������
					if (strcmp(str_2, str_3))							  //��������� �����
						printf("������ ������");
					else
						printf("������ ����������");
					printf("\n��������� ���������� �������? (���� �� ������� 1)");	//������ ��������?
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
				system("cls");
				printf("�������� ���� ��������� �������\n"); //�������� �����
				break;
			}
			}
		} while (menuPoint == 0);
	} while (i2);
	return 0;
}
