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
	display_t funcs[4] = {
		{'s', _string_put},
		{'c', _print_c},
		{'d', _print_nb},
		{'i', _print_nb}
	};

	count = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				break;
			for (i = 0; i < 4; i++)
			{
				if (*format == ' ' && !*(format + 1))
					break;
				if (*format == funcs[i].value)
				{
					count += funcs[i].fp(args);
					break;
				}
				if (*format == '%' || i == 3)
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
