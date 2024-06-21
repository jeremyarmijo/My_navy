/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** taille d'un mot
*/

#include "def.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}
