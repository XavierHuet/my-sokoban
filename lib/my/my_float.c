/*
** EPITECH PROJECT, 2023
** float
** File description:
** my_printf
*/

#include <stdio.h>
#include "my.h"

int execute(float right, int cmp)
{
    if (right == 0.0) {
        return 6;
    }
    while (right < 1.0) {
        cmp = cmp + 1;
        right = right * 10.0;
    }
    return cmp;
}

int display(int cmp, int dec, int len, double x)
{
    double app = 0.010000;
    int left = x;

    len = len + my_put_nbr(left) + my_putchar('.');
    if (x == app)
        cmp = cmp - 1;
    while (cmp > 0) {
        cmp = cmp - 1;
        my_put_nbr(0);
        len = len + 1;
    }
    len = len + my_put_nbr(dec);
    return len;
}

int verify(double x, int len)
{
    int tolerence = 0;

    if ((x == (double)tolerence)) {
        len = len + my_put_nbr(0) + my_putchar('.');
        for (int i = 0; i < 6; i = i + 1) {
            my_put_nbr(0);
            len = len + 1;
        }
        return len;
    } else
        return 0;
}

int neg(double *x, int *left, int *len)
{
    if (*x < 0) {
        *x = *x * (-1);
        *left = *left * (-1);
        *len = *len + my_putchar('-');
        return 1;
    }
    return 0;
}

int my_float(double x, int precision)
{
    int left = x;
    float right = 0;
    int dec = 0;
    int len = 0;
    int round = 0;
    int cmp = -1;

    if (verify(x, len) == 8)
        return 8;
    neg(&x, &left, &len);
    right = x - left;
    round = right * precision * 10;
    while (round > 10)
        round = round - 10;
    dec = right * precision;
    if ((round >= 5) && (round < 10))
        dec = dec + 1;
    cmp = execute(right, cmp);
    len = display(cmp, dec, len, x);
    return len;
}
