#include "main.h"

/**
 * _puthex - print hex nmbrs
 * @nb: the nmber;
 * Return: printed char nbr
*/

int    _puthex(unsigned long nb)
{
	unsigned int count;

	count = 0;
	if (nb > 15)
		count += _puthex(nb / 16);
	nb %= 16;
	if (nb > 9)
		nb += 87;
	else
		nb += 48;
	count += write(1, &nb, 1);
	return (count);
}

/**
 * _print_hexa - print nmbrs
 * @args: p
 * Return: how many bytes written
*/

int _print_hexa(va_list *args)
{
	unsigned int nb, count;

	nb = va_arg(*args, unsigned int);
	count = _puthex(nb);
	return (count);
}

/**
 * _putheXupp - print hex in uppercase
 * @nb: the nmber;
 * Return: printed char nbr
*/

int    _putheXupp(unsigned int nb)
{
	unsigned int count;

	count = 0;
	if (nb > 15)
		count += _putheXupp(nb / 16);
	nb %= 16;
	if (nb > 9)
		nb += 55;
	else
		nb += 48;
	count += write(1, &nb, 1);
	return (count);
}

/**
 * _print_heXupp - print nmbrs
 * @args: p
 * Return: how many bytes written
**/

int _print_heXupp(va_list *args)
{
	unsigned int nb, count;

	nb = va_arg(*args, unsigned int);
	count = _putheXupp(nb);
	return (count);
}
