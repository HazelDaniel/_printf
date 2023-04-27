#include "main.h"
#include <stdio.h>
/**
 * is_digit - a function that checks if a
 * character is convertible to digit
 * @c: the character parameter
 * Return: 1 or 0
 **/
int is_digit(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

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
/**
 * is_print - a function that checks if a
 * character is printable
 * @c: the character parameter
 * Return: 1 or 0
 **/
int is_print(char c)
{
	if (c <= 126 && c >= 32)
		return (1);
	return (0);
}
/**
 * is_alpha - a function that checks if a
 * character is printable
 * @c: the character parameter
 * Return: 1 or 0
 **/
int is_alpha(char c)
{
	if ((c <= 90 && c >= 65) ||
		(c >= 97 && c <= 122))
		return (1);
	return (0);
}
/**
 * ctoi - a function that converts
 * a character to a number
 * @c: the character
 * Return: integer
 **/
int ctoi(char c)
{
	return (c - '0');
}

/**
* _atoi - converts a string to an integer
* @s: string to be converted
* Return: the int converted from the string
*/
int _atoi(char *s)
{
	int i, d, n, len, f, digit;

	i = 0;
	d = 0;
	n = 0;
	len = 0;
	f = 0;
	digit = 0;
	while (s[len] != '\0')
	len++;
		while (i < len && f == 0)
		{
			if (s[i] == '-')
			{
				++d;
			}
			if (s[i] >= '0' && s[i] <= '9')
			{
				digit = s[i] - '0';
				if (d % 2)
					digit = -digit;
				n = n * 10 + digit;
				f = 1;
				if (s[i + 1] < '0' || s[i + 1] > '9')
					break;
				f = 0;
			}
			i++;
		}
	if (f == 0)
	{
		return (0);
	}
	return (n);
}

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
	// printf("%d\n", digits);
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

int in_str (char c, char *str)
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

unsigned long long int get_abs(long long int val)
{
	if (val < 0)
		return (-val);
	return (val);
}

char *rev_str(char *str)
{
	int i = 0, len = _strlen(str), index = len - 1;
	char *rev = NULL;

	rev = malloc((len + 1) * sizeof(char));
	if (rev == NULL)
		return (rev);

	for (; i <= index; i++)
		rev[i] = str[index - i];
	rev[i] = '\0';
	return (rev);
}

char *prepend_x(unsigned long long dig, char x_case)
{
	char *tmp_hex = NULL, *res_hex = NULL;
	int len = 0, i = 2;

	tmp_hex = uint_to_hex(dig, x_case);
	if (tmp_hex == NULL)
		return (tmp_hex);
	tmp_hex = (void *)tmp_hex;
	len = _strlen(tmp_hex);
	res_hex = malloc((len + 3) * sizeof(char));
	if (res_hex == NULL)
		return (tmp_hex);
	res_hex[0] = '0';
	res_hex[1] = 'x';

	for (; tmp_hex[i - 2] != '\0'; i++)
		res_hex[i] = tmp_hex[i - 2];
	res_hex[i] = '\0';

	return (res_hex);
}
int _max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

char *non_print_x(long int num)
{
	char *res_hex = NULL, *ret_hex = NULL;
	int res_len, i = 0;

	res_hex = uint_to_hex(num, 'X');
	if (res_hex == NULL)
		return (res_hex);
	res_len = _strlen(res_hex);
	if (res_len == 1)
	{
		ret_hex = malloc(3 * sizeof(char));
		if (ret_hex == NULL)
			return (ret_hex);
		ret_hex[0] = '0';
		ret_hex[1] = res_hex[0];
		ret_hex[2] = '\0';
	}
	else
	{
		ret_hex = malloc((res_len + 1) * sizeof(char));
		if (ret_hex == NULL)
			return (ret_hex);
		for (; res_hex[i] != '\0'; i++)
			ret_hex[i] = res_hex[i];
		ret_hex[res_len] = '\0';
	}

	free(res_hex);
	return (ret_hex);
}
