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
*/

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


#endif
