#include "main.h"

/**
  * rev_str - a function that reverses a string
  * @str: parameter of type char *.
  * Return: char *.
 */
char *rev_str(char *str)
{
	int i = 0, len = _strlen(str), index = len - 1;
	char *rev = NULL;

	rev = malloc((len + 1) * sizeof(char));
	if (rev == NULL)
		return (rev);

	for (; i <= index; i++)
		rev[i] = str[index - i];
	rev[i] = '\0';
	return (rev);
}

/**
  * _max - a function that returns
	* the maximum of two numbers
  * @a: parameter of type int .
  * @b: parameter of type int .
  * Return: int .
 */
int _max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
