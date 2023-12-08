#include "main.h"

/**
 * _putoctal - print octal nmbrs
 * @nb: the nmber;
 * Return: printed char nbr
**/

int    _putoctal(unsigned int nb)
{
	unsigned int count;

	count = 0;
	if (nb > 7)
		count += _putoctal(nb / 8);
	nb %= 8;
	nb += 48;
	count += write(1, &nb, 1);
	return (count);
}

/**
 * _print_octal - print octal nmbrs
 * @args: p;
 * Return: printed char nbr
*/

int _print_octal(va_list *args)
{
	unsigned int nb, count;

	nb = va_arg(*args, unsigned int);
	count = _putoctal(nb);
	return (count);
}
