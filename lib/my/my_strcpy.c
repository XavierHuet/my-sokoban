/*
** EPITECH PROJECT, 2023
** my_strcpy
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char const *src)
{
    int nb = 0;

    while (src[nb] != '\0') {
        dest [nb] = src [nb];
        nb++;
    }
    dest[nb] = '\0';
    return dest;
}
