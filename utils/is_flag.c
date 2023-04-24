#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * is_flag - a function that checks if a
 * character is a flag
 * @c: the test character
 * @hash_addr: address of the flag hash
 * Return: array of int
 **/
int *is_flag(char c,flag_t hash_addr[])
{
	int i = 0, first_index = 0;
	int *flags_ret = malloc(2 * sizeof(int));

	if (flags_ret == NULL)
		return (flags_ret);

	while (((hash_addr)[i]).flag)
	{
		if (c == ((hash_addr)[i]).flag)
		{
			flags_ret[0] = 1;
			first_index = i;
			break;
		}
		else
		{
			flags_ret[0] = 0;
		}
		i++;
	}
	i--;
	if (flags_ret[0] == 0)
		flags_ret[1] = -1;
	else
		flags_ret[1] = first_index;
	return (flags_ret);
}
