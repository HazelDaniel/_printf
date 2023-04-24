/**
 * is_digit - a function that checks if a
 * character is convertible to digit
 * @c: the character parameter
 * Return: 1 or 0
 **/
int is_digit(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}
