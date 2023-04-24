#include "main.h"

/**
 * dig_count - a function that counts
 * the number of digits in a given integer
 * @dig: the provided integer
 * Return: int
 **/
int dig_count(unsigned int dig)
{
	int count = 0;

	if (dig < 10)
	{
		return (1);
	}
	count++;
	while ((dig /= 10) > 0)
		count++;
	return (count);
}
