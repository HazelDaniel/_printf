#include "main.h"
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
