/*
** EPITECH PROJECT, 2024
** signal
** File description:
** management
*/
#include "def.h"

void management_game(main_t *full)
{
    variable_global = -1;
    my_putstr("successfully connected\n\n");
    print_maps(full);
    usleep(2000);
    kill(full->pids.pid_usr1, SIGUSR1);
    my_putstr("\nwaiting for enemy's attack...\n\n");
    variable_global = 0;
    signal(SIGUSR1, sig_handler3);
    signal(SIGUSR2, sig_handler3);
    for (int i = 0; variable_global > -100; i++)
        pause();
    variable_global = variable_global + 101;
    recevied_rocket(full);
    signal(SIGUSR2, sig_handler1);
    pause();
}

void usr2(main_t *full)
{
    management_game(full);
    while (full->anexs.win == 0) {
        variable_global = 0;
        value_back(full);
        send_attack_to1(full, 1);
        print_maps(full);
        my_putstr("\nwaiting for enemy's attack...\n\n");
        variable_global = 0;
        signal(SIGUSR1, sig_handler3);
        signal(SIGUSR2, sig_handler3);
        for (int i = 0; variable_global > -100; i++)
            pause();
        variable_global = variable_global + 101;
        recevied_rocket(full);
        if_win(full);
    }
    if (full->anexs.win == 2)
        my_putstr("I won\n");
    if (full->anexs.win == 1)
        my_putstr("Enemy won\n");
}

void before_game(main_t *full, struct sigaction *sa)
{
    usleep(2000);
    sa->sa_flags = SA_SIGINFO;
    sa->sa_sigaction = my_get_pid;
    sigaction(SIGUSR1, sa, NULL);
    usr1(full);
    value_back(full);
    send_attack_to2(full, 0);
    my_putstr("waiting for enemy's attack...\n\n");
}

void player_1(struct sigaction *sa, main_t *full)
{
    before_game(full, sa);
    while (full->anexs.win == 0) {
        variable_global = 0;
        signal(SIGUSR1, sig_handler3);
        signal(SIGUSR2, sig_handler3);
        for (int i = 0; variable_global > -100; i++)
            pause();
        variable_global = variable_global + 101;
        recevied_rocket2(full);
        print_maps(full);
        value_back(full);
        send_attack_to2(full, 0);
        my_putstr("waiting for enemy's attack...\n\n");
        if_win(full);
    }
    if (full->anexs.win == 2)
        my_putstr("I won\n");
    if (full->anexs.win == 1)
        my_putstr("Enemy won\n");
}

static void prepare_game(int *i, int *pid)
{
        if (*i == 0)
            print_pid(*pid);
        *i = 1;
        usleep(2000);
}

void signal_management(main_t *full)
{
    int pid = getpid();
    int i = 0;
    struct sigaction sa;

    full->anexs.win = 0;
    while (1) {
        prepare_game(&i, &pid);
        signal(SIGUSR1, sig_handler);
        if (variable_global == 3) {
            variable_global = -1;
            player_1(&sa, full);
        }
        if (variable_global == 2)
            usr2(full);
        if (variable_global == 42)
            value_back(full);
        if (full->anexs.win != 0)
            return;
    }
}
