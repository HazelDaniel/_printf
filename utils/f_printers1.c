#include "main.h"
#include <stdio.h>

int print_bin(va_list va_args, int index, char *flag,
	int width, int precision, int length, char specifier)
{
	char *flags_net = get_important_flags(flag), *pad_string = NULL,
	*p_buffer = NULL, *str_next = NULL;
	long int next, b_len;

	next = va_arg(va_args, long long int);
	next = get_abs(next);
	p_buffer = uint_to_bin(next); b_len = _strlen(p_buffer);
	write_bytes(p_buffer, (int *)&b_len);
	free(p_buffer);
	return (b_len);
}

int print_int(va_list va_args, int index, char *flag,
	 int width, int precision, int length, char specifier)
{
	char *flags_net = get_important_flags(flag), *pad_string = NULL,
	*p_buffer = NULL, *str_next = NULL;
	long int next, b_len;
	int is_negative = 0, i, j = 0, k = 0;
	fm_int_t int_formatted;

	// printf("flags: %d\t, width : %d\t, precision : %d\t, length : %d\t, specifier : %c\n", _strlen(flags_net), width, precision, length, specifier);
	if (length)
	{
		switch (length)
		{
		case SHORT_SIZE:
			next = va_arg(va_args, int);
			break;
		case LONG_SIZE:
			next = va_arg(va_args, long int);
			break;
		}
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
		/* 1 for the null byte and 1 for the extra sign */
		if (p_buffer == NULL)
		{
			free(str_next);
			return (-1);
		}
		p_buffer[0] = '-';
		p_buffer[_strlen(str_next)] = '\0';
		for (; str_next[j] != '\0'; )
			p_buffer[++k] = str_next[j++];
		b_len = _strlen(p_buffer);
		write_bytes(p_buffer, (int *)&b_len);
	}
	else
	{
		b_len = _strlen(str_next);
		write_bytes(str_next, (int *)&b_len);
	}
	
	free(flags_net);
	free(p_buffer);
	free(str_next);
	return (b_len);
}

int print_x_upper(va_list va_args, int index, char *flag,
	int width, int precision, int length, char specifier)
{
	char *flags_net = get_important_flags(flag), *pad_string = NULL,
	*p_buffer = NULL, *str_next = NULL;
	long int next, b_len;
	int is_negative = 0, i, j = 0, k = 0;
	fm_hex_t hex_formatted;

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
	b_len = _strlen(str_next);
	write_bytes(str_next, (int *)&b_len);
	
	free(flags_net);
	free(p_buffer);
	free(str_next);
	return (b_len);
}

int print_pointer(va_list va_args, int index, char *flag,
	int width, int precision, int length, char specifier)
{
	char *flags_net = get_important_flags(flag), *pad_string = NULL,
	*p_buffer = NULL, *str_next = NULL;
	long int next, b_len;
	int is_negative = 0, i, j = 0, k = 0;
	fm_addr_t addr_formatted;

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
	b_len = _strlen(str_next);
	write_bytes(str_next, (int *)&b_len);
	
	free(flags_net);
	free(p_buffer);
	free(str_next);
	return (b_len);
}
/*
	Edge case : Cannot print very large addresses 
 */
