/*
** EPITECH PROJECT, 2024
** base
** File description:
** base
*/

#include "def.h"

static int init(main_t *full, int ac, char **av, int player)
{
    if (ac == 3)
        full->pids.pid_usr1 = my_getnbr(av[1]);
    if (my_strcopy(av[1], "-h") == 1){
        usage();
        return 84;
    }
    full->open_file.fd = open(av[player], O_RDONLY);
    full->open_file.size = 32;
    full->open_file.buffer = malloc(sizeof(char) * (full->open_file.size + 1));
    return 0;
}

static int error(main_t *full)
{
    if (full->open_file.fd != 3)
        return 84;
    if (full->open_file.size == 0)
        return 84;
    return 0;
}

void map_value(main_t *full)
{
    int i = 0;
    int j = 0;
    int y = 0;

    full->dim.map = malloc(sizeof(char *) * (full->dim.coll + 1));
    for (i = 0; i < full->dim.coll; i++)
        full->dim.map[i] = malloc(sizeof(char) * (full->dim.line + 1));
    for (i = 0; i < full->open_file.size; i++) {
        for (j = 0; j < full->dim.line; j++) {
            full->dim.map[y][j] = full->open_file.buffer[i];
            i++;
        }
        if (full->open_file.buffer[i] == '\n')
            full->dim.map[y][j] = '\0';
        y++;
    }
    full->dim.map[full->dim.coll] = NULL;
}

void put_value(main_t *full, int pos)
{
    int i = 0;

    if (MAP_1[pos][3] > MAP_1[pos][6]) {
        i = MAP_1[pos][3];
        MAP_1[pos][3] = MAP_1[pos][6];
        MAP_1[pos][6] = i;
    }
    full->boot[pos].first_y = (full->dim.map[pos][3] - 48);
    full->boot[pos].first_x = (full->dim.map[pos][2] - 64);
    full->boot[pos].second_y = (full->dim.map[pos][6] - 48);
    full->boot[pos].second_x = (full->dim.map[pos][5] - 64);
}

int if_break(main_t *full, int pos, int ref, int result)
{
    if (full->dim.map[pos][5] < 'A' || full->dim.map[pos][5] > 'H'
    || full->dim.map[pos][2] < 'A' || full->dim.map[pos][2] > 'H')
        return 84;
    if (ref < 2 || ref > 5)
        return 84;
    if (result < 0)
        return 84;
    if ((full->dim.map[pos][3] - 48) > 8
    || (full->dim.map[pos][3] - 48) < 1
    || (full->dim.map[pos][6] - 48) > 8
    || (full->dim.map[pos][6] - 48) < 1)
        return 84;
    if (full->dim.map[pos][2] != full->dim.map[pos][5]
    && full->dim.map[pos][3] != full->dim.map[pos][6])
        return 84;
    return 0;
}

int check_line(main_t *full, int pos)
{
    int ref = (full->dim.map[pos][0] - 48);
    int result = MAP_1[pos][5] - MAP_1[pos][2];
    int i = 0;

    DIGIT_1 = MAP_1[pos][6] - MAP_1[pos][3];
    if (if_break(full, pos, ref, result) == 84)
        return 84;
    if (full->anexs.digit == 0) {
        i = 0;
        while ((full->dim.map[pos][2] + i) <= (full->dim.map[pos][5]))
            i++;
        if (i != ref)
            return 84;
    }
    full->boot[pos].ref = ref;
    put_value(full, pos);
    return 0;
}

static int is_ok(main_t *full)
{
    int error = 0;

    full->boot = malloc(sizeof(boot2_t) * (full->dim.coll + 1));
    full->boot[full->dim.coll].first_x = -42;
    for (int i = 0; i < full->dim.coll; i++) {
        error = check_line(full, i);
        if (error == 84)
            return 84;
    }
    return 0;
}

static int two_arg(main_t *full, int ac, char **av)
{
    int val = 0;
    int value = 0;

    val = init(full, ac, av, ac - 1);
    value = error(full);
        if (val == 84 || value == 84)
            return 84;
        read(full->open_file.fd, full->open_file.buffer, full->open_file.size);
        full->dim.line = 0;
        full->dim.coll = 0;
        coll_lines(full);
        if (full->dim.line != 7)
            return 84;
        map_value(full);
        close(full->open_file.fd);
        if (is_ok(full) == 84)
            return 84;
        return 0;
}

static int args_three(main_t *full, int ac, char **av)
{
    int val = 0;
    int value = 0;

    val = init(full, ac, av, ac - 1);
    value = error(full);
    if (val == 84 || value == 84)
        return 84;
    read(full->open_file.fd, full->open_file.buffer, full->open_file.size);
    full->dim.line = 0;
    full->dim.coll = 0;
    coll_lines(full);
    if (full->dim.line != 7)
        return 84;
    map_value(full);
    if (is_ok(full) == 84)
        return 84;
    if (kill(my_getnbr(av[1]), SIGUSR1) == -1)
        return 84;
    return 0;
}

int base(main_t *full, int ac, char **av)
{
    int val = 0;
    int value = 0;

    full->player = 0;
    if (ac != 2 && ac != 3)
        return 84;
    if (ac == 2) {
        full->player = 1;
        val = two_arg(full, ac, av);
    }
    if (ac == 3) {
        full->player = 2;
        value = args_three(full, ac, av);
        close(full->open_file.fd);
    }
    if (value == 84 || val == 84)
        return 84;
    return 0;
}
