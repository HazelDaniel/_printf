#ifndef ___MAIN__
#define ___MAIN__
#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
#define SHORT_SIZE (2)
#define LONG_SIZE (4)
#define LONG_DOUBLE_SIZE (8)
int ctoi(char c);
int is_print(char c);
char itoc(int i);
int _strlen(char *c);
char *uint_to_bin(unsigned int dig);
char *uint_to_hex(unsigned long int dig, char x_case);
int dig_count(unsigned int dig);
char *itoa(unsigned int i);
int _atoi(char *s);
typedef struct {
	char flag;
	int found;
} flag_t;
int *is_flag(char c,flag_t hash_addr[]);
char **get_flags (char *format, int *ind_ptr);
int write_bytes(char *bytes, int *end_addr);
char **get_width (va_list va_args, char *format, int *ind_ptr);
int is_digit(char c);
char **get_precision (va_list va_args, char *format, int *ind_ptr);
char **get_length (va_list va_args, char *format, int *ind_ptr);
char **get_specifier (va_list va_args, char *format, int *ind_ptr);
#endif/*___MAIN__*/
