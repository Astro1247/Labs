#include "stdafx.h"		
#include "stdlib.h"
#include "math.h"																	 
#include "locale.h"																	 															 


int main()
{
	int s, n, n1, k, f, input[5], i, temp, a = 1;
	char yn;
	setlocale(LC_ALL, "RUS");
	do
	{	
		s = 0;
		f = 0;
		printf("������� �����: ");
		scanf("%i",&n);
		while (s < n)
		{
			f = f + 1;
			s = s + f;
			printf("�������� �� ���������� ������� S<%i...\nS= %i\n",n,s);
		}
		printf("��������� �����..\n");
		printf("������ S ����� %i\n", s);
		printf("���������? (Y/N)");
		scanf(" %c", &yn);
	}  while (yn == 'y' && yn != 'n');
	printf("������� ENTER ����� ���������� . . .\n");
	getchar();
	system("cls");
	do
	{
		i = 0;
		printf("������� ���������� ���������� �����: ");
		scanf("%i",&n1);
		do
		{
			printf("������� ����� %i: ", i+1);
			scanf("%i", &k);
			a = a * k;
			i = i + 1;
		} while (i < n1);
		printf("��������� ��������� ���������� �����: %i\n", a);
		printf("���������? (Y/N)");
		scanf(" %c", &yn);
	} while (yn == 'y' && yn != 'n');
	return 0;
}

