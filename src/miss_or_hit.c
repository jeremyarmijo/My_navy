/*
** EPITECH PROJECT, 2024
** signal
** File description:
** management
*/
#include "def.h"

void miss_or_hit1(main_t *full)
{
    if (variable_global == 200) {
        full->batles.zone2[full->rockets.coory + 1]
        [full->rockets.coorx * 2] = 'x';
        my_putstr("result: ");
        my_putchar(full->rockets.coorx + 64);
        my_putchar(full->rockets.coory + 48);
        my_putstr(":hit\n\n");
    }
    if (variable_global == 100) {
        full->batles.zone2[full->rockets.coory + 1]
        [full->rockets.coorx * 2] = 'o';
        my_putstr("result: ");
        my_putchar(full->rockets.coorx + 64);
        my_putchar(full->rockets.coory + 48);
        my_putstr(":missed\n\n");
    }
    usleep(2000);
    kill(full->pids.pid_usr1, SIGUSR2);
}

void miss_or_hit2(main_t *full)
{
    if (variable_global == 200) {
        full->batles.zone2[full->rockets.coory + 1]
        [full->rockets.coorx * 2] = 'x';
        my_putstr("result: ");
        my_putchar(full->rockets.coorx + 64);
        my_putchar(full->rockets.coory + 48);
        my_putstr(":hit\n\n");
    }
    if (variable_global == 100) {
        full->batles.zone2[full->rockets.coory + 1]
        [full->rockets.coorx * 2] = 'o';
        my_putstr("result: ");
        my_putchar(full->rockets.coorx + 64);
        my_putchar(full->rockets.coory + 48);
        my_putstr(":missed\n\n");
    }
    usleep(2000);
    kill(full->pids.pid_usr2, SIGUSR2);
}
