/*
** EPITECH PROJECT, 2024
** tiers
** File description:
** tiers
*/

#include "def.h"

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        write(1, &str[i], 1);
    }
}

void usr1(main_t *full)
{
    my_putstr("my navy:\n");
    for (int i = 0; i < 10; i++) {
        my_putstr(full->batles.zone[i]);
        my_putstr("\n");
    }
    my_putstr("\nenemy navy:\n");
    for (int i = 0; i < 10; i++) {
        my_putstr(full->batles.zone2[i]);
        my_putstr("\n");
    }
}

void usage(void)
{
    char *b = "USAGE\n     ./navy [first_player_pid] navy_positions";
    char *c = "\nDESCRIPTION\n     first_player_pid: only for ";
    char *d = "the 2nd player. pid of the first player.\n     navy_";
    char *e = "positions: file representing the positions of the ships.\n";

    my_putstr(b);
    my_putstr(c);
    my_putstr(d);
    my_putstr(e);
}

void coll_lines(main_t *full)
{
    for (int i = 0; i < full->open_file.size; i++) {
        if (full->open_file.buffer[i] == '\n'){
            full->dim.coll++;
        }
    }
    for (int i = 0; full->open_file.buffer[i] != '\n'; i++) {
        full->dim.line++;
    }
}

int if_good(main_t *full)
{
    if (full->open_file.buffer[0] < 'A' || full->open_file.buffer[0] > 'H')
        return 42;
    if (full->open_file.buffer[1] < '1' || full->open_file.buffer[1] > '8')
        return 42;
    if (full->open_file.buffer[2] != '\0' && full->open_file.buffer[2] != '\n')
        return 42;
    return 0;
}
