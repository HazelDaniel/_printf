#ifndef ___MAIN__
#define ___MAIN__
#include <unistd.h>
#include <stdarg.h>
#define SHORT_SIZE (2)
#define LONG_SIZE (4)
#define LONG_DOUBLE_SIZE (8)
int _printf(const char *format, ...);
/*utility functions*/
char *uint_to_bin(unsigned int x);
int dig_count(unsigned int dig);
int _strlen(char *c);
char *itoa(unsigned int i);
int _atoi(char *s);
char itoc(int i);
char *uint_to_hex(unsigned long int dig, char x_case);
typedef struct
{
	char flag;
	int found;
} flag_t;
int *is_flag(char c,flag_t hash_addr[]);
int is_digit(char c);
int write_bytes(char *bytes, int *end_addr);
char **get_flags (char *format, int *ind_ptr);
char **get_width (va_list va_args, char *format, int *ind_ptr);
char **get_precision (va_list va_args, char *format, int *ind_ptr);
char **get_length (va_list va_args, char *format, int *ind_ptr);
char **get_specifier (va_list va_args, char *format, int *ind_ptr);
#endif/*___MAIN__*/
