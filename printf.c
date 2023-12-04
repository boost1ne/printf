#include "main.h"

int _putchar(char c)
{
    return (write(1, &c, 1));
}

int _puts(char *str)
{
    int i;

    for (i = 0; str[i]; i++)
        _putchar(str[i]);
    return (i);
}


int _string_put(va_list p)
{
    char *str;

    str = va_arg(p, char *);
    if (!str)
    {
        _puts("(null)");
        return (-1);
    }
    return (_puts(str));
}

int _print_c(va_list args)
{
    char c;

    c = va_arg(args, int);
    return (_putchar(c));
}

int	_printf(const char *format, ...)
{
    va_list args;
    unsigned int count = 0;
    int i;
    display_t funcs[2] = {
        {'s', _string_put},
        {'c', _print_c}
    };

    if (!format || !*format)
        return (-1);
    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (!*format)
                return (-1);
            for (i = 0; i < 2; i++)
            {
                if (*format == funcs[i].value)
                    count += funcs[i].fp(args);
            }
        }
        else
            count += _putchar(*format);
        format++;
    }
    return (count);
}
