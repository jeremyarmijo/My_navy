/*
** EPITECH PROJECT, 2023
** my_strcopy
** File description:
** verifi si deux chaine son identique
*/

#include "def.h"

int my_strcopy(char *str1, char *str2)
{
    int i = 0;

    if (my_strlen(str1) > my_strlen(str2))
        return -1;
    if (my_strlen(str1) < my_strlen(str2))
        return -1;
    while (str1[i] != '\0'){
        if ((str1[i] - str2[i]) > 0)
            return -1;
        if ((str1[i] - str2[i]) < 0)
            return -1;
        i++;
    }
    return 1;
}
