#include "main.h"
#include <stdio.h>

/* SUB UTILS */
char flag_sign_or_space(int is_signed, int is_force_spaced, int is_force_signed);
/*TODO: FREE ALL FLAGS AND BUFFERS PASSED IN THE FUNCTIONS */

int fm_write_int(char *flags, char *buffer, int width,
	int precision, int is_octal, int is_hex)
{
	/* NO SUPPORT FOR HASH FLAGS IN INT */
	/* use this same function as the underlying for all other integer types
	 you could pass arguments for specific functionalities (if any)*/
	int net_len, buff_len, is_justified = in_str('-', flags),
	is_signed = buffer[0] == '-', is_force_signed = in_str('+', flags),
	is_force_spaced = in_str(' ', flags),
	is_force_prefix = in_str('#', flags), print_none = 0;
	char *zero_pad = NULL, *space_pad = NULL, write_buff[1024] = "",
	dig_buff[1024] = "";
	int i = 0, j = 0, s_pad_num, z_pad_num;

	buff_len = _strlen(buffer);
	if (is_signed)
		buff_len--;
	if (is_octal || is_hex)
	{
		is_signed = 0;
		is_force_signed = 0;
		is_force_spaced = 0;
	}
	/* this is because we are going to prepend the
	 * minus sign into another buffer - which is a resulting */
	if (!precision && buff_len == 1 && buffer[0] == '0'
		&& !(is_octal || is_hex))
	{
		print_none = 1;
		goto no_print;
	}
	if (_max(width, precision) > buff_len)
	{
		if (precision > buff_len)
		{
			z_pad_num = precision - buff_len;
			zero_pad = malloc((z_pad_num + 1) * sizeof(char));
			if (zero_pad == NULL)
				return (-1);
			zero_pad[z_pad_num] = '\0';
			while (i < z_pad_num)
				zero_pad[i++] = '0';
			// todo: append result from left using zero pad
		}
		if (width > precision)
		{
			if (!precision)
				s_pad_num = get_abs(width - buff_len);
			else
				s_pad_num = width - precision;

			if (is_octal && s_pad_num >= 1 && is_force_prefix)
				s_pad_num--;
			if (is_hex && s_pad_num >= 2 && is_force_prefix)
				s_pad_num -= 2;

			if ((is_signed || is_force_signed || is_force_spaced) && s_pad_num > 1)
			{
				s_pad_num--;
			}
			space_pad = malloc((s_pad_num + 1) * sizeof(char));
			if (space_pad == NULL)
				return (-1);
			space_pad[s_pad_num] = '\0';
			while (j < s_pad_num)
				space_pad[j++] = ' ';
			// todo : check for justify flag
		}
		i = 0;
		if (is_force_signed || is_force_spaced || is_signed)
		{
			dig_buff[0] = flag_sign_or_space(is_signed, is_force_spaced, is_force_signed);
			i++;
		}
		else
		{
			if (is_force_prefix)
			{
				if (is_octal && !z_pad_num)
				{
					dig_buff[0] = '0';
					i++;
				}
				else if (is_hex && z_pad_num < 2)
				{
					dig_buff[0] = '0';
					dig_buff[1] = 'x';
					i+=2;
				}

			}
		}
	}
	else
	{
		if (is_signed)
		{
			dig_buff[0] = '-';
			i++;
		}
		else if (is_force_spaced)
		{
			dig_buff[0] = ' ';
			i++;
		}
		if (is_force_prefix)
		{
			if (is_octal && !z_pad_num)
			{
				dig_buff[0] = '0';
				i++;
			}
			else if (is_hex && z_pad_num < 2)
			{
				dig_buff[0] = '0';
				dig_buff[1] = 'x';
				i+=2;
			}
		}
	}
	if (precision && zero_pad)
	{
		for (j = 0; zero_pad[j] != '\0'; i++, j++)
			dig_buff[i] = zero_pad[j];
	}
	for (j = 0; buffer[j] != '\0'; i++, j++)
	{
		if (buffer[j] == '-')
			j++;
		dig_buff[i] = buffer[j];
	}
	i = 0, j = 0;

	if (is_justified)
	{
		for (; dig_buff[i] != '\0'; i++)
			write_buff[i] = dig_buff[i];
		if (!space_pad)
			goto no_sp;
		for (; space_pad[j] != '\0'; i++, j++)
			write_buff[i] = space_pad[j];
		no_sp:
			;
	}
	else
	{
		if (!space_pad)
			goto no_sp1;
		for (; space_pad[j] != '\0'; i++, j++)
			write_buff[i] = space_pad[j];
		no_sp1:
			;
		for (j = 0; dig_buff[j] != '\0'; j++, i++)
			write_buff[i] = dig_buff[j];
	}
	net_len = _strlen(write_buff);
	write_bytes(write_buff, &net_len);
no_print:
	if (print_none == 1)
	{
		net_len = 1;
		write_bytes("\n", &net_len);
	}
	free(zero_pad);
	free(space_pad);
	free(buffer);
	free(flags);

	return (net_len);
}

int fm_write_str(char *flags, char *buffer, int width,
	int precision)
{
	/* NO SUPPORT FOR HASH FLAGS IN INT */
	int net_len, buff_len, is_justified = in_str('-', flags);
	char *space_pad = NULL, write_buff[1024] = "",
	dig_buff[1024] = "";
	int i = 0, j = 0, s_pad_num = 0;

	buff_len = _strlen(buffer);
	if (_max(width, precision) > buff_len)
	{
		if (width > precision)
		{
			if (!precision)
				s_pad_num = get_abs(width - buff_len);
			else
				s_pad_num = width - precision;
			space_pad = malloc((s_pad_num + 1) * sizeof(char));
			if (space_pad == NULL)
				return (-1);
			space_pad[s_pad_num] = '\0';
			while (j < s_pad_num)
				space_pad[j++] = ' ';
			// todo : check for justify flag
		}
		i = 0;
	}
	else
	{
		if (precision < buff_len && width)
		{
			if (width == buff_len)
				s_pad_num = width - precision;
			else if (width < buff_len)
				s_pad_num = precision;
			space_pad = malloc((s_pad_num + 1) * sizeof(char));
			if (space_pad == NULL)
				return (-1);
			space_pad[s_pad_num] = '\0';
			while (j < s_pad_num)
				space_pad[j++] = ' ';
		}
	}
	if (precision < buff_len && precision != 0)
	{
			for (j = 0; j < precision; i++, j++)
				dig_buff[i] = buffer[j];
	}
	else
	{
		for (j = 0; buffer[j] != '\0'; i++, j++)
			dig_buff[i] = buffer[j];
	}
	i = 0, j = 0;

	if (is_justified)
	{
		for (; dig_buff[i] != '\0'; i++)
			write_buff[i] = dig_buff[i];
		if (!space_pad)
			goto no_sp;
		for (; space_pad[j] != '\0'; i++, j++)
			write_buff[i] = space_pad[j];
		no_sp:
			;
	}
	else
	{
		if (!space_pad)
			goto no_sp1;
		for (; space_pad[j] != '\0'; i++, j++)
			write_buff[i] = space_pad[j];
		no_sp1:
			;
		for (j = 0; dig_buff[j] != '\0'; j++, i++)
			write_buff[i] = dig_buff[j];
	}
	net_len = _strlen(write_buff);
	write_bytes(write_buff, &net_len);
	free(space_pad);
	free(buffer);
	free(flags);
	return (net_len);
}

int fm_write_char(char *flags, char *buffer, int width)
{

	int net_len, buff_len, is_justified = in_str('-', flags);
	char *space_pad = NULL, write_buff[1024] = "",
	dig_buff[1024] = "";
	int i = 0, j = 0, s_pad_num = 0;

	buff_len = _strlen(buffer);
	if (width > buff_len)
	{
		s_pad_num = get_abs(width - buff_len);
		space_pad = malloc((s_pad_num + 1) * sizeof(char));
		if (space_pad == NULL)
			return (-1);
		space_pad[s_pad_num] = '\0';
		while (j < s_pad_num)
			space_pad[j++] = ' ';
		i = 0;
	}
	else
	{
		if (width)
		{
			if (width == buff_len)
				s_pad_num = width;
			else if (width == 0)
				s_pad_num = width;
			space_pad = malloc((s_pad_num + 1) * sizeof(char));
			if (space_pad == NULL)
				return (-1);
			space_pad[s_pad_num] = '\0';
			while (j < s_pad_num)
				space_pad[j++] = ' ';
		}
	}
	for (j = 0; buffer[j] != '\0'; i++, j++)
		dig_buff[i] = buffer[j];
	i = 0, j = 0;

	if (is_justified)
	{
		for (; dig_buff[i] != '\0'; i++)
			write_buff[i] = dig_buff[i];
		if (!space_pad)
			goto no_sp;
		for (; space_pad[j] != '\0'; i++, j++)
			write_buff[i] = space_pad[j];
		no_sp:
			;
	}
	else
	{
		if (!space_pad)
			goto no_sp1;
		for (; space_pad[j] != '\0'; i++, j++)
			write_buff[i] = space_pad[j];
		no_sp1:
			;
		for (j = 0; dig_buff[j] != '\0'; j++, i++)
			write_buff[i] = dig_buff[j];
	}
	net_len = _strlen(write_buff);
	write_bytes(write_buff, &net_len);
	free(space_pad);
	free(buffer);
	free(flags);
	return (net_len);
}

int fm_write_hex(char *flags, char *buffer, int width,
	int precision)
{
	return fm_write_int(flags, buffer, width, precision, 0, 1);
}

int fm_write_octal(char *flags, char *buffer, int width,
	int precision)
{
	return fm_write_int(flags, buffer, width, precision, 1, 0);
}

int fm_write_addr(char *flags, char *buffer, int width)
{
	return (fm_write_str(flags, buffer, width, 0));
}
char flag_sign_or_space(int is_signed, int is_force_spaced, int is_force_signed)
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
