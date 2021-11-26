#include <stdio.h>
#include <conio.h>
#include <locale>
#include "MyStrings.h"

int main()
{
	setlocale(LC_ALL, "ru");
	char main[256]{};
	char add[256]{};
	printf("Введите строку: ");
	gets_s(main);
	printf("Длина введенной строки: %d\n", mystrlen(main));
	printf("Введите строку 1: \n");
	gets_s(main);
	printf("Введите строку 2: \n ");
	gets_s(add);
	mystrcy(main, add);
	printf("Строка 1 - %s	Строка 2 - %s\n", main, add);
	printf("Введите строку 1: \n");
	gets_s(main);
	printf("Введите строку 2: \n ");
	gets_s(add);
	mystrcat(main, add);
	printf("Строка 1 - %s	Строка 2 - %s\n", main, add);
	printf("Введите строку 1: \n");
	gets_s(main);
	printf("Введите строку 2: \n ");
	gets_s(add);
	printf("Строка 1 - %s	Строка 2 - %s  -- %d\n", main, add, mystrcmp(main ,add));
	return 0;
}