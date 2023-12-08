#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * struct display - struct contains the derective
 * and a p to the function associated
 * @value: the derective
 * @fp: function pointer
**/

typedef struct display
{
	char value;
	int (*fp)(va_list *p);
} display_t;

int	_printf(const char *format, ...);
int _print_c(va_list *args);
int _string_put(va_list *p);
int _puts(char *str);
int _putchar(char c);
int printf_handler(const char *format, va_list *args);
int _print_nb(va_list *args);
int    _putnbr(int nb);
int _print_unb(va_list *args);
int    _putunbr(unsigned int nb);
int _print_octal(va_list *args);
int _print_heXupp(va_list *args);
int _print_hexa(va_list *args);
int _print_binary(va_list *args);
int    _puthex(unsigned long nb);
int _print_addr(va_list *args);
int _print_rev(va_list *p);
int _print_rot13(va_list *p);

#endif
