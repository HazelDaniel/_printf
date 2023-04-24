#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * get_length - a function that gets the length
 * of a custom printf function
 * @va_args: the variadic argument list
 * @format: the string parameter
 * @ind_ptr: the address of the current
 * index
 * Return: char **
 **/
char **get_length (va_list va_args, char *format, int *ind_ptr)
{
	char *status = "1";
	char **result = NULL, *length_str;
	result = malloc(2 * sizeof(char *));
	if (result == NULL)
	{
		*status = '0';
		return (result);
	}
	result[1] = malloc(2 * sizeof(char));
	if (result[1] == NULL)
	{
		*status = '0';
		return (NULL);
	}
	switch (format[*ind_ptr])
	{
	case 'h':
			result[1][0] = itoc(SHORT_SIZE);
			(*ind_ptr)++;
		break;
	case 'l':
			if (format[*ind_ptr + 1] == 'l')
				(*ind_ptr)++;
			result[1][0] = itoc(LONG_SIZE);
			(*ind_ptr)++;
		break;
	case 'L':
			result[1][0] = itoc(LONG_DOUBLE_SIZE);
			(*ind_ptr)++;
		break;
	default:
		result[0] = "1";
		result[1] = NULL;
		return (result);
	}
	result[0] = "1";
	result[1][1] = '\0';
	return (result);
}
