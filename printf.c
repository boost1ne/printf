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
	int i;
	display_t funcs[2] = {
		{'s', _string_put},
		{'c', _print_c}
	};

	if ((*format == '%' && !*(format + 1)))
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				break;
			for (i = 0; i < 2; i++)
			{
				if (*format == funcs[i].value)
				{
					count += funcs[i].fp(&args);
					break;
				}
				else if (*format == '%' || i == 1)
				{
					count += _putchar(*format);
					break;
				}
			}
		}
		else
			count += _putchar(*format);
		format++;
	}
	return (count);
}

int main(void)
{
    int len;
    int len2;
    // char *s2;

    // s2 = "Mussum Ipsum, cacilds vidisMussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus. litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";
    len = _printf("", "");
    len2 = printf("", "");
    printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    len = _printf("%c", 'g');
    len2 = printf("%c", 'g');
    printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    len = _printf("%a");
    len2 = printf("%a");
    printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    len = _printf("Percent:[%%%]\n");
    len2 = printf("Percent:[%%%]\n");
    printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    return (0);
}
