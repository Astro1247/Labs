#include "stdafx.h"
#include "stdio.h"
#include <time.h>
#include <stdlib.h>
#include "windows.h"
#include "locale.h"

int error()
{
	system("cls");
	error1();
}

int error1()
{
	system("cls");
	printf("         _,.-------.,_\n     ,;~.             .~;,\n   ,;                     ;,\n  ;                         ;\n ,.        ERROR            .,\n,;                           ;,\n; ;      .           .      ; ;\n| ;   ______       ______   ; |\n|  `/~.     ~. . .~     .~\.  |\n|  ~  ,-~~~^~, | ,~^~~~-,  ~  |\n |   |        }:{        |   |\n |   l       / | \       !   |\n .~  (__,.--. .^. .--.,__)  ~.\n |     ---;. / | \ `;---     |\n  \__.       \/^\/       .__/\n   V| \                 / |V\n    | |T~\___!___!___/~T| |\n    | |`IIII_I_I_I_IIII.| |\n    |  \,III I I I III,/  |\n     \   `~~~~~~~~~~.    /\n       \   .       .   /\n         \.    ^    ./\n           ^~~~^~~~^");
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("COLOR 04");
	error2();
	return 0;
}

int error2()
{
	system("cls");
	printf("         _,.-------.,_\n     ,;~.             .~;,\n   ,;                     ;,\n  ;                         ;\n ,.        ERROR            .,\n,;                           ;,\n; ;      .           .      ; ;\n| ;   ______       ______   ; |\n|  `/~.     ~. . .~     .~\.  |\n|  ~  ,-~~~^~, | ,~^~~~-,  ~  |\n |   |        }:{        |   |\n |   l       / | \       !   |\n .~  (__,.--. .^. .--.,__)  ~.\n |     ---;. / | \ `;---     |\n  \__.       \/^\/       .__/\n   V| \                 / |V\n    | |T~\___!___!___/~T| |\n    | |`IIII_I_I_I_IIII.| |\n    |  \,III I I I III,/  |\n     \   `~~~~~~~~~~.    /\n       \   .       .   /\n         \.    ^    ./\n           ^~~~^~~~^");
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("COLOR 40");
	error1();
	return 0;
}