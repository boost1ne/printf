#include "main.h"

/**
 *printf_handler - formats and prints data to stdout
 *@format: format string to check
 *@args: list p
 *Return: number of printed characters
 ****/

int printf_handler(const char *format, va_list *args)
{
	unsigned int count, i;
	display_t funcs[2] = {
		{'s', _string_put},
		{'c', _print_c}
	};

	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				return (-1);
			for (i = 0; i < 2; i++)
			{
				if (*format == ' ' && !*(format + 1))
					return (-1);
				if (*format == funcs[i].value)
				{
					count += funcs[i].fp(args);
					break;
				}
				if (*format == '%' || i == 1)
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
