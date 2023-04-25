#include "main.h"

int handle_print(va_list va_args, int index, char *flag,
	 int width, int precision, int length, char specifier)
{
	int i = 0, ind_tmp = index;
	spec_t opts[] = {
		{'s', print_string},{'d', print_int},
		{'i', print_int}, {'b', print_bin},
		{'X', print_x_upper}, {'p', print_pointer}, {'S', print_non_print},
		{'u', print_unsigned}, {'x', print_x_lower},
		{'c', print_char}, {'o', print_octal},
		{'r', print_reverse}, {'R', print_rot13}, {'\0', NULL}
	};

	for (; opts[i].spec != '\0'; i++)
		if (opts[i].spec == specifier)
			opts[i].fn(va_args, index, flag, width, precision, length, specifier);

	return (0);
}
