/*
** EPITECH PROJECT, 2024
** signal
** File description:
** management
*/
#include "def.h"

void sig_handler4(int signo)
{
    if (signo == SIGUSR1) {
        variable_global = 100;
    }
    if (signo == SIGUSR2) {
        variable_global = 200;
    }
}

void recup_back(main_t *full, int who)
{
    signal(SIGUSR1, sig_handler4);
    signal(SIGUSR2, sig_handler4);
    pause();
    if (who == 0)
        miss_or_hit1(full);
    else
        miss_or_hit2(full);
}

void send_attack_to2(main_t *full, int cpt)
{
    full->rockets.coory = (full->rockets.coory - 48);
    full->rockets.coorx = (full->rockets.coorx - 48);
    if (variable_global > 999)
        full->pids.pid_usr2 = variable_global;
    for (int i = 0; i < full->rockets.coorx; i++) {
        cpt++;
        usleep(2000);
        kill(full->pids.pid_usr2, SIGUSR1);
    }
    for (int i = 0; i < full->rockets.coory; i++) {
        cpt++;
        usleep(2000);
        kill(full->pids.pid_usr2, SIGUSR2);
    }
    usleep(2000);
    kill(full->pids.pid_usr2, SIGUSR1);
    recup_back(full, 1);
}

void send_attack_to1(main_t *full, int cpt)
{
    full->rockets.coory = (full->rockets.coory - 48);
    full->rockets.coorx = (full->rockets.coorx - 48);
    for (int i = 0; i < full->rockets.coorx; i++) {
        cpt++;
        usleep(2000);
        kill(full->pids.pid_usr1, SIGUSR1);
    }
    for (int i = 0; i < full->rockets.coory; i++) {
        cpt++;
        usleep(2000);
        kill(full->pids.pid_usr1, SIGUSR2);
    }
    usleep(2000);
    kill(full->pids.pid_usr1, SIGUSR1);
    recup_back(full, 0);
}
