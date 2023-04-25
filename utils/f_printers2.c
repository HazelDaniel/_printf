#include "main.h"
#include <stdio.h>


int print_non_print(va_list va_args, int index, char *flag,
	int width, int precision, int length, char specifier)
{
	char *next, *np_str = NULL;
	int stop = 1, i = 0, k = 0, len, b_len;

	next = va_arg(va_args, char *);
	len = _strlen(next);

	for (; i < len; i++)
	{
		if (!is_print(next[i]))
		{
			np_str = itoa((int)next[i]);
			stop = 2;
			write(1, "\\x", stop);
			b_len = _strlen(np_str);
			write(1, np_str, b_len);
			k += 2 + b_len;
			free(np_str);
		}
		else
		{
			stop = 1;
			write(1, &(next[i]), stop);
			k += 1;
		}
	}
	return (k);
}
/*
	Edge case - i don't know control characters are considered non printable
*/

int print_unsigned(va_list va_args, int index, char *flag,
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
		next = va_arg(va_args, unsigned long int);
	}
	str_next = itoa(get_abs(next));
	if (str_next == NULL)
		return (-1);
	b_len = _strlen(str_next);
	write_bytes(str_next, (int *)&b_len);
	
	free(flags_net);
	free(p_buffer);
	free(str_next);
	return (b_len);
}

int print_octal(va_list va_args, int index, char *flag,
	int width, int precision, int length, char specifier)
{
	char *str_next = NULL;
	long int next, b_len;
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
		next = va_arg(va_args, unsigned long int);
	}
	str_next = uint_to_octal(next);
	b_len = _strlen(str_next);
	write_bytes(str_next, (int *)&b_len);
	free(str_next);
	return (b_len);
}
