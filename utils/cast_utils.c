#include "main.h"

long int cast_int_to_size(long int value, int size)
{
	switch(size)
	{
	case SHORT_SIZE:
			return ((short)value);
		break;
	case LONG_SIZE:
			return ((long int)value);
		break;
	default:
		return ((int)value);
	}
}

long double cast_float_to_size(long double value, int size)
{
	switch(size)
	{
	case DOUBLE_SIZE:
			return ((double)value);
		break;
	case LONG_DOUBLE_SIZE:
			return ((long double)value);
		break;
	default:
		return ((float)value);
	}
}
