// Lab4.cpp: определяет точку входа для консольного приложения.
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
		printf("S<50, increasing S by 1... (S=%i)\n", s);
		s = s + 1;
		printf("Checking if S<50...\n");
	} while (s < 50);
	printf("Stopping loop..\n");
	printf("Now S = %i\n", s);
	printf("Press ENTER to continue...\n");
	getchar();
	//123
	return 0;
}

