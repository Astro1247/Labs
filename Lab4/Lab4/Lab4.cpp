// Lab4.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"																	 
#include "conio.h"																	 
#include "math.h"																	 
#include "locale.h"																	 
#include "string.h"																	 
																					 
																					 
int main()																			 
{
	setlocale(LC_ALL, "RUS");
	int s = 0;																		 
	do																				 
	{
		printf("S ������ 50, ����������� S �� 1... (S=%i)\n", s);
		s = s + 1;
		printf("�������� �� ���������� ������� S<50...\n");
	} while (s < 50);
	printf("��������� �����..\n");
	printf("������ S ����� %i\n", s);
	printf("������� ENTER ����� ���������� . . .\n");
	getchar();
	//123
	return 0;
}

