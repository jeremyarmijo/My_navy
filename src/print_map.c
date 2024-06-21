/*
** EPITECH PROJECT, 2024
** signal
** File description:
** management
*/
#include "def.h"

void print_pid(int pid)
{
    my_putstr("my_pid: ");
    my_put_nbr(pid);
    my_putstr("\n\n");
    if (variable_global == 1)
        my_putstr("waiting for enemy...\n");
}

void print_maps(main_t *full)
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
