#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "stdafx.h"
#include "locale.h"
#include "conio.h"
#include<Windows.h>

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
					fflush(stdin);
					i1 = 1;
					do {
						printf("\n������� ������: ");
						fflush(stdin);
						str_1 == NULL;
						gets(str_1);
						if (strlen(str_1) > 100) {
							system("cls");
							printf("������� ������� ������ ��������� ����\n");
						}
						else i1 = 0;
					} while (i1);
					printf("\n������� ������ ������� ��������� �������: ");
					symbol = _getch();
					fflush(stdin);
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
					printf("\n���������: %s\n", str_1);//����� ����������
					printf("��������� ���������� �������? (���� �� ������� 1)");	//��������� ��������?
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
					printf("������� ������ ��� ���������:\n");
					do {
						printf("\n������� ������1: ");
						fflush(stdin);
						gets(str_2);	//���� 1 ������ ��� ���������
						if (strlen(str_2) > 100) {	//�������� �� ����� ������
							system("cls");
							printf("\n\t������ ������� ������� ��������� ���� ");
						}
						else i1 = 0;
					} while (i1);
					i1 = 1;
					do {
						printf("������� ������2: ");
						fflush(stdin);
						gets(str_3);	//���� 2 ������ ��� ���������
						if (strlen(str_3) > 100) {	//�������� �� ����� ������
							system("cls");
							printf("\n\t������ 2 ������� ������� ��������� ���� \n");
						}
						else i1 = 0;
					} while (i1);
					printf("\n������ 1:%s\n������ 2:%s\n", str_2, str_3);	//����� 1 � 2 ������
					if (strcmp(str_2, str_3))							  //��������� �����
						printf("\n������ ������");
					else
						printf("\n������ ����������");
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
				printf("\n�������� ���� ��������� �������\n"); //�������� �����
				system("cls");
				break;
			}
			}
		} while (menuPoint == 0);
	} while (i2);
	return 0;
}
