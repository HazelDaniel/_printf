#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * itoa - a function that converts a given
 * integer parameter to string
 * @i: the integer
 * Return: char*
 **/
char *itoa(unsigned int i)
{
	char *res_tmp = NULL, tmp_char;
	unsigned int temp = i;
	int j, digits = dig_count(i);

	res_tmp = malloc((digits + 1) * sizeof(char));
	if (res_tmp == NULL)
		return (NULL);
	for (j = 0; j < digits; j++)
	{
		if (temp < 10)
		{
			res_tmp[j] = itoc(temp);
		}
		else
		{
			res_tmp[j] = itoc(temp % 10);
			temp /= 10;
		}
	}
	for (j = 0; j < ((digits) / 2); j++)
	{
		tmp_char = res_tmp[digits - 1 - j];
		res_tmp[digits - 1 - j] = res_tmp[j];
		res_tmp[j] = tmp_char;
	}
	res_tmp[digits] = '\0';
	// printf("%d\n", digits);
	return (res_tmp);
}
