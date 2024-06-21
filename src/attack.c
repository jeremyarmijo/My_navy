/*
** EPITECH PROJECT, 2024
** signal
** File description:
** management
*/
#include "def.h"

void attack_management2(main_t *full, int letter_x, int y, int shoot)
{
    if (full->batles.zone[y + 1][letter_x * 2] != '.') {
        full->batles.zone[y + 1][letter_x * 2] = 'x';
        my_putstr("result: ");
        my_putchar(letter_x + 64);
        my_putchar(y + 48);
        my_putstr(":hit\n\n");
        shoot++;
    } else {
        full->batles.zone[y + 1][letter_x * 2] = 'o';
            my_putstr("result: ");
        my_putchar(letter_x + 64);
        my_putchar(y + 48);
        my_putstr(":missed\n\n");
    }
    send_back(full, shoot, 1);
}

void attack_management(main_t *full, int letter_x, int y, int shoot)
{
    if (full->batles.zone[y + 1][letter_x * 2] != '.') {
        full->batles.zone[y + 1][letter_x * 2] = 'x';
        my_putstr("result: ");
        my_putchar(letter_x + 64);
        my_putchar(y + 48);
        my_putstr(":hit\n");
        shoot++;
    } else {
        full->batles.zone[y + 1][letter_x * 2] = 'o';
            my_putstr("result: ");
        my_putchar(letter_x + 64);
        my_putchar(y + 48);
        my_putstr(":missed\n");
    }
    send_back(full, shoot, 0);
}
