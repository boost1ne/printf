#include "main.h"


/**
 * _print_addr - print addre
 * @args: p;
 * Return: printed char nbr
*/

int _print_addr(va_list *args)
{
	unsigned long nb, count;

	count = write(1, "0x", 2);
	nb = va_arg(*args, unsigned long);
	count = _puthex(nb);
	return (count);
}
