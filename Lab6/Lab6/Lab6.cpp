#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "stdafx.h"
#include "locale.h"
#include "conio.h"

int main() {
	int i, j, menuPoint=0;
	char str_1[100], str_2[100], str_3[100],s;  //�������� ������ 
	char symbol, yn; //��������� ������
	setlocale(LC_ALL, "RUS");
	printf("�������� ��������:\n1. �������� ���������� ������� �� ��������� ������\n2. ��������� ���� �����\n��� �����: ");
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
				printf("������� ������: ");
				fgets(str_1, 100, stdin);	// ���� ������
					//getchar();
				if (sizeof(str_1) / sizeof(char*) > 100)
				{
					printf("\nToo big dick\n");
					break;
				}
				printf("������� ������ ������� ��������� �������: ");
				scanf("%c", &symbol);
				printf("\nsymbol= %d",symbol);
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
				printf("��������� ���������� �������? (Y/N)");
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