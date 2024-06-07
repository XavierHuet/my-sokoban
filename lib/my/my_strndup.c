/*
** EPITECH PROJECT, 2023
** do8
** File description:
** do8
*/

#include "my.h"

char *my_strndup(char *src, int n)
{
    int i = 0;
    int l = my_strlen(src);
    char *str;

    if (n > l || n <= 0)
        return src;
    str = malloc(sizeof(char) * (n + 1));
    while (i < n) {
        str[i] = src[i];
        i = i + 1;
    }
    str[n] = '\0';
    return (str);
}
