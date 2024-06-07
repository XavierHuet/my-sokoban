/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** my_putstr
*/

#include "my.h"

int my_putstr(char const *str)
{
    int m = 0;

    while (str[m] != '\0') {
        my_putchar(str[m]);
        m = m + 1;
    }
    return m;
}
