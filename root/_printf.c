#include "main.h"
#include <stdio.h>
#include "utils/uint_to_bin.c"
#include "utils/uint_to_hex.c"
#include "utils/uint_to_octal.c"
#include "utils/get_flags.c"
#include "utils/utils2.c"
#include "utils/utils3.c"
#include "utils/utils4.c"
#include "utils/get_width.c"
#include "utils/get_precision.c"
#include "utils/get_length.c"
#include "utils/get_specifier.c"
#include "utils/handle_print.c"
#include "utils/f_printers1.c"
#include "utils/f_printers2.c"
#include "utils/f_printers3.c"
#include "utils/field_utils.c"
#include "utils/cast_utils.c"
#include "utils/utils.c"
#include "utils/spec_write_handlers.c"
#include "utils/spec_write_handlers2.c"

void free_main_strings(char **flags_list, char **width_list,
	char **precision_list, char **length_list, char **specifier_list);
void free_gen_strings(char **flags_list, char **width_list,
	char **precision_list, char **length_list, char **specifier_list);
void handle_width(char *flags, int *ind_ptr, int *width_ptr, char *format,
		char ***width_list_ptr, char *curr_char_ptr,
		char status[], va_list va_args);
void handle_precision(int width, int *ind_ptr, int *prec_ptr, char *format,
		char ***prec_list_ptr, char *curr_char_ptr,
		char status[], va_list va_args);
void handle_length(int precision, int *ind_ptr, int *len_ptr, char *format,
		char ***len_list_ptr, char *curr_char_ptr,
		char status[], va_list va_args);
void handle_specifier(int *ind_ptr, char *spec_ptr, char *format,
		char ***spec_list_ptr, char status[], va_list va_args);

int _printf(const char *format, ...)
{
	va_list va_args;
	int index = 0, format_mode = 0, printed_chars = 0, b_print_len;
	char status[1] = {'1'}, curr_char,
	*flags = NULL, **flags_list = NULL, **width_list = NULL,
	**precision_list = NULL, **length_list = NULL,
	**specifier_list = NULL, specifier = '\0';
	int width, precision, length, i = 0, format_start, j = 0;
	int jump_back = 0;

	va_start(va_args, format);
	while (format[index] != '\0')
	{
		width = 0, length = 0, precision = 0;
		b_print_len = 1, specifier = '\0';
		curr_char = format[index];

		if (jump_back)
			goto jump_block;
		if (curr_char != '%')
		{
			format_mode = 0;
		}
		else
		{
			index++;
			if (index > 0 && format[index - 1] == '%'
				&& format[index] == '%')
			{
				index --;
			}
			format_mode = 1;
			format_start = index;
		}
jump_block:
		if (jump_back && index > 0 && format[index - 1] == '%')
		{
			index--;
			write_bytes((char *)&(format[index]), &b_print_len);
			printed_chars += b_print_len;
			index++;
		}
		if (format_mode == 0)
		{
			write_bytes(&curr_char, &b_print_len);
			printed_chars += b_print_len;
		}
		else
		{
			while (format_mode == 1 && format[index] != '\0')
			{
				flags_list = get_flags((char *)format, &index);
				if (flags_list == NULL)
				{
					status[0] = '0';
					return (-1);
				}
				status[0] = flags_list[0][0];
				flags = flags_list[1];
				if (status[0] == '1')
				{
					handle_width(flags, &index, &width, (char *)format,
						&width_list, &curr_char, status, va_args);
				}
				else
				{
					format_mode = 0; break;
				}
				if (status[0] == '1')
				{
					handle_precision(width, &index, &precision, (char *)format,
						 &precision_list, &curr_char, status, va_args);
				}
				else
				{
					format_mode = 0; break;
				}
				if (status[0] == '1')
				{
					handle_length(precision, &index, &length, (char *)format,
						&length_list, &curr_char, status, va_args);
				}
				else
				{
					format_mode = 0; break;
				}
				if (status[0] == '1')
				{
					specifier_list = get_specifier(va_args, (char *)format, &index);
					status[0] = specifier_list[0][0];
					if (specifier_list[1])
							specifier = specifier_list[1][0];
				}
				else
				{
					format_mode = 0; break;
				}
				if (status[0] == '1')
				{
					if (specifier != '\0')
					{
						printed_chars += handle_print(va_args, index,
						 flags, width, precision, length, specifier);

						free_gen_strings(flags_list, width_list,
							precision_list, length_list, specifier_list);
					}
					else
					{
						index = format_start > 0 ? format_start - 1 : format_start;
						format_mode = 0;
						jump_back = 1;
						free_gen_strings(flags_list, width_list,
							precision_list, length_list, specifier_list);
					}
					format_mode = 0;
				}
			}
			free_main_strings(flags_list, width_list,
				precision_list, length_list, specifier_list);
		}
		index++;
	}
	va_end(va_args);

	return (printed_chars);
}


void free_main_strings(char **flags_list, char **width_list,
	char **precision_list, char **length_list, char **specifier_list)
{
	free(flags_list);
	free(width_list);
	free(precision_list);
	free(length_list);
	free(specifier_list);
}
void free_gen_strings(char **flags_list, char **width_list,
	char **precision_list, char **length_list, char **specifier_list)
{
	free(flags_list[0]);
	free(flags_list[1]);
	free(width_list[0]);
	free(width_list[1]);
	free(precision_list[0]);
	free(precision_list[1]);
	free(length_list[0]);
	free(length_list[1]);
	free(specifier_list[0]);
	free(specifier_list[1]);
}

//	JUST FOR READABILITY. THEY ARE STRICTLY MUTATING
void handle_precision(int width, int *ind_ptr, int *prec_ptr, char *format,
		char ***prec_list_ptr, char *curr_char_ptr,
		char status[], va_list va_args)
{
		if (width)
		(*ind_ptr)++;
	*curr_char_ptr = format[*ind_ptr];
	*prec_list_ptr = get_precision(va_args, (char *)format, ind_ptr);
	status[0] = (*prec_list_ptr)[0][0];
	if ((*prec_list_ptr)[1])
		*prec_ptr = _atoi((*prec_list_ptr)[1]);
}
void handle_width(char *flags, int *ind_ptr, int *width_ptr, char *format,
		char ***width_list_ptr, char *curr_char_ptr,
		char status[], va_list va_args)
{
		if (flags)
		(*ind_ptr)++;
	*curr_char_ptr = format[*ind_ptr];
	*width_list_ptr = get_width(va_args, (char *)format, ind_ptr);
	status[0] = (*width_list_ptr)[0][0];
	if ((*width_list_ptr)[1])
		*width_ptr = _atoi((*width_list_ptr)[1]);
}
void handle_length(int precision, int *ind_ptr, int *len_ptr, char *format,
		char ***len_list_ptr, char *curr_char_ptr,
		char status[], va_list va_args)
{
		if (precision)
		(*ind_ptr)++;
	*curr_char_ptr = format[*ind_ptr];
	*len_list_ptr = get_length(va_args, (char *)format, ind_ptr);
	status[0] = (*len_list_ptr)[0][0];
	if ((*len_list_ptr)[1])
		*len_ptr = _atoi((*len_list_ptr)[1]);
}
void handle_specifier(int *ind_ptr, char *spec_ptr, char *format,
		char ***spec_list_ptr, char status[], va_list va_args)
{
	//handle_specifier(&index, &specifier, (char *)format, &specifier_list, status, va_args);
					// specifier_list = get_specifier(va_args, (char *)format, &index);
					// status[0] = specifier_list[0][0];
					// if (specifier_list[1])
					// 		specifier = specifier_list[1][0];
	*spec_list_ptr = get_specifier(va_args, (char *)format, ind_ptr);
	status[0] = (*spec_list_ptr)[0][0];
	if ((*spec_list_ptr)[1])
		*spec_ptr = _atoi((*spec_list_ptr)[1]);
}
