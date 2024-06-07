/*
** EPITECH PROJECT, 2023
** type
** File description:
** type
*/

#include <stdarg.h>
#include <stdio.h>
#include "my.h"

int type_s(va_list list)
{
    return (my_putstr(va_arg(list, char *)));
}

int type_i(va_list list)
{
    return (my_put_nbr(va_arg(list, int)));
}

int type_c(va_list list)
{
    my_putchar(va_arg(list, int));
    return 1;
}

int type_percent(va_list list)
{
    (void) list;
    my_putchar('%');
    return 1;
}

int parse_tab(char c, va_list list)
{
    type_t TAB[] = {
    {'d', &type_i} , {'i', &type_i} , {'u', &type_u} ,
    {'o', &type_o} , {'x', &type_x} , {'X', &type_majx} ,
    {'f', &type_f} , {'c', &type_c} , {'s', &type_s} ,
    {'b', &type_b} , {'e', &type_e} , {'%', &type_percent} ,
    {'p', &type_p} , {'E', &type_maje} , {'F', &type_f} ,
    {'\0', NULL}
    };
    int i = 0;

    while (TAB[i].function != NULL) {
        if (TAB[i].c == c) {
            return (TAB[i].function(list));
        }
        i = i + 1;
    }
}
