#include "main.h"

/**
  * cast_int_to_size - the function name
  * @value: parameter of type long int .
  * @size: parameter of type int .
  * Return: long int .
 */
long int cast_int_to_size(long int value, int size)
{
	switch (size)
	{
	case SHORT_SIZE:
		return ((short)value);
	case LONG_SIZE:
		return ((long int)value);
	default:
		return ((int)value);
	}
}

/**
  * cast_float_to_size - the function name
  * @value: parameter of type long double .
  * @size: parameter of type int .
  * Return: long double .
 */
long double cast_float_to_size(long double value, int size)
{
	switch (size)
	{
	case DOUBLE_SIZE:
		return ((double)value);
	case LONG_DOUBLE_SIZE:
		return ((long double)value);
	default:
		return ((float)value);
	}
}
