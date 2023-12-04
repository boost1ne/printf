#include "main.h"
#include <stdio.h>
int main(void)
{
    int len;
    int len2;
    // char *s2;

    // s2 = "Mussum Ipsum, cacilds vidisMussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus. litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";
    len = _printf("s%sx\n","test");
    len2 = printf("s%sx\n", "test");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    len = _printf("%c", 'g');
    len2 = printf("%c", 'g');
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    // len = _printf("%");
    // len2 = printf("%");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    return (0);
}
