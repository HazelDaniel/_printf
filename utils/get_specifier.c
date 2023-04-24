#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * get_specifier - a function that gets the specifier
 * of a custom printf function
 * @va_args: the variadic argument list
 * @format: the string parameter
 * @ind_ptr: the address of the current
 * index
 * Return: char **
 **/
char **get_specifier (va_list va_args, char *format, int *ind_ptr)
{
	char *status = "1";
	char **result = NULL, *specifier_str;
	result = malloc(2 * sizeof(char *));
	if (result == NULL)
	{
		*status = '0';
		return (result);
	}
	result[1] = malloc(2 * sizeof(char));
	if (result[1] == NULL)
	{
		free(result);
		*status = '0';
		return (NULL);
	}
	switch (format[*ind_ptr])
	{
	case 's':
	case 'c':
	case 'u':
	case 'o':
	case 'i':
	case 'd':
	case 'b':
	case 'x':
	case 'X':
	case 'p':
	case 'S':
	case 'r':
	case 'R':
	case '%':
		result[1][0] = format[*ind_ptr];
		break;
	default:
		result[0] = "1";
		result[1][0] = '\0';
		return (result);
	}
	result[0] = "1";
	result[1][1] = '\0';
	return (result);
}
