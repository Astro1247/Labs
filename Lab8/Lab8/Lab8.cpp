// ConsoleApplication12.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <stdio.h>
#include <locale.h>
#include "locale.h"
#include <stdlib.h>

float ff(float);
int find_max(int *A, int sizeA, int, int);

int main()
{
	float r = 0, s;
	int err, yn = 0, sizeA, *A, i = 0, max = 0, n = 1;
	setlocale(LC_ALL, "RUS");
	printf("������� ������ �����= 1\n���������� ������������� �������� � �������= 2");
	/*do {
	do {
	do
	{
	err = 0; // ������� ���������� ���������� �� ������� ������ (���� ������ �����, ��������� ������ �������� �����)
	printf("������� ������ �����: ");
	clean_stdin(); // �������� ����� �����
	if (scanf("%f[0-9]", &r) == 1) {} // �������� ���� �� ������������ ����� ��� �����
	else
	{
	printf("�� ����� �����, ��������� ����\n����� ������� ������ ����� �� 0,1 �� 1000,0");
	err = 1; // ��������� ������.

	}
	if (r > 100 || r <= 0) // �������� ���������� ����� �� ��������� � ���������� �������� �������� �����
	{
	printf("��������� ����� �� ������ � ���������� ��������\n���������� ��������: 0,1 - 1000,0\n");
	err = 1; // ��������� ������.
	}
	} while (err == 1); // ��������� ���� ���� ������
	s = ff(r);
	printf("������� ����� : %f\n", s);
	printf("\n������� 1 ���� ������ ��������� ��������");
	scanf("%i", &yn);
	} while (yn == 1);

	*/	do {
		do
		{
			err = 0; // ������� ���������� ���������� �� ������� ������ (���� ������ �����, ��������� ������ �������� �����)
			printf("\n������� ������ ������ ");
			clean_stdin(); // �������� ����� ����� 
			if (scanf("%i[0-9]", &sizeA) == 1) {} // �������� ���� �� ������������ ����� ��� �����
			else
			{
				printf("�� ����� �����, ��������� ����\n����� ������� ������ ����� �� ");
				err = 1; // ��������� ������.

			}
			if (sizeA > 20 || sizeA <= 2) // �������� ���������� ����� �� ��������� � ���������� �������� �������� �����
			{
				printf("��������� ����� �� ������ � ���������� ��������\n���������� ��������: 2 - 20\n");
				err = 1; // ��������� ������.
			}
		} while (err == 1); // ��������� ���� ���� ������

		A = (int*)malloc(sizeA * sizeof(int));

		if (!A) {
			printf("������ �� ���� �������� ��� ����� �����");
			getchar();
			return 1;
		}
		for (i = 0;i < sizeA; i++) {
			do
			{
				err = 0; // ������� ���������� ���������� �� ������� ������ (���� ������ �����, ��������� ������ �������� �����)
				printf("������� %i ������� ������� ", i);
				clean_stdin(); // �������� ����� ����� 
				if (scanf("%i[0-9]", &A[i]) == 1) {} // �������� ���� �� ������������ ����� ��� �����
				else
				{
					printf("�� ����� �����, ��������� ����\n����� ������� ������ ����� �� -20000 �� 20000");
					err = 1; // ��������� ������.
				}
				if (r > 20000 || r <= -20000) // �������� ���������� ����� �� ��������� � ���������� �������� �������� �����
				{
					printf("��������� ����� �� ������ � ���������� ��������\n���������� ��������: �� -20000 �� 20000\n");
					err = 1; // ��������� ������.
				}
			} while (err == 1); // ��������� ���� ���� ������
		}
		printf("����� ������:\n");
		for (i = 0;i < sizeA; i++) {
			printf("%i ", A[i]);
		}
		max = find_max(A, sizeA, 0, 0);
		printf("max= %i", max);
		system("pause");
	} while (yn == 2);
	//	} while (yn);
	return 0;
}

float ff(float n) {
	return 3.14 * n * n;
}

clean_stdin(void) // ������� ������� ������ ����� � ����������
{
	fflush(stdin);
	fseek(stdin, 0, SEEK_END);
}

int find_max(int *A[], int sizeA, int i, int max)
{
	/*int b = A[i];
	printf("mas %i",i);
	getchar();
	system("pause");*/
	/*if (i < sizeA) {
		if (A[i] > max) {
			max = A[i];
		}
		else return 0;
			i++;
		find_max(A, sizeA, i+=1, max);
	}*/
	if (i < sizeA-1)
	{
		int maxx = &A[1];
		if (*maxx < A[i])
			maxx = A[i];
		i++;
		find_max(*A, sizeA, i, max);
	}
	return max;
}


/*int search(int *array, int array_size)
{
static int maxVal = 0;
static int currIndex = 0;
static int memIndex = 0;

if (array_size) {
if (*array > maxVal) {
maxVal = *array;
memIndex = currIndex;
}
currIndex++;
return search(++array, --array_size);
}
return memIndex;
}*/