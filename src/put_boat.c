/*
** EPITECH PROJECT, 2024
** header
** File description:
** put_boat
*/

#include "def.h"

void verify_is_num(main_t *full, char num)
{
    if ((num - 48) >= 1 && (num - 48) <= 8)
        full->anexs.dead = 1;
}

void put_on_boat(main_t *full, int i, int who)
{
    if (who == 0) {
        for (int index = 0; FOR_1 != FOR2_1; index++) {
            COND_0 = (BOAT_1[i].ref + 48);
        }
        return;
    }
    for (int index = 0; FOR_2 != FOR2_2; index++) {
        if ((index % 2) != 0 && (COND_1 == '.' || COND_1 == ' '))
            COND_1 = (BOAT_1[i].ref + 48);
        else
            verify_is_num(full, COND_1);
    }
}

void print_boat(main_t *full)
{
    for (int i = 0; full->boot[i].first_x != -42; i++) {
        ZONEXYF_2 = (full->boot[i].ref + 48);
        ZONEXYS_2 = (full->boot[i].ref + 48);
        if ((BOAT_1[i].first_x - BOAT_1[i].second_x) == 0) {
            BOAT_1[i].direction_boat = 0;
            put_on_boat(full, i, 0);
        } else {
            BOAT_1[i].direction_boat = 1;
            put_on_boat(full, i, 1);
        }
    }
}
