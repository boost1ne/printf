#include "main.h"

/**
 * _putnbr - print nmbrs
 * @nb: the nmber;
 * Return: printed char nbr
*/

int    _putnbr(int nb)
{
	unsigned int unb, count;

	count = 0;
	if (nb < 0)
	{
		nb = -nb;
		count += write(1, "-", 1);
	}
	unb = nb;
	if (unb > 9)
		count += _putnbr(unb / 10);
	unb %= 10;
	unb += 48;
	count += write(1, &unb, 1);
	return (count);
}

/**
 * _print_nb - print nmbrs
 * @args: p
 * Return: how many bytes written
*/

int _print_nb(va_list *args)
{
	int nb, count;

	nb = va_arg(*args, int);
	count = _putnbr(nb);
	return (count);
}
