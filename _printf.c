#include "main.h"
#include <stdio.h>
#include "utils/uint_to_bin.c"
#include "utils/uint_to_hex.c"
#include "utils/dig_count.c"
#include "utils/itoa.c"
#include "utils/itoc.c"
#include "utils/is_flag.c"
#include "utils/get_flags.c"
#include "utils/_strlen.c"
#include "utils/write_bytes.c"
#include "utils/get_width.c"
#include "utils/get_precision.c"
#include "utils/is_digit.c"
#include "utils/atoi.c"
#include "utils/get_length.c"
#include "utils/get_specifier.c"

int _printf(const char *format, ...)
{
	va_list va_args;
	int index, format_mode, printed_chars, b_print_len = 1;
	char status[1] = "1", curr_char;
	char* flags = NULL, **flags_list = NULL, **width_list,
	**precision_list = NULL, **length_list = NULL,
	**specifier_list = NULL, specifier = '\0';
	int width, precision, length, i, k;

	va_start(va_args, format);
	while (format[index] != '\0')
	{
		width = 0, length = 0, precision = 0, i = 0, k = 0,
		specifier = '\0';
		curr_char = format[index];
		if (curr_char != '%')
		{
			format_mode = 0;
		}
		else
		{
			index++;
			format_mode = 1;
		}
		if (format_mode == 0)
		{
			write_bytes(&curr_char, &b_print_len);
			b_print_len = 1;
			printed_chars++;
		}
		else
		{
			while (format_mode == 1 && format[index] != '\0')
			{
				flags_list = get_flags((char *)format, &index);
				if (flags_list == NULL)
				{
					free(flags_list);
					status[0] = '0';
					return (-1);
				}
				status[0] = flags_list[0][0];
				flags = flags_list[1];
				if (status[0] == '1')
				{
					index++, curr_char = format[index];
					width_list = get_width(va_args, (char *)format, &index);
					status[0] = width_list[0][0];
					if (width_list[1])
						width = _atoi(width_list[1]);
				}
				else
				{
					format_mode = '0';
					break;
				}
				if (status[0] == '1')
				{
					index++, curr_char = format[index];
					precision_list = get_precision(va_args, (char *)format, &index);
					status[0] = precision_list[0][0];
					if (precision_list[1])
						precision = _atoi(precision_list[1]);
					// printf("flags: %s\nwidth: %d\nprecision: %d\n", flags, width, precision);
				}
				else
				{
					format_mode = '0';
					break;
				}
				if (status[0] == '1')
				{
					index++, curr_char = format[index];
					length_list = get_length(va_args, (char *)format, &index);
					status[0] = length_list[0][0];
					// printf("flags: %s\nwidth: %d\nprecision: %d\nlength: %s\n", flags, width, precision, length_list[1]);
					if (length_list[1])
						length = _atoi(length_list[1]);
				}
				else
				{
					format_mode = '0';
					break;
				}
				if (status[0] == '1')
				{
					specifier_list = get_specifier(va_args, (char *)format, &index);
					status[0] = specifier_list[0][0];
					if (specifier_list[1])
							specifier = specifier_list[1][0];
					printf("flags: %s\nwidth: %d\nprecision: %d\nlength: %d\nspecifier: %c\n", flags, width, precision, length, specifier);
				}
				else
				{
					format_mode = '0';
					break;
				}
				if (status[0] == '1' && specifier != '\0')
				{
					format_mode = '0';
				}
			}
		}
		index++;
	}
	va_end(va_args);

	free(flags_list);
	free(width_list);
	free(precision_list);
	free(length_list);
	free(specifier_list);
	return (0);
}
