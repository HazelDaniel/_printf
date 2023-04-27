#include "main.h"
#include <stdio.h>
#include <limits.h>
#include "utils/spec_write_handlers.c"

int main(void)
{
	_printf("A. i%d\n", 55, "string template");
	// puts("..........................................");
	_printf("B. i%#-0 +5.2hd %-*.3dlve everybody\n", 55, 45, 100);
	// puts("..........................................");
	_printf("C. t%%\n", 55, "string template");
	// puts("D..........................................");
	_printf("D. i%-+0-5.22hd %-*.3mlve everybody\n", 55, "string template");
	_printf("E");
	// printf("F. %03.3d\n", 88);
		int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
		// printf("Length:[%d, %i]\n", len, len);
		//printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
		//printf("char:[%-3p]\n", (void *)1356);
    _printf("Unsigned:[%lu]\n", (unsigned int)-3);
		//printf("upper hex:[%X]\n", -3);
    _printf("Unsigned octal:[%o]\n", ui);
		//printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%llx, %X]\n", -3, ui);
    // printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    // printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    _printf("non printable:[%S]\n", "I am a \n\tstring\a\b !");
    // printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
		//printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    _printf("binary:[%-# 08.3lb]\n", 5);
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    // printf("Len:[%d]\n", len2);
    _printf("reversed:[%r]\n", "hello world");
    _printf("Rot13:[%R]\n", "hello, world");
		//printf("%13.1s\n", "hello, world");
			int ch = 9;
		//printf("%-10p\n", addr);
		//printf("%#-10.0o\n", ch);
		//printf("%-10.11d\n", -888888);
	return (0);
}
