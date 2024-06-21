/*
** EPITECH PROJECT, 2024
** navy
** File description:
** enemy map
*/

#include "def.h"

void put_in_map_enemy(main_t *full, int i)
{
    full->batles.zone2[i][0] = '1' + full->anexs.indice;
    full->anexs.indice++;
    full->batles.zone2[i][1] = '|';
    for (int index = 2; index < 17; index++) {
        if (index % 2 == 0)
            full->batles.zone2[i][index] = '.';
        else
            full->batles.zone2[i][index] = ' ';
    }
}

void put_map_enemy(main_t *full, int i)
{
    full->batles.zone2[i][0] = ' ';
    full->batles.zone2[i][1] = '|';
    for (int index = 2; index < 17; index++) {
        if (index % 2 == 0) {
            full->batles.zone2[i][index] = 'A' + full->anexs.indice;
            full->anexs.indice++;
        } else
            full->batles.zone2[i][index] = ' ';
    }
}

void put_to_map_enemy(main_t *full, int i)
{
    for (int index = 0; index < 17; index++) {
        full->batles.zone2[i][index] = '-';
    }
    full->batles.zone2[i][1] = '+';
}

static void put_all_enemy(main_t *full)
{
    for (int i = 0; full->batles.zone2[i] != NULL; i++) {
        if (i == 0) {
            put_map_enemy(full, i);
            full->anexs.indice = 0;
        }
        if (i == 1) {
            put_to_map_enemy(full, i);
        }
        if (i >= 2) {
            put_in_map_enemy(full, i);
        }
    }
}

void create_map_enemy(main_t *full)
{
    full->anexs.indice = 0;
    full->batles.zone2 = malloc(sizeof(char *) * (10 + 1));
    full->batles.zone2[10] = NULL;
    for (int i = 0; i < 10; i++) {
        full->batles.zone2[i] = malloc(sizeof(char) * (17 + 1));
        full->batles.zone2[i][17] = '\0';
    }
    put_all_enemy(full);
    if (full->anexs.dead == 1)
        return;
}
