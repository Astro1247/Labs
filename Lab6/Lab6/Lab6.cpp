#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "stdafx.h"
#include "locale.h"

int main() {
	int i, j, pov = 0;
	char str_1[100], str_2[100], str_3[100];  //�������� ������ 
	char symbol; //��������� ������
	setlocale(LC_ALL, "rus");
	do {
		printf("������� ������ : ");
		//scanf("%s",&str_1);
		gets(str_1);	//����� ������
		printf("\n������� ������ ������� ��������� ������� :");
		scanf("%c", &symbol);
		getchar();
		//�������� �� ������ s ���� ��������� ������� (c)
		i = 0;//������ ��� �������� ������
		j = i;//������ ��� ���������������� ������

			  //���� ����������� �������� ������
		while (str_1[i])//���� � ������ �� ������� ����
		{
			//��������� ������� ������ ������
			if (str_1[i] != symbol) //���� s[i] �� ����� (c) ���������� ������� ������ ������ �� ������ ������� j
				str_1[j++] = str_1[i]; // �  ��������� ������ j �������
			i++;// � ��������� ������ i �� �������
		}
		str_1[j] = '\0';//������ �������� ����� � ����� ���������������� ������

		printf("������ :%s\n", str_1);//����� ����������
		printf("���� ������ ��������� ������� 1, ���� ��� ������� 0 :");
		scanf("%i", &pov);
		getchar();
	} while (pov != 0);

	printf("������� ������� ��� ��������� :\n ");
	printf("\n1 :");
	gets(str_2);
	printf("\n2 :");
	gets(str_3);

	if (strcmp(str_2, str_3) == 0)
		printf("����� %s ������� ����� %s", str_2, str_3);
	else
		if (str_2>str_3)
			printf("����� %s > %s\n", str_2, str_3);
		else
			printf("����� %s < %s\n", str_2, str_3);

	system("pause");

	return 0;
}