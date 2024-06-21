/*
** EPITECH PROJECT, 2024
** signal
** File description:
** management
*/
#include "def.h"

void value_back(main_t *full)
{
    free(full->open_file.buffer);
    full->open_file.buffer = malloc(sizeof(char) * 300);
    my_putstr("\nattack: ");
    while (1) {
        full->open_file.size = read(0, full->open_file.buffer, 300);
        if (if_good(full) == 42 && full->open_file.size != -1) {
            my_putstr("\nwrong position\n\nattack: ");
        }
        if (if_good(full) != 42 && full->open_file.size != -1) {
            full->rockets.coorx = (full->open_file.buffer[0] - 16);
            full->rockets.coory = (full->open_file.buffer[1]);
            my_putstr("\n");
            return;
        }
    }
}
