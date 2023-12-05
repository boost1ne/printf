#include "main.h"

/**
 * _strlen - a function that returns the length of a string.
 * @s: the string to be counted.
 * Return: the length of the string
*/

unsigned int _strlen(char *s)
{
	unsigned int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 *rev_puts - writes str to stdout in rev
 *@str: str
 *@len: lenght of str
 *Return: number of printed characters
 ***/

int rev_puts(char *str, unsigned int len)
{
	int i;

	i = len;
	while (len)
	{
		_putchar(str[len - 1]);
		len--;
	}
	return (i);
}

/**
 *_print_rev - writes character to stdout
 *@p: variable arguments list
 *Return: number of printed characters
 ***/

int _print_rev(va_list *p)
{
	char *str;

	str = va_arg(*p, char *);
	if (!str)
		return (rev_puts("(null)", _strlen("(null)")));
	return (rev_puts(str, _strlen(str)));
}
