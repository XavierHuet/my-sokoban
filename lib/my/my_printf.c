/*
** EPITECH PROJECT, 2023
** miniprintf
** File description:
** miniprintf
*/
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int my_printf(const char *format, ...)
{
    int i = 0;
    int len = 0;
    va_list list;

    va_start(list, *format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            len = len + (parse_tab(format[i + 1], list));
            i = i + 1;
        } else {
            my_putchar(format[i]);
            len = len + 1;
        }
        i = i + 1;
    }
    va_end(list);
    return len;
}
