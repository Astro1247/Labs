// ConsoleApplication12.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <stdio.h>
#include <locale.h>
#include "locale.h"
#include <stdlib.h>

float ff(float n);
void clean_stdin();
int maximum(int ar[], int n);
void func1();
void func2();

int main()
{
	char yn = 'n';
	int menuPoint = 0, error = 0;
	setlocale(LC_ALL, "RUS");
	do
	{
		do
		{
			menuPoint = 0;
			system("cls");
			printf("����:\n1. ���������� ������� �����\n2. ���������� ������������� �������� � �������\n0. ����� �� ���������\n");
			if (error == 1)
			{
				printf("��� ����� ���� �������� ������, ��������� �������...\n");
				error = 0;
			}
			printf("�������� ��������: ");
			if (scanf("%i[0-9]", &menuPoint) == 1) {}
			else
			{
				error = 1;
			}
			if (menuPoint < 0 || menuPoint > 2) { error = 1; }
			clean_stdin();
		} while (error == 1);
		switch (menuPoint)
		{
		case 0:
			break;
		case 1:
			system("cls");
			func1();
			break;
		case 2:
			system("cls");
			func2();
			break;
		default:
			break;
		}
		if (menuPoint == 0) {}
		else
		do
		{
			printf("��������� � ������� ���� ���������? (Y/N) ");
			clean_stdin(); //������� ������ �����
			scanf("%c", &yn);
			getchar();
			if (yn == 'y' || yn == 'Y' || yn == 'n' || yn == 'N') { error = 0; }
			else error = 1;
		} while (error == 1);
	} while (yn == 'y' && yn != 'n'); // ���� ������������ ���� "Y" �� ��������� ���������� ���������
	return 0;
}


float ff(float n) {
	return 3.14 * n * n;
}

void clean_stdin() // ������� ������� ������ ����� � ����������
{
	fflush(stdin);
	fseek(stdin, 0, SEEK_END);
}

int i = 0, max;

int maximum(int ar[], int n)
{
	int max;
	if (!n)
		return ar[n];
	max = maximum(ar, n - 1);
	return ar[n]>max ? ar[n] : max;
}

void func1()
{
	char yn;
	float r = 0, s;
	int error;
	do {
		do
		{
			system("cls");
			error = 0; // ������� ���������� ���������� �� ������� ������ (���� ������ �����, ��������� ������ �������� �����)
			printf("������ ����� ���� �� 0,1 �� 1000\n������� ������ �����: ");
			clean_stdin(); // �������� ����� �����
			if (scanf("%f[0-9]", &r) == 1) {} // �������� ���� �� ������������ ����� ��� �����
			else
			{
				printf("�� ����� �����, ��������� ����");
				error = 1; // ��������� ������.

			}
			if (r > 100 || r <= 0) // �������� ���������� ����� �� ��������� � ���������� �������� �������� �����
			{
				printf("��������� ����� �� ������ � ���������� ��������\n���������� ��������: 0,1 - 1000\n");
				error = 1; // ��������� ������.
			}
			clean_stdin();
		} while (error == 1); // ��������� ���� ���� ������
		s = ff(r);
		printf("������� ����� : %f\n", s);
		do
		{
			printf("��������� ���������� �������? (Y/N) ");
			clean_stdin(); //������� ������ �����
			scanf("%c", &yn);
			getchar();
			if (yn == 'y' || yn == 'Y' || yn == 'n' || yn == 'N') { error = 0; }
			else error = 1;
		} while (error == 1);
	} while (yn == 'y' && yn != 'n'); // ���� ������������ ���� "Y" �� ��������� ���������� ���������
	//return 0;
}

void func2()
{
	char yn;
	int error = 0, sizeA, *A, i = 0, max = 0, n = 1;
	do {
		do
		{
			system("cls");
			printf("���������� �������� �� 2 �� 20\n");
			if (error == 1)
			{
				printf("��� ����� ���� �������� ������, ��������� ������� �����...\n");
				error = 0; // ������� ���������� ���������� �� ������� ������ (���� ������ �����, ��������� ������ �������� �����)
			}
			printf("������� ������ ������: ");
			clean_stdin(); // �������� ����� ����� 
			if (scanf("%i[0-9]", &sizeA) == 1) {} // �������� ���� �� ������������ ����� ��� �����
			else
			{
				printf("�� ����� �����, ��������� ����\n");
				error = 1; // ��������� ������.

			}
			if (sizeA > 20 || sizeA < 2) // �������� ���������� ����� �� ��������� � ���������� �������� �������� �����
			{
				printf("��������� ����� �� ������ � ���������� ��������\n");
				error = 1; // ��������� ������.
			}
		} while (error == 1); // ��������� ���� ���� ������

		A = (int*)malloc(sizeA * sizeof(int));

		if (!A) {
			printf("������ �� ���� �������� ��� ����� �����");
			getchar();
			return;
		}
		printf("����� ������� ������ ����� �� -20000 �� 20000\n");
		for (i = 0; i < sizeA; i++) {
			do
			{
				error = 0; // ������� ���������� ���������� �� ������� ������ (���� ������ �����, ��������� ������ �������� �����)
				printf("������� %i ������� ������� ", i+1);
				clean_stdin(); // �������� ����� ����� 
				if (scanf("%i[0-9]", &A[i]) == 1) {} // �������� ���� �� ������������ ����� ��� �����
				else
				{
					printf("�� ����� �����, ��������� ����\n");
					error = 1; // ��������� ������.
				}
				if (A[i] > 20000 || A[i] <= -20000) // �������� ���������� ����� �� ��������� � ���������� �������� �������� �����
				{
					printf("��������� ����� �� ������ � ���������� ��������\n");
					error = 1; // ��������� ������.
				}
			} while (error == 1); // ��������� ���� ���� ������
		}
		printf("����� ������: \n");
		for (i = 0; i < sizeA; i++) {
			printf("%i ", A[i]);
		}
		max = A[0];
		max = maximum(A, sizeA);
		printf("\n������������ ������� � �������: %i\n", max);
		system("pause");
		do
		{
			printf("��������� ���������� �������? (Y/N) ");
			clean_stdin(); //������� ������ �����
			scanf("%c", &yn);
			getchar();
			if (yn == 'y' || yn == 'Y' || yn == 'n' || yn == 'N') { error = 0; }
			else error = 1;
		} while (error == 1);
	} while (yn == 'y' && yn != 'n'); // ���� ������������ ���� "Y" �� ��������� ���������� ���������
	//return 0;
}