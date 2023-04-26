#include "main.h"
#include <stdio.h>

int fm_write_int(char *flags, char *buffer, int width,
	int precision);
int fm_write_str(char *flags, char *buffer, int width,
	int precision);
int fm_write_char(char *buffer, int width,
	int buff_len);
int fm_write_hex(char *buffer, int width,
	int precision, int buff_len);
int fm_write_addr(char *buffer, int width);


/* SUB UTILS */
char flag_sign_or_space(int is_signed, int is_force_spaced, int is_force_signed);

int fm_write_int(char *flags, char *buffer, int width,
	int precision)
{
	/* NO SUPPORT FOR HASH FLAGS IN INT */
	int net_len, buff_len, is_justified = in_str('-', flags),
	is_signed = buffer[0] == '-', is_force_signed = in_str('+', flags),
	is_force_spaced = in_str(' ', flags);
	char *zero_pad = NULL, *space_pad = NULL, write_buff[1024] = "",
	dig_buff[1024] = "";
	int i = 0, j = 0, s_pad_num, z_pad_num;

	buff_len = _strlen(buffer);
	if (is_signed)
		buff_len--;/* this is because we are going to prepend the minus sign later */
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
	free(zero_pad);
	free(space_pad);

	return (net_len);
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
