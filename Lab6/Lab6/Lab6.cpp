#include "stdafx.h"
#include <locale.h>
#include "stdlib.h"

void remove_all_chars(char* string, char c) {
	char *pr = string, *pw = string;
	while (*pr) {
		*pw = *pr++;
		pw += (*pw != c);
	}
	*pw = '\0';
}

int main()
{
	char *invalidch = "o";
	char string[100], delch;
	setlocale(LC_ALL, "RUS");
	printf("¬ведите строку: ");
	scanf("%s", string);
	char *c = string;
	scanf("%c", &delch);
	remove_all_chars(string, 'o');
	printf("%s\n", string);
	system("pause");
    return 0;
}
