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
struct spec_n_fn
{
	char spec;
	int (*fn)(va_list, int, char *, int, int, int, char);
};
typedef struct spec_n_fn spec_t;
int *is_flag(char c,flag_t hash_addr[]);
char **get_flags (char *format, int *ind_ptr);
int write_bytes(char *bytes, int *end_addr);
char **get_width (va_list va_args, char *format, int *ind_ptr);
int is_digit(char c);
char **get_precision (va_list va_args, char *format, int *ind_ptr);
char **get_length (va_list va_args, char *format, int *ind_ptr);
char **get_specifier (va_list va_args, char *format, int *ind_ptr);
int handle_print(va_list va_args, int index, char *flag,
	 int width, int precision, int length, char specifier);
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
#endif/*___MAIN__*/
