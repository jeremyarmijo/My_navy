/*
** EPITECH PROJECT, 2023
** Put character
** File description:
** Print a char
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
