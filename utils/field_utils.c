#include "main.h"

/**
 * get_important_flags - a function that
 * removes duplicate flags and return the
 * ones with higher priority
 * @flags: the input string containing the flags
 * Return: char *
 **/
char *get_important_flags(char *flags)
{
	char order[] = {'#', '+', ' ', '-', '0'};
	char important[] = "\0\0\0\0\0\0", *res_str = NULL;
	int i = 0, j = 0, k = 0, len = _strlen(flags);

	for (; flags[i] != '\0'; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (flags[i] == order[j])
			{
				if (flags[i] == ' ')
				{
					if (!in_str('+', flags))
						important[k++] = flags[i];
				}
				else if (flags[i] == '0')
				{
					if (!in_str(' ', flags))
						important[k++] = flags[i];
				}
				else
				{
					important[k++] = flags[i];
				}
			}
		}
	}
	res_str = malloc((k + 1) * sizeof(char));
	if (res_str == NULL)
		return (res_str);
	for (j = 0; j < k; j++)
		res_str[j] = important[j];

	return (res_str);
}
