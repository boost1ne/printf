#include "main.h"

/**
 * _putbinary - print binary nmbrs
 * @nb: the nmber;
 * Return: printed char nbr
*/

int    _putbinary(unsigned int nb)
{
	unsigned int count;

	count = 0;
	if (nb > 1)
		count += _putbinary(nb / 2);
	nb %= 2;
	nb += 48;
	count += write(1, &nb, 1);
	return (count);
}

/**
 * _print_binary - print nmbrs
 * @args: p
 * Return: how many bytes written
*/

int _print_binary(va_list *args)
{
	unsigned int nb, count;

	nb = va_arg(*args, unsigned int);
	count = _putbinary(nb);
	return (count);
}
