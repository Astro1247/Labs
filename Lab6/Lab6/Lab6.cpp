#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "stdafx.h"
#include "locale.h"

int main() {
	int i, j, menuPoint;
	char str_1[100], str_2[100], str_3[100];  //�������� ������ 
	char symbol, YN; //��������� ������
	setlocale(LC_ALL, "RUS");
	printf("�������� ��������:\n1. �������� ���������� ������� �� ��������� ������\n2. ��������� ���� �����");
	scanf("%d", &menuPoint);
	switch (menuPoint)
	{
	case 1:
	{
		do {
			printf("������� ������: ");
			gets(str_1);	// ���� ������
			printf("������� ������ ������� ��������� �������: ");
			scanf("%c", &symbol);
			getchar();
			                // �������� �� ������ s ���� ��������� ������� (c)
			i = 0;          // ������ ��� �������� ������
			j = i;          // ������ ��� ���������������� ������
				            // ���� ����������� �������� ������
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
			scanf("%c", &YN);
			getchar();
		} while (YN == 'y' || YN == 'Y');
	}
	case 2:
	{
		do
		{
			printf("������� ������ ��� ���������:\n");
			printf("\n1: ");
			gets(str_2);
			printf("\n2: ");
			gets(str_3);
			if (strcmp(str_2, str_3))
				printf("������ ������");
			else
				printf("������ ����������");
			printf("��������� ���������� �������? (Y/N)");
			scanf("%c", &YN);
			getchar();
		} while (YN == 'y' || YN == 'Y');
	}
	}
	system("pause");
	return 0;
}