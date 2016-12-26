#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 3

int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;
int full = 0;
int count = 0;

int fullList(int count)
{
	return intArray[count];
}

int peek() {
	return intArray[front];
}

bool isEmpty() {
	return itemCount == 0;
}

bool isFull() {
	return itemCount == MAX;
}

int size() {
	return itemCount;
}

void insert(int data) {

	if (!isFull()) {

		if (rear == MAX - 1) {
			rear = -1;
		}

		intArray[++rear] = data;
		itemCount++;
	}
}

int removeData() {
	int data = intArray[front++];

	if (front == MAX) {
		front = 0;
	}

	itemCount--;
	return data;
}

void queue()
{
	count = 0;
	full = 0;
	while (1)
	{
	int menuPoint = 1, currentSelect = 1;
	bool isSwitching = true, isError = 0;
	while (isSwitching == true)
	{
		clean();
		int pressedkey = "";
		printf("���� ���������� ��������:\n=> 1. �������� �������\n   2. ������� �������\n   3. ������� ������ �������\n   4. ��������� ������� �� �������\n   5. �������� ������ �������\n   6. ������� ������ ������� �� �������");
		{
			int pressedkey;
			int i = 0;
			int counter = 0;
			while (isSwitching)
				if ((pressedkey = getch()) != -1)
				{
					counter += 1;
					if (pressedkey == 80)
					{
						if (menuPoint < 6)
							menuPoint += 1;
						isError = false;
					}
					else if (pressedkey == 72)
					{
						if (menuPoint > 1)
							menuPoint -= 1;
						isError = false;
					}
					else if (pressedkey == 13)
						isSwitching = false;
					else if (pressedkey == 27)
						return;
					else if (counter > 1)
						break;
					if (counter > 1)
					{
						if (isError == false)
						{
							currentSelect = menuPoint;
							system("cls");
							printf("���� ���������� ��������:\n");
							switch (currentSelect)
							{
							case 1:
								printf("=> 1. �������� �������\n   2. ������� �������\n   3. ������� ������ �������\n   4. ��������� ������� �� �������\n   5. �������� ������ �������\n   6. ������� ������ ������� �� �������");
								break;
							case 2:
								printf("   1. �������� �������\n=> 2. ������� �������\n   3. ������� ������ �������\n   4. ��������� ������� �� �������\n   5. �������� ������ �������\n   6. ������� ������ ������� �� �������");
								break;
							case 3:
								printf("   1. �������� �������\n   2. ������� �������\n=> 3. ������� ������ �������\n   4. ��������� ������� �� �������\n   5. �������� ������ �������\n   6. ������� ������ ������� �� �������");
								break;
							case 4:
								printf("   1. �������� �������\n   2. ������� �������\n   3. ������� ������ �������\n=> 4. ��������� ������� �� �������\n   5. �������� ������ �������\n   6. ������� ������ ������� �� �������");
								break;
							case 5:
								printf("   1. �������� �������\n   2. ������� �������\n   3. ������� ������ �������\n   4. ��������� ������� �� �������\n=> 5. �������� ������ �������\n   6. ������� ������ ������� �� �������");
								break;
							case 6:
								printf("   1. �������� �������\n   2. ������� �������\n   3. ������� ������ �������\n   4. ��������� ������� �� �������\n   5. �������� ������ �������\n=> 6. ������� ������ ������� �� �������");
								break;
							}
						}
						counter = 0;
					}
				}
		}
	}
	isError = false;
	switch (currentSelect)
	{
	case 1:
	{
		clean();
		int data = 0, err = 0;
		do
		{
			if (count > 2)
			{
				printf("������� �����������.\n");
				full = 1;
				err = 2;
				system("pause");
				break;
			}
			else
			{
				full = 0;
				count += 1;
				err = 0; // ������� ���������� ���������� �� ������� ������ (���� ������ �����, ��������� ������ �������� �����)
				printf("������� ����� ��� ���������� � �������: ");
				clean_stdin(); // �������� ����� ����� 
				if (scanf("%i[0-9]", &data) == 1) {} // �������� ���� �� ������������ ����� ��� �����
				else
				{
					printf("�����.\n");
					err = 1; // ��������� ������.
				}
				if (data > 1000 || data < -1000 && err == 0) // �������� ���������� ����� �� ��������� � ���������� �������� �������� �����
				{
					printf("��������� ����� �� ������ � ���������� �������� �������� �����!\n���������� ��������: �� -1000 �� 1000\n");
					err = 1; // ��������� ������.
				}
			}
		} while (err == 1); // ��������� ���� ���� ������
		if (full == 0)
			insert(data);
		clean();
		if (full == 0)
		{
			printf("�������� ��������� �������, ������� ����� ������� ��� �����������...");
			getch();
		}
		break;
	}
	case 2:
	{
		clean();
		if (!isEmpty())
		{
			int temp = 0;
			/*int removedNum = removeData();
			count = count - 1;
			full = 0;
			printf("������� '%i' ������ �� �������, ������� ����� ������� ��� �����������...", removedNum);*/
			printf("������� ��������� �������: ");
			for (int j = 0; j < 3; j++)
			{
				temp = fullList(j);
				if (j == 0)
					printf("%i", temp);
				else
					printf(", %i", temp);
			}
			printf("\n");
			getch();
			break;
		}
		if (isEmpty())
		{
			printf("������� ������!");
			getch();
			break;
		}
		getch();
		break;
	}
	case 3:
	{
		clean();
		int front = peek();
		if (!isEmpty()) {
			printf("������ �������: %i", front);
			int removedNum = removeData();
			count = count - 1;
			full = 0;
			printf("������� '%i' ������ �� �������, ������� ����� ������� ��� �����������...", removedNum);
		}
		else
			printf("������� ������!");
		//removeData();
		count = count - 1;
		full = 0;
		getch();
		break;
	}
	case 4:
		{
		clean();
		if (isEmpty())
			printf("������� ������!");
		else
			printf("������� �� ������!");
		getch();
		break;
		}
	case 5:
		{
		clean();
		int queueSize = size();
		printf("������ �������: %i", queueSize);
		getch();
		break;
		}

	case 6:
		{
		clean();
		if (!isEmpty())
		{
			int temp = 0;
			int removedNum = removeData();
			count = count - 1;
			full = 0;
			printf("������� '%i' ������ �� �������, ������� ����� ������� ��� �����������...", removedNum);
			getch();
			break;
		}
		if (isEmpty())
		{
			printf("������� ������!");
			getch();
			break;
		}
		getch();
		break;
		}
	default:
	{

		break;
	}
	}
}
}

