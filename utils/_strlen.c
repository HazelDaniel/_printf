#include "main.h"
#include <stdio.h>
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
