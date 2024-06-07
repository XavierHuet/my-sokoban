/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my_ls
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdarg.h>
    #include <dirent.h>
    #include <sys/types.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <stdint.h>
    #include <sys/sysmacros.h>
    #include <unistd.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include<stdlib.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <ncurses.h>
    #include <stdbool.h>

typedef int (*factors)(va_list);
typedef struct type_t {
    char c;
    factors function;
} type_t;
typedef struct var {
    int n;
    char *path;
    int i;
    int fd;
    char *buffer;
    char **map;
    int c;
    int x;
    int y;
} sok_t;

typedef struct game_info {
    int pos_x;
    int pos_y;
    char type; //box or player / or stockage_area
} info_t;

info_t *attribute_data(int *y, int *x, char type);
info_t **create_all_entity(char **map);
int error_handler(int argc, char **argv, sok_t *var);
sok_t *bob(char **argv);
int type_majf(va_list list);
int display_1(int x, int cmp, int len);
int last_num(double *x, int *cmp);
int type_p(va_list list);
int type_e(va_list list);
int type_maje(va_list list);
int my_scienty(double x);
int my_scienty_maj(double x);
int type_x(va_list list);
int type_majx(va_list list);
int type_o(va_list list);
int type_b(va_list list);
int type_u(va_list list);
int type_f(va_list list);
int parse_tab(char c, va_list list);
int my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_put_nbr(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_putnbr_base(long long nbr, char const *base);
int my_getnbr_base(char const *str, char const *base);
int my_printf(const char *format, ...);
int my_float(double x, int precision);
int verify(double x, int len);
int neg(double *x, int *left, int *len);
int execute(float right, int cmp);
char *my_strndup(char *src, int n);
char **my_str_to_word_array(char *str);
int count_len(char *str);
int count_alphanum(char *str);
int count_len(char *str);
int my_strcmp(char const *s1, char const *s2);
int my_printf(char const *format, ...);
void display_sokoban(sok_t *var, info_t **tab);
int locate_player_x(char **map);
int locate_player_y(char **map);
int find_x_sokoban(char **map, int y);
int find_y_sokoban(char **map, int y);
sok_t *update_struct(sok_t *var, int x, int y);
int verify_all(int argc, char **argv, sok_t *var);
void key_left(sok_t *var);
void key_right(sok_t *var);
void key_down(sok_t *var);
void key_up(sok_t *var);
void handle_movement(sok_t *var);
#endif
