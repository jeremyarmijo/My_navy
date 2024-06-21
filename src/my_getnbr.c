/*
** EPITECH PROJECT, 2023
** bootcamp
** File description:
** step2
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int nbr = 0;
    int my_bool = 0;

    while (str[i] != '\0'){
        if (str[i] >= '0' && str[i] <= '9')
            nbr = nbr * 10 + str[i] - 48;
        if (str[i - 1] == '-')
            my_bool = 1;
        i++;
    }
    if (my_bool == 1)
        nbr = nbr * -1;
    return nbr;
}
