#include "stdafx.h"
#include <locale.h>
#include "stdlib.h"

int main()
{
	char *invalidch = "o";
	char string[100];
	setlocale(LC_ALL, "RUS");
	printf("������� ������: ");
	scanf("%s", string);
	char *c = string;
	system("pause");
    return 0;
}
