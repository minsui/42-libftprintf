#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int m;
    int r;

    m = ft_printf("c: %c\n", 'A');
    r = printf("c: %c\n", 'A');
    printf("m:%d r:%d\n\n", m, r);

    m = ft_printf("s: %s\n", "42");
    r = printf("s: %s\n", "42");
    printf("m:%d r:%d\n\n", m, r);

    m = ft_printf("p: %p\n", &m);
    r = printf("p: %p\n", &m);
    printf("m:%d r:%d\n\n", m, r);

    m = ft_printf("d: %d\n", -42);
    r = printf("d: %d\n", -42);
    printf("m:%d r:%d\n\n", m, r);

    m = ft_printf("u: %u\n", 4294967295U);
    r = printf("u: %u\n", 4294967295U);
    printf("m:%d r:%d\n\n", m, r);

    m = ft_printf("x: %x\n", 255);
    r = printf("x: %x\n", 255);
    printf("m:%d r:%d\n\n", m, r);

    m = ft_printf("X: %X\n", 255);
    r = printf("X: %X\n", 255);
    printf("m:%d r:%d\n\n", m, r);

    m = ft_printf("%%: %%\n");
    r = printf("%%: %%\n");
    printf("m:%d r:%d\n\n", m, r);

    return (0);
}