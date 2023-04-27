#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * get_precision - a function that gets the precision
 * of a custom printf function
 * @va_args: the variadic argument list
 * @format: the string parameter
 * @ind_ptr: the address of the current
 * index
 * Return: char **
 **/
char **get_precision(va_list va_args, char *format, int *ind_ptr)
{
	char *status = "1";
	char **result = NULL, *precision_str;
	int i = *ind_ptr, j = 0, k = 0, precision;

	result  = malloc(2 * sizeof(char *));
	if (result == NULL)
	{
		*status = '0';
		return (NULL);
	}
	result[0] = malloc(2 * sizeof(char));
	if (result[0] == NULL)
	{
		*status = '0';
		return (NULL);
	}
	if (format[i] == '.')
	{
		i++, (*ind_ptr)++;
	}
	else
	{
		result[1] = NULL, result[0][0] = *status, result[0][1] = '\0';
		return (result);
	}
	if (format[i] == '*')
	{
		precision = va_arg(va_args, unsigned long);
		precision_str = itoa(precision);
		if (precision_str == NULL)
		{
			*status = '0';
			return (NULL);
		}
		result[1] = malloc((_strlen(precision_str) + 1) * sizeof(char));
		if (result[1] == NULL)
		{
			*status = '0';
			return (NULL);
		}
		for (j = 0; precision_str[j] != '\0'; j++)
		{
			result[1][j] = precision_str[j];
		}
		result[0][0] = '1', result[1][j] = '\0', free(precision_str);
	}
	else
	{
		while (is_digit(format[i]))
		{
			i++, k++;
		}
		result[1] = malloc((k + 1) * sizeof(char));
		if (result[1] == NULL)
		{
			*status = '0';
			return (NULL);
		}
		--k, --i;

		for (j = 0; j <= k; j++)
		{
			result[1][j] = format[j + *ind_ptr];
		}
		*ind_ptr = i;
		result[0][0] = '1', result[1][k + 1] = '\0';
	}
	return (result);
}
