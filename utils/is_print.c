/**
 * is_print - a function that checks if a
 * character is printable
 * @c: the character parameter
 * Return: 1 or 0
 **/
int is_print(char c)
{
	if (c <= 126 && c >= 32)
		return (1);
	return (0);
}
