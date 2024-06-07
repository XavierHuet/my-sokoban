/*
** EPITECH PROJECT, 2023
** my_scient
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdio.h>
#include "my.h"

int last_num(double *x, int *cmp)
{
    while (*x > 10.0) {
        *x = *x / 10.0;
        *cmp = *cmp + 1;
    }
    return 0;
}

int display_1(int x, int cmp, int len)
{
    my_putchar('e');
    if (x < 0) {
        my_putchar('-');
    } else {
        my_putchar('+');
    }
    len = len + 1;
    return len;
}

int my_scienty(double x)
{
    int cmp = 0;
    int len = 0;

    if (x < 0.0) {
        x = x * (-1);
        len = len + my_putchar('-');
    }
    if (x < 1.0) {
        while (x < 1.0) {
            x = x * 10.0;
            cmp = cmp + 1;
        }
    }
    last_num(&x, &cmp);
    len = len + my_float(x, 1000000) + display_1(x, cmp, len);
    if (cmp < 10)
        len = len + my_put_nbr(0);
    len = len + my_put_nbr(cmp);
    return len;
}
