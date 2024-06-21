/*
** EPITECH PROJECT, 2024
** signal
** File description:
** management
*/
#include "def.h"

void send_back(main_t *full, int shoot, int wich)
{
    if (wich == 0) {
        if (shoot == 0)
            kill(full->pids.pid_usr1, SIGUSR1);
        if (shoot == 1)
            kill(full->pids.pid_usr1, SIGUSR2);
    }
    if (wich == 1) {
        if (shoot == 0)
            kill(full->pids.pid_usr2, SIGUSR1);
        if (shoot == 1)
            kill(full->pids.pid_usr2, SIGUSR2);
    }
}

void my_get_pid(int , siginfo_t *info, void *)
{
    int signalPid = -1;

    signalPid = info->si_pid;
    variable_global = signalPid;
}

void sig_handler3(int signo)
{
    int test = variable_global;

    if (signo == SIGUSR1) {
        if (test != variable_global) {
            variable_global -= 100;
        }
        variable_global -= 1;
    }
    if (signo == SIGUSR2) {
        variable_global -= 0.1;
    }
}

void sig_handler(int signo)
{
    if (signo == SIGUSR1) {
        if (variable_global == 1) {
            my_putstr("\nenemy connected\n\n");
            variable_global = 3;
        }
    }
}

void sig_handler1(int signo)
{
    if (signo == SIGUSR2) {
        variable_global = 48;
    }
}
