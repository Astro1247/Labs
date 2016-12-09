#include "stdafx.h"
#include "stdio.h"
#include <stdbool.h>
#include <stdlib.h>

void mainMenu()
{
	int menuPoint = 1, currentSelect = 1;
	bool isSwitching = true, isError = 0;
	while (isSwitching == true)
	{
		int pressedkey = "";
		printf("Главное меню:\n=> 1. Стек\n   2. Очередь\n   3. Двухсвязный список\n");
		//while (pressedkey != '\r')
		{
			int pressedkey;
			int i = 0;
			int counter = 0;
			while (isSwitching)
				if ((pressedkey = getch()) != -1)
				{
					counter += 1;
					//printf("%i\n", pressedkey);
					if (pressedkey == 80)
					{
						if (menuPoint < 3)
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
							printf("Главное меню:\n");
							switch (currentSelect)
							{
							case 1:
								printf("=> 1. Стек\n   2. Очередь\n   3. Двухсвязный список\n");
								break;
							case 2:
								printf("   1. Стек\n=> 2. Очередь\n   3. Двухсвязный список\n");
								break;
							case 3:
								printf("   1. Стек\n   2. Очередь\n=> 3. Двухсвязный список\n");
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
		printf("Типо вызвал стек");
		break;
	}
	case 2:
	{
		clean();
		queue();
		break;
	}
	case 3:
	{
		clean();
		printf("Типо вызвал список");
		break;
	}
	default:
	{

		break;
	}
	}
}
