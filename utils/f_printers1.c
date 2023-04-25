#include "main.h"
#include <stdio.h>

int print_bin(va_list va_args, int index, char *flag, int width, int precision, int length, char specifier)
{
	puts("bin printed");
	return (0);
}

int print_int(va_list va_args, int index, char *flag,
	 int width, int precision, int length, char specifier)
{
	puts("int printed");
	return (0);
}

int print_x_upper(va_list va_args, int index, char *flag, int width,
	int precision, int length, char specifier)
{
	puts("x upper printed");
	return (0);
}

int print_pointer(va_list va_args, int index, char *flag,
	int width, int precision, int length, char specifier)
{
	puts("pointer printed");
	return (0);
}
