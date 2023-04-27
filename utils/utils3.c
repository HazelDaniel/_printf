#include "main.h"

/**
 * dig_count - a function that counts
 * the number of digits in a given integer
 * @dig: the provided integer
 * Return: int
 **/
int dig_count(unsigned long long int dig)
{
	int count = 0;

	if (dig < 10)
	{
		return (1);
	}
	count++;
	while ((dig /= 10) > 0)
		count++;
	return (count);
}

/**
 * itoa - a function that converts a given
 * integer parameter to string
 * @i: the integer
 * Return: char*
 **/
char *itoa(unsigned long long int i)
{
	char *res_tmp = NULL, tmp_char;
	unsigned long long int temp = i;
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
	return (res_tmp);
}
/**
 * itoc - a function that converts a
 * one digit integer to a character
 * @i: the integer
 * Return: char
 **/
char itoc(int i)
{
	return (i + '0');
}

/**
  * in_str - a function that looks up
	* a character in a string and returns
	* a boolean integer if found
  * @c: parameter of type char .
  * @str: parameter of type char *.
  * Return: int .
 */
int in_str(char c, char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/**
  * get_abs - a function that returns the absolute
	* value of a number
  * @val: parameter of type long long int .
  * Return: unsigned long long int .
 */
unsigned long long int get_abs(long long int val)
{
	if (val < 0)
		return (-val);
	return (val);
}
