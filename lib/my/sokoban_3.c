/*
** EPITECH PROJECT, 2023
** B-PSU-100-RUN-1-1-sokoban-xavier.huet
** File description:
** sokoban_3
*/

#include "my.h"

info_t *attribute_data(int *y, int *x, char type)
{
    info_t *data = malloc(sizeof(info_t));
    if (data == NULL)
        exit(84);
    data->pos_y = *y;
    data->pos_x = *x;
    data->type = type;

    return data;
}

info_t **create_all_entity(char **map)
{
    int k = 0;
    int cmp = 0;

    for (int a = 0; map[a] != NULL; a++) {
        for (int b = 0; map[a][b] != '\0'; b++) {
            if (map[a][b] == 'O') {
                a++;
                cmp = a;
            }
        }
    }
    info_t **tab = malloc(sizeof(info_t *) * (cmp + 1));
    if (tab == NULL)
        exit(84);
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            if (map[i][j] == 'O') {
                tab[k] = attribute_data(&i, &j, map[i][j]);
                k++;
            }
        }
    }
    tab[k] = NULL;
    return tab;
}

void key_left(sok_t *var)
{
    int x = var->x;
    int y = var->y;

    if (var->map[y][x - 1] != '#'
                            && var->map[y][x - 1] != 'X') {
        var->map[y][x] = ' ';
        var->map[y][x - 1] = 'P';
        var->x--;
    } else if (var->map[y][x - 1] == 'X' && var->map[y][x - 2] != '#' &&
            var->map[y][x - 2] != 'X') {
        var->map[y][x] = ' ';
        var->map[y][x - 1] = 'P';
        var->map[y][x - 2] = 'X';
        var->x--;
    }
}

void key_right(sok_t *var)
{
    int x = var->x;
    int y = var->y;

    if (var->map[y][x + 1] != '#'
                                && var->map[y][x + 1] != 'X') {
        var->map[y][x] = ' ';
        var->map[y][x + 1] = 'P';
        var->x++;
    } else if (var->map[y][x + 1] == 'X' && var->map[y][x + 2] != '#' &&
            var->map[y][x + 2] != 'X') {
        var->map[y][x] = ' ';
        var->map[y][x + 1] = 'P';
        var->map[y][x + 2] = 'X';
        var->x++;
    }
}

void key_down(sok_t *var)
{
    int x = var->x;
    int y = var->y;

    if (var->map[y + 1][x] != '#'
                        && var->map[y + 1][x] != 'X') {
        var->map[y][x] = ' ';
        var->map[y + 1][x] = 'P';
        var->y++;
    } else if (var->map[y + 1][x] == 'X' && var->map[y + 2][x] != '#' &&
            var->map[y + 2][x] != 'X') {
        var->map[y][x] = ' ';
        var->map[y + 1][x] = 'P';
        var->map[y + 2][x] = 'X';
        var->y++;
    }
}

void key_up(sok_t *var)
{
    int x = var->x;
    int y = var->y;

   if (var->map[y - 1][x] != '#'
                            && var->map[y - 1][x] != 'X') {
        var->map[y][x] = ' ';
        var->map[y - 1][x] = 'P';
        var->y--;
    } else if (var->map[y - 1][x] == 'X' && var->map[y - 2][x] != '#' &&
            var->map[y - 2][x] != 'X') {
        var->map[y][x] = ' ';
        var->map[y - 1][x] = 'P';
        var->map[y - 2][x] = 'X';
        var->y--;
    }
}

void handle_movement(sok_t *var)
{
    if (var->c == KEY_LEFT)
        key_left(var);
    if (var->c == KEY_RIGHT)
        key_right(var);
    if (var->c == KEY_DOWN)
        key_down(var);
    if (var->c == KEY_UP)
        key_up(var);
}
