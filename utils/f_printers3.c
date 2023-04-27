#include "main.h"
#include <stdio.h>


int print_x_lower(va_list va_args, int index, char *flag,
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
	str_next = uint_to_hex(next, 'x');
	if (str_next == NULL)
		return (-1);
	b_len = fm_write_hex(flags_net, str_next, width, precision);
	
	return (b_len);
}

int print_char(va_list va_args, int index, char *flag,
	int width, int precision, int length, char specifier)
{
	char next, *next_buffer = NULL,
	*flags_net = get_important_flags(flag);
	int b_len = 1;

	next = va_arg(va_args, int);
	next_buffer = malloc(2 * sizeof(char));
	if (next_buffer == NULL)
		return (-1);
	next_buffer[1] = '\0';
	next_buffer[0] = next;
	b_len = fm_write_char(flags_net, next_buffer, width);

	return (b_len);
}

int print_string(va_list va_args, int index, char *flag,
	int width, int precision, int length, char specifier)
{
	char *next, *flags_net = get_important_flags(flag),
	*w_buffer = NULL;
	int b_len, i = 0;

	next = va_arg(va_args, char *);
	b_len = _strlen(next);
	w_buffer = malloc((b_len + 1) * sizeof(char));
	if (w_buffer == NULL)
		return (-1);
	
	for (; next[i] != '\0'; i++)
		w_buffer[i] = next[i];
	w_buffer[i] = '\0';

	b_len = fm_write_str(flags_net, next, width, precision);
	return (b_len);
}

int print_reverse(va_list va_args, int index, char *flag,
	int width, int precision, int length, char specifier)
{
	char *next, *rev_next;
	int b_len;

	next = va_arg(va_args, char *);
	rev_next = rev_str(next);
	b_len = _strlen(rev_next);
	write_bytes(rev_next, (int *)&b_len);
	free(rev_next);
	return (b_len);
}

int print_rot13(va_list va_args, int index, char *flag,
	int width, int precision, int length, char specifier)
{
	char *next, *r13_tmp;
	char text[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char map[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i = 0, j = 0, k = 0, len;

	next = va_arg(va_args, char *);
	len = _strlen(next);
	r13_tmp = malloc((len + 1) * sizeof(char));
	if (r13_tmp == NULL)
		return (-1);
	for (; i < len; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (next[i] == text[j])
			{
				r13_tmp[k] = map[j];
				k++;
			}
			else if (!is_alpha(next[i]))
			{
				r13_tmp[k++] = next[i++];
			}
		}
	}
	r13_tmp[len] = '\0';
	i = len;
	write_bytes(r13_tmp, (int *)&i);
	return (len);
}
