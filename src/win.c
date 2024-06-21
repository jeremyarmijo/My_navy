/*
** EPITECH PROJECT, 2024
** signal
** File description:
** management
*/
#include "def.h"

int check_up(char map, int cpt)
{
    if (map == 'x')
        cpt++;
    return cpt;
}

void if_win(main_t *full)
{
    int cpt = 0;

    for (int i = 2; i < 10; i++) {
        for (int y = 2; y < 17; y++)
            cpt = check_up(full->batles.zone[i][y], cpt);
    }
    if (cpt == 14) {
        full->anexs.win = 1;
        return;
    }
    cpt = 0;
    for (int i = 2; i < 10; i++) {
        for (int y = 2; y < 17; y++)
            cpt = check_up(full->batles.zone2[i][y], cpt);
    }
    if (cpt == 14)
        full->anexs.win = 2;
}
