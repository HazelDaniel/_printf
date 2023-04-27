#include "main.h"

/**
 * write_bytes - a function that prints
 * a number of bytes to stdout
 * @bytes: the address of the first byte
 * @end_addr: what to print up to.
 * Return: int
 **/
int write_bytes(char *bytes, int *end_addr)
{
	int temp = *end_addr;

	if (temp > 0)
		write(1, bytes, *end_addr);
	*end_addr = temp;
	return (temp);
}

/**
 * _strlen - a function that computes the
 * length of a string
 * @c: the string
 * Return: int
 **/
int _strlen(char *c)
{
	int i = 0;

	if (c == NULL)
		return (-1);
	while (*(c + i) != '\0')
		i++;
	return (i);
}

/**
 * is_flag - a function that checks if a
 * character is a flag
 * @c: the test character
 * @hash_addr: address of the flag hash
 * Return: array of int
 **/
int *is_flag(char c, flag_t hash_addr[])
{
	int i = 0, first_index = 0;
	int *flags_ret = malloc(2 * sizeof(int));

	if (flags_ret == NULL)
		return (flags_ret);

	while (((hash_addr)[i]).flag)
	{
		if (c == ((hash_addr)[i]).flag)
		{
			flags_ret[0] = 1;
			first_index = i;
			break;
		}
		else
		{
			flags_ret[0] = 0;
		}
		i++;
	}
	i--;
	if (flags_ret[0] == 0)
		flags_ret[1] = -1;
	else
		flags_ret[1] = first_index;
	return (flags_ret);
}

/**
  * non_print_x - a function that
	* checks for non-printable characters
	* in a string and replaces them with their
	* ascii value prepended by '\x'
  * @num: parameter of type long int .
  * Return: char *.
 */
char *non_print_x(long int num)
{
	char *res_hex = NULL, *ret_hex = NULL;
	int res_len, i = 0;

	res_hex = uint_to_hex(num, 'X');
	if (res_hex == NULL)
		return (res_hex);
	res_len = _strlen(res_hex);
	if (res_len == 1)
	{
		ret_hex = malloc(3 * sizeof(char));
		if (ret_hex == NULL)
			return (ret_hex);
		ret_hex[0] = '0';
		ret_hex[1] = res_hex[0];
		ret_hex[2] = '\0';
	}
	else
	{
		ret_hex = malloc((res_len + 1) * sizeof(char));
		if (ret_hex == NULL)
			return (ret_hex);
		for (; res_hex[i] != '\0'; i++)
			ret_hex[i] = res_hex[i];
		ret_hex[res_len] = '\0';
	}

	free(res_hex);
	return (ret_hex);
}

/**
  * prepend_x - a function that prepends a '0x'
	* before a hex digit
  * @dig: parameter of type unsigned long long .
  * @x_case: parameter of type char .
  * Return: char *.
 */
char *prepend_x(unsigned long long dig, char x_case)
{
	char *tmp_hex = NULL, *res_hex = NULL;
	int len = 0, i = 2;

	tmp_hex = uint_to_hex(dig, x_case);
	if (tmp_hex == NULL)
		return (tmp_hex);
	tmp_hex = (void *)tmp_hex;
	len = _strlen(tmp_hex);
	res_hex = malloc((len + 3) * sizeof(char));
	if (res_hex == NULL)
		return (tmp_hex);
	res_hex[0] = '0';
	res_hex[1] = 'x';

	for (; tmp_hex[i - 2] != '\0'; i++)
		res_hex[i] = tmp_hex[i - 2];
	res_hex[i] = '\0';

	return (res_hex);
}
