#include "stdafx.h"															 
#include "math.h"																	 
#include "locale.h"																	 															 


int main()
{
	setlocale(LC_ALL, "RUS");
	int s, f, input[5], i, temp, a = 1;
	char yn;
	do
	{
		s = 0;
		f = 0;
		do
		{
			f = f + 1;
			s = s + f;
			printf("�������� �� ���������� ������� S<50...\nS= %i\n", s);
		} while (s < 50);
		printf("��������� �����..\n");
		printf("������ S ����� %i\n", s);
		printf("���������? (Y/N)");
		scanf(" %c", &yn);
	}  while (yn == 'y' && yn != 'n');
	printf("������� ENTER ����� ���������� . . .\n");
	getchar();
	do
	{
		for (i = 0; i < 5; i++)
		{
			printf("������� ����� %i: ", i+1);
			scanf("%d", &input[i]);
			a = a * input[i];
		}
		printf("��������� ��������� ���������� �����: %i\n", a);
		printf("���������? (Y/N)");
		scanf(" %c", &yn);
	} while (yn == 'y' && yn != 'n');
	return 2;
}

