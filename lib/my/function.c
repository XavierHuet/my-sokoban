/*
** EPITECH PROJECT, 2023
** functions
** File description:
** my_printf
*/

#include <stdarg.h>
#include "my.h"

int type_x(va_list list)
{
    return (my_putnbr_base(va_arg(list, int), "0123456789abcdef"));
}

int type_majx(va_list list)
{
    return (my_putnbr_base(va_arg(list, int), "0123456789ABCDEF"));
}

int type_o(va_list list)
{
    return (my_putnbr_base(va_arg(list, int), "01234567"));
}

int type_b(va_list list)
{
    return (my_putnbr_base(va_arg(list, int), "01"));
}

int type_u(va_list list)
{
    return (my_put_nbr(va_arg(list, unsigned int)));
}
