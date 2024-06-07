/*
** EPITECH PROJECT, 2023
** my_scient_maj
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdio.h>
#include "my.h"

int my_scienty_maj(double x)
{
    int cmp = 0;
    int len = 0;

    if (x < 0) {
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
