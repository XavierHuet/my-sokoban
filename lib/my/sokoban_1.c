/*
** EPITECH PROJECT, 2023
** B-PSU-100-RUN-1-1-sokoban-xavier.huet
** File description:
** sokoban_1
*/

#include "my.h"

int my_stat_buffer(char *str)
{
    struct stat buffer;

    stat(str, &buffer);
    return (buffer.st_size);
}

void print_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        my_printf("%s", tab[i]);
        i = i + 1;
    }
}

sok_t  *bob(char **argv)
{
    int n = my_stat_buffer(argv[1]);
    char *path = argv[1];
    int fd;
    int c;
    int i;
    int y;
    int x;
    sok_t *var = malloc(sizeof(sok_t));

    var->fd = open(argv[1], O_RDONLY);
    var->n = n;
    var->path = path;
    var->c = 0;
    var->i = 0;
    return var;
}

int find_x_sokoban(char **map, int y)
{
    int x = 0;

    while (map[y][x] != '\0') {
        if (map[y][x] == 'P') {
            return x;
        }
        x++;
    }
    return -1;
}

int locate_player_x(char **map)
{
    int y = 0;
    int var = 0;

    while (map[y] != NULL) {
        var = find_x_sokoban(map, y);
        if (var != -1)
            return var;
        y++;
    }
    return 0;
}
