#include "main.h"
#include <stdio.h>


int print_non_print(va_list va_args, int index, char *flag,
	int width, int precision, int length, char specifier)
{
	puts("non-print printed");
	return (0);
}

int print_unsigned(va_list va_args, int index, char *flag,
	int width, int precision, int length, char specifier)
{
	puts("unsigned int printed");
	return (0);
}

int print_octal(va_list va_args, int index, char *flag,
	int width, int precision, int length, char specifier)
{
	puts("octal printed");
	return (0);
}
