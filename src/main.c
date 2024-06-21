/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** my_navy
*/
#include "def.h"
float variable_global = -1;

int main(int ac, char **av)
{
    main_t *full = malloc(sizeof(main_t));
    int error = base(full, ac, av);

    full->anexs.win = 0;
    full->anexs.dead = 0;
    if (error == 84)
        return 84;
    create_map(full);
    create_map_enemy(full);
    variable_global = full->player;
    signal_management(full);
    if (full->anexs.dead == 1)
        return 84;
    return 0;
}
