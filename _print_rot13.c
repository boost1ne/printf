#include "main.h"

/**
 * _isupper -  a function that checks for uppercase character.
 * @c: the value to be checked
 * Return: 1 if c is uppercase, 0 otherwise
*/
int _isupper(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	else
		return (0);
}

/**
 * _isalpha - check if c a letter
 * @c: the value to be checked
 * Return: 1 if c a letter, 0 otherwise
*/

int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	return (0);
}


/**
 *_put_rot13 - writes str to stdout in rot13
 *@str: str
 *Return: number of printed characters
 ***/

int _put_rot13(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if ((_isalpha(str[i]) && _isupper(str[i]) && str[i] < 'N')
		|| (_isalpha(str[i]) && !_isupper(str[i]) && str[i] < 'n'))
			_putchar(str[i] + 13);
		else if (_isalpha(str[i]))
			_putchar(str[i] - 13);
		else
			_putchar(str[i]);
	}
	return (i);
}

/**
 *_print_rot13 - writes character to stdout
 *@p: variable arguments list
 *Return: number of printed characters
 ***/

int _print_rot13(va_list *p)
{
	char *str;

	str = va_arg(*p, char *);
	if (!str)
		return (_put_rot13("(null)"));
	return (_put_rot13(str));
}
