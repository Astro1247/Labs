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
			//printf("S ������ 50, ����������� S �� 1... (S=%i)\n", s);
			s = s + f;
			printf("�������� �� ���������� ������� S<50...\nS= %i\n", s);
		} while (s < 50);
		printf("��������� �����..\n");
		printf("������ S ����� %i\n", s);
		/*printf("���������? (y/n)\n");
		scanf(" %c", &yn);
		if (yn == 'n' || yn == 'N')
		{
			goto func2;
		}
		else if (yn == 'Y' || yn == 'y')
		{
			goto func1;
			printf("\n");
		}
		else
		{
			printf("������������ ����.\n");
			goto check1;
		}*/
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

