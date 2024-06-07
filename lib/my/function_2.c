/*
** EPITECH PROJECT, 2023
** functions
** File description:
** my printf
*/

#include <stdarg.h>
#include <stdio.h>
#include "my.h"

int type_f(va_list list)
{
    return (my_float(va_arg(list, double), 1000000));
}

int type_e(va_list list)
{
    return (my_scienty(va_arg(list, double)));
}

int type_p(va_list list)
{
    int t = 0;

    t = my_putstr("0x");
    t = t + my_putnbr_base(va_arg(list, unsigned long), "0123456789abcdef");
    return t;
}

int type_maje(va_list list)
{
    return (my_scienty_maj(va_arg(list, double)));
}
