/*
** EPITECH PROJECT, 2023
** str to word array
** File description:
** str to word array
*/

#include "my.h"

int my_isalphanum(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
                            (c >= '0' && c <= '9' || c == ' ' || c == '#')) {
        return 1;
    } else {
        return 0;
    }
}

int count_len(char *str)
{
    int i = 0;

    while (str[i] != '\0' && my_isalphanum(str[i]) == 1)
        i = i + 1;
    return (i);
}

int count_alphanum(char *str)
{
    int i = 0;
    int cmp = 0;

    while (str[i] != '\0') {
        if (my_isalphanum(str[i]) == 0)
            cmp = cmp + 1;
        i = i + 1;
    }
    return cmp + 1;
}

char **my_str_to_word_array(char *str)
{
    char **array;
    int i = 0;
    int n = count_alphanum(str);
    int n1 = 0;

    array = malloc(sizeof(char *) * (n + 1));
    if (array == NULL)
        return NULL;
    while (i < n) {
        n1 = count_len(str);
        array[i] = my_strndup(str, n1);
        str = str + n1 + 1;
        i = i + 1;
    }
    array[i] = NULL;
    return array;
}
