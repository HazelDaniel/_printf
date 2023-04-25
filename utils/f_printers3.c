#include "main.h"
#include <stdio.h>


int print_x_lower(va_list va_args, int index, char *flag,
	int width, int precision, int length, char specifier)
{
	puts("hex lower printed");
	return (0);
}

int print_char(va_list va_args, int index, char *flag,
	int width, int precision, int length, char specifier)
{
	puts("char printed");
	return (0);
}

int print_string(va_list va_args, int index, char *flag,
	int width, int precision, int length, char specifier)
{
	puts("string printed");
	return (0);
}

int print_reverse(va_list va_args, int index, char *flag,
	int width, int precision, int length, char specifier)
{
	puts("reverse printed");
	return (0);
}

int print_rot13(va_list va_args, int index, char *flag,
	int width, int precision, int length, char specifier)
{
	puts("rot 13 printed");
	return (0);
}
