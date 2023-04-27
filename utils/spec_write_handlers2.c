#include "main.h"

/** flag_sign_or_space - a sub-routine
 * of fm_write.* handlers
 * @is_signed: parameter of type int
 * @is_force_signed: parameter of type int
 * @is_force_spaced: parameter of type int
 * Return: char
 **/
char flag_sign_or_space(int is_signed,
	int is_force_spaced, int is_force_signed)
{
	if (is_force_signed)
	{
		if (is_signed)
			return ('-');
		else
			return ('+');
	}
	else if (is_force_spaced)/* because only one of these can occur at once */
	{
		if (is_signed)
			return ('-');
		else
			return (' ');
	}
	else if (is_signed)
	{
		return ('-');
	}
		return ('\0');
}

/**
  * fm_write_hex - a function that formats
	* to hexadecimal
  * @flags: parameter of type char *.
  * @buffer: parameter of type char *.
  * @width: parameter of type int .
  * @precision: parameter of type int .
  * Return: int .
 */
int fm_write_hex(char *flags, char *buffer, int width,
	int precision)
{
	return (fm_write_int(flags, buffer, width, precision, 0, 1));
}

/**
  * fm_write_octal - a function that formats
	* to octal
  * @flags: parameter of type char *.
  * @buffer: parameter of type char *.
  * @width: parameter of type int .
  * @precision: parameter of type int .
  * Return: int .
 */
int fm_write_octal(char *flags, char *buffer, int width,
	int precision)
{
	return (fm_write_int(flags, buffer, width, precision, 1, 0));
}

/**
  * fm_write_addr - a function that formats to an
	* object address
  * @flags: parameter of type char *.
  * @buffer: parameter of type char *.
  * @width: parameter of type int .
  * Return: int .
 */
int fm_write_addr(char *flags, char *buffer, int width)
{
	return (fm_write_str(flags, buffer, width, 0));
}
