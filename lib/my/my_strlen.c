/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** Day04
*/

#include "my.h"

int my_strlen(char const *str)
{
    int l = 0;

    if (str == NULL) {
        return 0;
    }
    while (str[l] != '\0') {
        l = l + 1;
    }
    return l;
}
