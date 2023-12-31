#include "main.h"

/**
 * init - is a helper function to initialize struct
 * Return: an array of structs
*/

display_t *init(void)
{
	static display_t funcs[12] = {
		{'s', _string_put},
		{'c', _print_c},
		{'d', _print_nb},
		{'i', _print_nb},
		{'u', _print_unb},
		{'o', _print_octal},
		{'X', _print_heXupp},
		{'x', _print_hexa},
		{'b', _print_binary},
		{'p', _print_addr},
		{'r', _print_rev},
		{'R', _print_rot13}
	};
	return (funcs);
}

/**
 *printf_handler - formats and prints data to stdout
 *@format: format string to check
 *@args: list p
 *Return: number of printed characters
 ****/

int printf_handler(const char *format, va_list *args)
{
	unsigned int count, i;
	display_t *funcs = init();

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				break;
			for (i = 0; i < 12; i++)
			{
				if (*format == ' ' && !*(format + 1))
					return (-1);
				if (*format == funcs[i].value)
				{
					count += funcs[i].fp(args);
					break;
				}
				if (*format == '%' || i == 11)
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
