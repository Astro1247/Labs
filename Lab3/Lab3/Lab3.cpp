// Lab3.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	int input1, input2, input3;
	func1:
	printf("������� ����� ��� ��������: ");
	scanf("%d", &input1);
	if (input1 < 0)
	{
		printf("��� ���� ������������� �����.\n");
	}
	else if (input1 > 0)
	{
		printf("��� ���� ������������� �����.\n");
	}
	else
	{
		printf("��� ��� ����.\n");
	}
	printf("��������� ��������? (0 - ���/1 - ��)");
	scanf("%d", &input3);
	if (input3 == 1)
	{
		goto func1;
	}
	getchar();
	func2:
	printf("������� ����� ��� ������ �� ������������� ������: ");
	scanf("%d", &input2);
	printf("������������� ������: ");
	switch (input2)
	{
		case 1:
		{
			printf("!");
			break;
		}
		case 2:
		{
			printf("@");
			break;
		}
		case 3:
		{
			printf("#");
			break;
		}
		case 4:
		{
			printf("$");
			break;
		}
		case 5:
		{
			printf("%%");
			break;
		}
		case 6:
		{
			printf("^");
			break;
		}
		case 7:
		{
			printf("&");
			break;
		}
		case 8:
		{
			printf("*");
			break;
		}
		case 9:
		{
			printf("(");
			break;
		}
		case 0:
		{
			printf(")");
			break;
		}
	}
	printf("\n��������� ��������? (0 - ���/1 - ��)");
	scanf("%d", &input3);
	if (input3 == 1)
	{
		goto func2;
	}
	getchar();
    return 0;
}

