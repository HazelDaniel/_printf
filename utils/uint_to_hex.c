#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * uint_to_hex - a function that
 * converts an integer into hexadecimal
 * @dig: the integer
 * @x_case: the character that determines in what
 * case the hexadecimal will be returned
 * Return: char *
 **/
char *uint_to_hex(unsigned long int dig, char x_case)
{
	int i = 0, j, ascii_offset, rem;
	char *tmp_str = NULL, x_store[16];
	unsigned int temp = dig;

	for (; temp > 0; i++)
	{
		rem = temp % 16;
		if (rem < 10)
		{
			x_store[i] = itoc(rem);
		}
		else
		{
			switch (x_case)
			{
			case 'x':
					ascii_offset = 32;
				break;
			case 'X':
					ascii_offset = 0;
				break;
			}
			x_store[i] = rem + (55 + ascii_offset);
		}
		temp /= 16;
	}
	i--;
	tmp_str = malloc((i + 1 + 1) * sizeof(char));
	if (tmp_str == NULL)
		return (tmp_str);
	for (j = 0; i >= 0; i--, j++)
	{
		tmp_str[j] = x_store[i];
	}
	tmp_str[j] = '\0';
	return (tmp_str);
}
