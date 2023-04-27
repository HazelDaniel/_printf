#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * uint_to_bin - a function that
 * converts an integer into binary
 * @dig: the integer
 * Return: char *
 **/
char *uint_to_bin(unsigned long long int dig)
{
	int i = 0;
	unsigned int a[32], sum = 0, max = 2147483648, s_index;
	char *tmp_str = NULL;

	a[0] = (dig / max) % 2;
	for (i = 1; i < 32; i++)
		max /= 2, a[i] = (dig / max) % 2;
	for (i = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum == 1 && a[i] != 0)
		{
			tmp_str = malloc((32 - i + 1) * sizeof(char));
			if (tmp_str == NULL)
				return (tmp_str);
			s_index = i;
		}
	}
	for (i = 0; s_index < 32; s_index++, i++)
		tmp_str[i] = itoc(a[s_index]);
	tmp_str[i] = '\0';
	return (tmp_str);
}
