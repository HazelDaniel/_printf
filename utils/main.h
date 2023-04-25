#ifndef ___MAIN__
#define ___MAIN__
#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#define SHORT_SIZE (2)
#define LONG_SIZE (4)
#define DOUBLE_SIZE (8)
#define LONG_DOUBLE_SIZE (16)
int ctoi(char c);
int is_print(char c);
char itoc(int i);
int _strlen(char *c);
char *uint_to_bin(unsigned long long int dig);
char *uint_to_hex(unsigned long long int dig, char x_case);
char *prepend_x(unsigned long long int dig, char x_case);
char *uint_to_octal(unsigned long long int dig);
int dig_count(unsigned long long int dig);
unsigned long long int get_abs(long long int val);
char *itoa(unsigned long long int i);
int _atoi(char *s);
char *rev_str(char *str);
typedef struct
{
	char flag;
	int found;
} flag_t;
struct spec_n_fn
{
	char spec;
	int (*fn)(va_list, int, char *, int, int, int, char);
};
typedef struct spec_n_fn spec_t;
int *is_flag(char c,flag_t hash_addr[]);
int is_digit(char c);
int is_print(char c);
int in_str (char c, char *str);
int write_bytes(char *bytes, int *end_addr);
char **get_flags (char *format, int *ind_ptr);
char **get_width (va_list va_args, char *format, int *ind_ptr);
char **get_precision (va_list va_args, char *format, int *ind_ptr);
char **get_length (va_list va_args, char *format, int *ind_ptr);
char **get_specifier (va_list va_args, char *format, int *ind_ptr);
int handle_print(va_list va_args, int index, char *flag,
	 int width, int precision, int length, char specifier);
/*TYPE BASED PRINTS*/
int print_int(va_list va_args, int index, char *flag,
	 int width, int precision, int length, char specifier);
int print_bin(va_list va_args, int index, char *flag,
	 int width, int precision, int length, char specifier);
int print_x_upper(va_list va_args, int index, char *flag,
	 int width, int precision, int length, char specifier);
int print_pointer(va_list va_args, int index, char *flag,
	 int width, int precision, int length, char specifier);
int print_non_print(va_list va_args, int index, char *flag,
	 int width, int precision, int length, char specifier);
int print_unsigned(va_list va_args, int index, char *flag,
	 int width, int precision, int length, char specifier);
int print_octal(va_list va_args, int index, char *flag,
	 int width, int precision, int length, char specifier);
int print_x_lower(va_list va_args, int index, char *flag,
	 int width, int precision, int length, char specifier);
int print_char(va_list va_args, int index, char *flag,
	 int width, int precision, int length, char specifier);
int print_string(va_list va_args, int index, char *flag,
	 int width, int precision, int length, char specifier);
int print_reverse(va_list va_args, int index, char *flag,
	 int width, int precision, int length, char specifier);
int print_rot13(va_list va_args, int index, char *flag,
	 int width, int precision, int length, char specifier);
/*CAST UTILS*/
long int cast_int_to_size(long int value, int size);
long double cast_float_to_size(long double value, int size);
/*FIELD UTILS*/
char *get_important_flags(char *flags);
#endif/*___MAIN__*/
