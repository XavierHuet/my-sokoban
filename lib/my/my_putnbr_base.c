/*
** EPITECH PROJECT, 2023
** my_putnbr_base.c
** File description:
** nbr_base
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int my_putnbr_base(long long nbr, char const *base)
{
    int m = 0;
    int deci = my_strlen(base);
    int base_index = 0;

    if (nbr < 0) {
        nbr = nbr * -1;
        my_putchar('-');
    }
    if (nbr >= deci) {
        m = m + my_putnbr_base(nbr / deci, base);
    }
    base_index = nbr % deci;
    my_putchar(base[base_index]);
    m = m + 1;
    return m;
}
