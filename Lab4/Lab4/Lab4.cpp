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
		while (s < 50)
		{
			f = f + 1;
			s = s + f;
			printf("�������� �� ���������� ������� S<50...\nS= %i\n", s);
		}
		printf("��������� �����..\n");
		printf("������ S ����� %i\n", s);
		printf("���������? (Y/N)");
		scanf(" %c", &yn);
	}  while (yn == 'y' && yn != 'n');
	printf("������� ENTER ����� ���������� . . .\n");
	getchar();
	do
	{
		i = 0;
		do
		{
			printf("������� ����� %i: ", i+1);
			scanf("%d", &input[i]);
			a = a * input[i];
			i = i + 1;
		} while (i < 5);
		printf("��������� ��������� ���������� �����: %i\n", a);
		printf("���������? (Y/N)");
		scanf(" %c", &yn);
	} while (yn == 'y' && yn != 'n');
	return 2;
}

