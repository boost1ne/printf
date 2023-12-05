#include "main.h"

/**
 *_putchar - writes character to stdout
 *@c: the char to be printed
 *Return: the char
 ***/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 *_puts - writes str to stdout
 *@str: str
 *Return: number of printed characters
 ***/

int _puts(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		_putchar(str[i]);
	return (i);
}

/**
 *_string_put - writes character to stdout
 *@p: variable arguments list
 *Return: number of printed characters
 ***/

int _string_put(va_list *p)
{
	char *str;

	str = va_arg(*p, char *);
	if (!str)
		return (_puts("(null)"));
	return (_puts(str));
}

/**
 *_print_c - writes character to stdout
 *@args: variable arguments list
 *Return: number of printed characters
 ***/

int _print_c(va_list *args)
{
	char c;

	c = va_arg(*args, int);
	return (_putchar(c));
}

/**
 *_printf - formats and prints data to stdout
 *@format: format string to check
 *@...: variable arguments list
 *
 *Return: number of printed characters
 ****/

int	_printf(const char *format, ...)
{
	va_list args;
	unsigned int count = 0;

	if (!format || !*format || (*format == '%' && !*(format + 1)))
		return (-1);
	va_start(args, format);
	count = printf_handler(format, &args);
	return (count);
}

#include "main.h"
#include <stdio.h>
int main(void)
{
    int len;
    int len2;
    // char *s2;

    // s2 = "Mussum Ipsum, cacilds vidisMussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus. litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";
    // len = _printf("s%sx\n","test");
    // len2 = printf("s%sx\n", "test");
    // _printf("Len:[%d]\n", len);
    // printf("Len:[%d]\n", len2);
    // len = _printf("%c", 'g');
    // len2 = printf("%c", 'g');
    // _printf("Len:[%d]\n", len);
    // printf("Len:[%d]\n", len2);
    // // len = _printf("%");
    // // len2 = printf("%");
    // _printf("Len:[%d]\n", len);
    // printf("Len:[%d]\n", len2);
    // len = _printf("Percent:[%%]\n");
    // len2 = printf("Percent:[%%]\n");
    // _printf("Len:[%d]\n", len);
    // printf("Len:[%d]\n", len2);
    len = _printf("%d\n", -762534);
    len2 = printf("%d\n", -762534, -762534);
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    return (0);
}
