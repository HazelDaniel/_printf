#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * uint_to_octal - a function that
 * converts an integer into octal
 * @dig: the integer
 * Return: char *
 **/
char *uint_to_octal(unsigned long long int dig)
{
	int i = 0, index = 0;
	char *tmp_str = NULL, tmp;
	unsigned long long octal = 0;
	tmp_str = malloc(23 * sizeof(char));
	if (tmp_str == NULL)
		return (NULL);
	for (; index < 23; index++)
		tmp_str[index] = '\0';
	
	for (index = 0; dig > 0 && index < 23;)
	{
		tmp_str[index++] = itoc((unsigned long long int)(dig % 8));
		dig /= 8;
	}
	--index;
	for (; i < ((index + 1) / 2); i++)
	{
		tmp = tmp_str[i];
		tmp_str[i] = tmp_str[index - i];
		tmp_str[index - i] = tmp;
	}
	return (tmp_str);
}
