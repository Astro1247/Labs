#include "stdafx.h"															 
#include "math.h"																	 
#include "locale.h"																	 															 


int main()
{
	setlocale(LC_ALL, "RUS");
	int s, f, input[4], i, temp;
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
			printf("������� ����� %i: ", i);

			scanf("%d", &input[i]);
		}
		printf("���������? (Y/N)");
		scanf(" %c", &yn);
	} while (yn == 'y' && yn != 'n');
	return 0;
}

