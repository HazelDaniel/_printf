#include <unistd.h>

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
