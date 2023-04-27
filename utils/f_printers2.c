#include "main.h"
#include <stdio.h>


int print_non_print(va_list va_args, int index, char *flag,
	int width, int precision, int length, char specifier)
{
	char *next, *np_str = NULL, buffer[1024] = "",
	*hex_tmp = NULL, *meg_str[1024];
	int stop = 1, i = 0, ind = 0, k = 0, len, b_len,
	free_ind = 0;

	next = va_arg(va_args, char *);
	len = _strlen(next);

	for (; i < len; i++)
	{
		if (!is_print(next[i]))
		{
			np_str = non_print_x((int)next[i]);
			if (np_str == NULL)
				for (free_ind = 0; meg_str[free_ind];)
					free(meg_str[free_ind++]);
			stop = 2;
			write(1, "\\x", stop);
			b_len = _strlen(np_str);
			write(1, np_str, b_len);
			k += 2 + b_len;
			meg_str[ind] = np_str;
			ind++;
		}
		else
		{
			stop = 1;
			write(1, &(next[i]), stop);
			k += 1;
		}
	}
	for (; ind >= 0;)
		free(meg_str[ind--]);

	return (k);
}

int print_unsigned(va_list va_args, int index, char *flag,
	int width, int precision, int length, char specifier)
{
	char *flags_net = get_important_flags(flag), *pad_string = NULL,
	*p_buffer = NULL, *str_next = NULL;
	long int next, b_len;
	int is_negative = 0, i, j = 0, k = 0;
	fm_int_t int_formatted;

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
	b_len = fm_write_int(flags_net, str_next, width, precision, 0, 0);

	return (b_len);
}

int print_octal(va_list va_args, int index, char *flag,
	int width, int precision, int length, char specifier)
{
	char *str_next = NULL, *flags_net = get_important_flags(flag);
	long int next, b_len;
	fm_int_t int_formatted;

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
	b_len = fm_write_int(flags_net, str_next, width, precision, 1, 0);
	return (b_len);
}
