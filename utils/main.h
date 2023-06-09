#ifndef ___MAIN__
#define ___MAIN__
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#define SHORT_SIZE (2)
#define LONG_SIZE (4)
#define DOUBLE_SIZE (8)
#define LONG_DOUBLE_SIZE (16)
int _printf(const char *format, ...);
/*utility functions*/
int dig_count(unsigned long long int dig);
unsigned long long int get_abs(long long int val);
int _strlen(char *c);
int _max(int a, int b);
char *itoa(unsigned long long int i);
int _atoi(char *s);
char *non_print_x(long int num);
char itoc(int i);
char *rev_str(char *str);
char *uint_to_bin(unsigned long long int x);
char *uint_to_hex(unsigned long long int dig, char x_case);
char *prepend_x(unsigned long long int dig, char x_case);
char *uint_to_octal(unsigned long long int dig);
typedef struct
{
	char flag;
	int found;
} flag_t;
typedef struct
{
	int is_signed;
	int has_flags;
	int has_width;
	int has_precision;
	int has_length;
	int (*fn)(char *flags, char *buffer, int, int, int);
} fm_int_t;
typedef struct
{
	int has_minus_flag;
	int has_width;
	int has_precision;
	int (*fn)(char *flags, char *buffer, int, int);
} fm_str_t;
typedef struct
{
	int has_minus_flag;
	int has_width;
	int has_length;
	int (*fn)(char *buffer, int, int);
} fm_char_t;
typedef struct
{
	int has_minus_flag;
	int has_width;
	int has_precision;
	int has_length;
	int (*fn)(char *buffer, int, int, int);
} fm_hex_t;
typedef struct
{
	int has_minus_flag;
	int has_width;
	int (*fn)(char *buffer, int);
} fm_addr_t;
struct spec_n_fn
{
	char spec;
	int (*fn)(va_list, int, char *, int, int, int, char);
};
typedef struct spec_n_fn spec_t;
int *is_flag(char c,flag_t hash_addr[]);
int is_digit(char c);
int is_print(char c);
int is_alpha(char c);
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
/* SPECIFIER-BASED WRITE HANDLERS */
int fm_write_int(char *flags, char *buffer, int width,
	int precision, int is_octal, int is_hex);
int fm_write_str(char *flags, char *buffer, int width,
	int precision);
int fm_write_char(char *flags, char *buffer, int width);
int fm_write_hex(char *flags, char *buffer, int width,
	int precision);
int fm_write_octal(char *flags, char *buffer, int width,
	int precision);
int fm_write_addr(char *flags, char *buffer, int width);
#endif/*___MAIN__*/
