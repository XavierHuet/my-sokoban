/*
** EPITECH PROJECT, 2023
** my strcmp
** File description:
** my strcmp
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0') {
        if (s1[i] == s2[i]) {
            i = i + 1;
        } else {
            return 1;
        }
    return 0;
    }
}
