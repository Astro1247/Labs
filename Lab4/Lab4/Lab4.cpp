#include "stdafx.h"															 
#include "math.h"																	 
#include "locale.h"																	 															 


int main()
{
	setlocale(LC_ALL, "RUS");
func1:
	char yn;
	int s = 0;
	do
	{
		printf("S ������ 50, ����������� S �� 1... (S=%i)\n", s);
		s = s + 1;
		printf("�������� �� ���������� ������� S<50...\n");
	} while (s < 50);
	printf("��������� �����..\n");
	printf("������ S ����� %i\n", s);
check1:
	printf("���������? (y/n)\n");
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
	}
func2:

	printf("������� ENTER ����� ���������� . . .\n");
	getchar();
	return 0;
}

