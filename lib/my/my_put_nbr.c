/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** nbr
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int my_put_nbr(int nb)
{
    int m = 0;

    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
    }
    if (nb >= 10) {
        m = m + my_put_nbr(nb / 10);
    }
    my_putchar(nb % 10 + 48);
    m = m + 1;
    return m;
}
