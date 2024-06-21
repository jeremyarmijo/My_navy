/*
** EPITECH PROJECT, 2024
** signal
** File description:
** management
*/
#include "def.h"

void recevied_rocket2(main_t *full)
{
    int x = variable_global;
    float y = (variable_global - x);
    int true_y = 0;

    y = y * -1;
    y = (y * 10) + 0.5;
    true_y = y;
    x = -x;
    full->rockets.x = x;
    full->rockets.y = true_y;
    attack_management2(full, x, true_y, 0);
}

void recevied_rocket(main_t *full)
{
    int x = variable_global;
    float y = (variable_global - x);
    int true_y = 0;

    y = y * -1;
    y = (y * 10) + 0.5;
    true_y = y;
    x = -x;
    full->rockets.x = x;
    full->rockets.y = true_y;
    attack_management(full, x, true_y, 0);
}
