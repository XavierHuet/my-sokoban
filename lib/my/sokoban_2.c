/*
** EPITECH PROJECT, 2023
** B-PSU-100-RUN-1-1-sokoban-xavier.huet
** File description:
** sokobab_2
*/

#include "my.h"

int find_y_sokoban(char **map, int y)
{
    int x = 0;

    while (map[y][x] != '\0') {
        if (map[y][x] == 'P') {
            return y;
        }
        x++;
    }
    return -1;
}

int locate_player_y(char **map)
{
    int y = 0;
    int x = 0;
    int var;

    while (map[y] != NULL) {
        var = find_y_sokoban(map, y);
        if (var != -1)
            return var;
        y++;
    }
    return 0;
}

void replace_o(sok_t *var, info_t **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        if (var->map[tab[i]->pos_y][tab[i]->pos_x] == ' ')
            var->map[tab[i]->pos_y][tab[i]->pos_x] = 'O';
}

void display_sokoban(sok_t *var, info_t **tab)
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    while (true) {
        replace_o(var, tab);
        clear();
        var->i = 0;
        while (var->map[var->i] != NULL) {
            printw("%s\n", var->map[var->i]);
            var->i++;
        }
        printw("\n\nPress Space to exit");
        var->c = getch();
        handle_movement(var);
        if (var->c == ' ')
            break;
        refresh();
    }
    endwin();
}

sok_t *update_struct(sok_t *var, int x, int y)
{
    var->x = x;
    var->y = y;
    return var;
}

int verify_all(int argc, char **argv, sok_t *var)
{
    char *str = "Le but du jeu est de bouger";

    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        my_printf("%s des caisses sur une positions x", str);
        return 0;
    }
    if (argc != 2)
        return 84;
    if (var->fd == -1)
        return 84;
}
