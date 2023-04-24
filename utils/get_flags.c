#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * get_flags - a function that gets the flags
 * of a custom printf function
 * @format: the first string parameter
 * @ind_ptr: the address of the current
 * index
 * Return: char **
 **/
char **get_flags (char *format, int *ind_ptr)
{
	char *status = "1";
	int flag_bool, flag_index, *flags_h_ret = NULL;
	char **result = NULL;
	flag_t flags_hash[] =
	{
		{'0', 0},
		{'-', 0},
		{'#', 0},
		{'+', 0},
		{' ', 0},
		{'\0', 1}
	};//basically, we are checking for duplicate flags
	int i = *ind_ptr, j = 0, k = 0;

	result = malloc(2 * sizeof(char *));
	if (result == NULL)
		return (result);
	result[0] = malloc(2 * sizeof(char));
	result[1] = malloc(6 * sizeof(char));
	if (result[0] == NULL || result[1] == NULL)
	{
		free(result[0]);
		free(result[1]);
		free(result);
		*status = '0';
		return (NULL);
	}

	for (j = 0; j < 6; j++, i++)
	{
		while ((flags_h_ret = is_flag(format[i], flags_hash), flags_h_ret[1] != -1) && j < 6)
		{
			if (flags_h_ret == NULL)
			{
				*status = '0';
				free(flags_h_ret);
				return (NULL);
			}
			flag_bool = flags_h_ret[0];
			flag_index = flags_h_ret[1];
			if (!flags_hash[flag_index].found)
			{
				flags_hash[flag_index].found = 1;
				result[1][k] = format[i];
				k++;
			}
			i++;
			j++;
		}
		break;
	}
	for (; k < 6; k++)
		result[1][k] = '\0';
	*ind_ptr = --i;
	result[0][0] = *status;
	result[0][1] = '\0';
	free(flags_h_ret);
	return (result);
}
