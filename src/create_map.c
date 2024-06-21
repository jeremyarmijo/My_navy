/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** my_navy
*/
#include "def.h"

void put_all(main_t *full)
{
    for (int i = 0; full->batles.zone[i] != NULL; i++) {
        if (i == 0) {
            put_map(full, i);
            full->anexs.indice = 0;
        }
        if (i == 1)
            put_to_map(full, i);
        if (i >= 2)
            put_in_map(full, i);
    }
}

void put_map(main_t *full, int i)
{
    full->batles.zone[i][0] = ' ';
    full->batles.zone[i][1] = '|';
    for (int index = 2; index < 17; index++) {
        if (index % 2 == 0) {
            full->batles.zone[i][index] = 'A' + full->anexs.indice;
            full->anexs.indice++;
        } else
            full->batles.zone[i][index] = ' ';
    }
}

void put_to_map(main_t *full, int i)
{
    for (int index = 0; index < 17; index++) {
        full->batles.zone[i][index] = '-';
    }
    full->batles.zone[i][1] = '+';
}

void put_in_map(main_t *full, int i)
{
    full->batles.zone[i][0] = '1' + full->anexs.indice;
    full->anexs.indice++;
    full->batles.zone[i][1] = '|';
    for (int index = 2; index < 17; index++) {
        if (index % 2 == 0)
            full->batles.zone[i][index] = '.';
        else
            full->batles.zone[i][index] = ' ';
    }
}

void create_map(main_t *full)
{
    full->anexs.indice = 0;
    full->batles.zone = malloc(sizeof(char *) * (10 + 1));
    full->batles.zone[10] = NULL;
    for (int i = 0; i < 10; i++) {
        full->batles.zone[i] = malloc(sizeof(char) * (17 + 1));
        full->batles.zone[i][17] = '\0';
    }
    put_all(full);
    print_boat(full);
    if (full->anexs.dead == 1)
        return;
}
