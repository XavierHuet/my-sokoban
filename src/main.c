/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** main
*/

#include "my.h"
#include <string.h>

int main(int argc, char **argv)
{
    sok_t *var = bob(argv);
    char *buffer = malloc(sizeof(char) * (var->n + 1));
    buffer[var->n] = '\0';
    int x = 0;
    int y = 0;

    if (error_handler(argc, argv, var) == 84)
        return 84;
    read(var->fd, buffer, var->n);
    var->map = my_str_to_word_array(buffer);
    x = locate_player_x(var->map);
    y = locate_player_y(var->map);
    info_t **tab = create_all_entity(var->map);
    update_struct(var, x, y);
    display_sokoban(var, tab);
    free(var->map);
}

int error_handler(int argc, char **argv, sok_t *var)
{
    if (argc != 2)
        return 84;
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        my_printf("Le but du jeu est de bouger des boites");
        return 0;
    }
    if (var->fd == -1)
        return 84;
}