#include "stdafx.h"		
#include "stdlib.h"
#include "math.h"																	 
#include "locale.h"																	 															 


int main()
{
	int s, f, i, temp, a = 1, numb, ik;
	char yn;
	setlocale(LC_ALL, "RUS");
	do
	{
		printf("���������� ����� ����� S: ");
		scanf("%i", &numb);
		getchar();
		s = 0;
		f = 0;
		while (s < numb)
		{
			f = f + 1;
			s = s + f;
			printf("�������� �� ���������� ������� S<%i...\nS= %i\n", numb, s);
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
		ik = 0;
		i = 0;
		a = 1;
		printf("������� ����� �� ������ �����������? i=");
		scanf(" %i", &ik);
		getchar();
		int *input = new int[ik];
		do
		{
			printf("������� ����� %i: ", i+1);
			scanf("%d", &input[i]);
			a = a * input[i];
			i += 1;
		} while (i < ik);
		printf("��������� ��������� ���������� �����: %i\n", a);
		printf("���������? (Y/N)");
		scanf(" %c", &yn);
	} while (yn == 'y' && yn != 'n');
	return 0;
}

