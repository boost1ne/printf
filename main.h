#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct display
{
    char value;
    int (*fp)(va_list p);
} display_t;

int	_printf(const char *format, ...);

#endif
