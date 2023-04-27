#include "main.h"
#include <stdio.h>

/**
  * print_bin - a function that prints a binary number
	* from an input integer string
  * @va_args: parameter of type va_list .
  * @index: parameter of type int .
  * @flag: parameter of type char *.
  * @width: parameter of type int .
  * @precision: parameter of type int .
  * @length: parameter of type int .
  * @specifier: parameter of type char .
  * Return: int .
 */
int print_bin(va_list va_args, int index, char *flag,
	int width, int precision, int length, char specifier)
{
	char *flags_net = get_important_flags(flag), *pad_string = NULL,
	*p_buffer = NULL, *str_next = NULL;
	long int next, b_len;

	next = va_arg(va_args, long long int);
	next = get_abs(next);
	p_buffer = uint_to_bin(next);
	b_len = _strlen(p_buffer);
	write_bytes(p_buffer, (int *)&b_len);
	free(p_buffer);
	return (b_len);
}

/**
  * print_int - a function that formats an integer
	* from an input integer string
  * @va_args: parameter of type va_list .
  * @index: parameter of type int .
  * @flag: parameter of type char *.
  * @width: parameter of type int .
  * @precision: parameter of type int .
  * @length: parameter of type int .
  * @specifier: parameter of type char .
  * Return: int .
 */
int print_int(va_list va_args, int index, char *flag,
	 int width, int precision, int length, char specifier)
{
	char *flags_net = get_important_flags(flag), *pad_string = NULL,
	*p_buffer = NULL, *str_next = NULL;
	long int next, b_len;
	int is_negative = 0, i, j = 0, k = 0;

	if (length)
	{
		if (length == SHORT_SIZE)
			next = va_arg(va_args, int);
		else if (length == LONG_SIZE)
			next = va_arg(va_args, long int);
	}
	else
	{
		next = va_arg(va_args, int);
	}
	str_next = itoa(get_abs(next));
	if (str_next == NULL)
		return (-1);
	if (next < 0)
	{
		is_negative = 1;
		p_buffer = malloc((_strlen(str_next) + 1 + 1) * sizeof(char));
		if (p_buffer == NULL)
		{
			free(str_next);
			return (-1);
		}
		p_buffer[0] = '-', p_buffer[_strlen(str_next)] = '\0';
		for (; str_next[j] != '\0'; )
			p_buffer[++k] = str_next[j++];
		b_len = fm_write_int(flags_net, p_buffer, width, precision, 0, 0);
	}
	else
	{
		b_len = fm_write_int(flags_net, str_next, width, precision, 0, 0);
	}
	return (b_len);
}

/**
  * print_x_upper - a function that converts
	* an input integer string to hexadecimal
  * @va_args: parameter of type va_list .
  * @index: parameter of type int .
  * @flag: parameter of type char *.
  * @width: parameter of type int .
  * @precision: parameter of type int .
  * @length: parameter of type int .
  * @specifier: parameter of type char .
  * Return: int .
 */
int print_x_upper(va_list va_args, int index, char *flag,
	int width, int precision, int length, char specifier)
{
	char *flags_net = get_important_flags(flag), *pad_string = NULL,
	*p_buffer = NULL, *str_next = NULL;
	long int next, b_len;
	int is_negative = 0, i, j = 0, k = 0;

	if (length)
	{
		switch (length)
		{
		case SHORT_SIZE:
			next = va_arg(va_args, unsigned int);
			break;
		case LONG_SIZE:
			next = va_arg(va_args, unsigned long int);
			break;
		}
	}
	else
	{
		next = va_arg(va_args, unsigned int);
	}
	str_next = uint_to_hex(next, 'X');
	if (str_next == NULL)
		return (-1);
	b_len = fm_write_hex(flags_net, str_next, width, precision);

	return (b_len);
}

/**
  * print_pointer - a function that converts an input
	* pointer string to it's address form
  * @va_args: parameter of type va_list .
  * @index: parameter of type int .
  * @flag: parameter of type char *.
  * @width: parameter of type int .
  * @precision: parameter of type int .
  * @length: parameter of type int .
  * @specifier: parameter of type char .
  * Return: int .
 */
int print_pointer(va_list va_args, int index, char *flag,
	int width, int precision, int length, char specifier)
{
	char *flags_net = get_important_flags(flag), *pad_string = NULL,
	*p_buffer = NULL, *str_next = NULL;
	long int next, b_len;
	int is_negative = 0, i, j = 0, k = 0;

	if (length)
	{
		switch (length)
		{
		case SHORT_SIZE:
			next = va_arg(va_args, unsigned int);
			break;
		case LONG_SIZE:
			next = va_arg(va_args, unsigned long int);
			break;
		}
	}
	else
	{
		next = va_arg(va_args, unsigned long long int);
	}
	str_next = prepend_x(next, 'x');
	if (str_next == NULL)
		return (-1);

	b_len = fm_write_addr(flags_net, str_next, width);

	return (b_len);
}
/* Edge case : Cannot print very large addresses */
