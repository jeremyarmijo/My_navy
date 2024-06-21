/*
** EPITECH PROJECT, 2023
** HEADER
** File description:
** HEADER
*/
#ifndef DEF
    #define DEF
    #include "my.h"
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <signal.h>
    #define ZONE_1 full->batles.zone
    #define BOAT_1 full->boot
    #define ZONEXYF_2 ZONE_1[BOAT_1[i].first_y + 1][BOAT_1[i].first_x * 2]
    #define ZONEXYS_2 ZONE_1[BOAT_1[i].second_y + 1][BOAT_1[i].second_x * 2]
    #define FOR_1 ZONE_1[BOAT_1[i].first_y + 2 + index][BOAT_1[i].first_x * 2]
    #define FOR2_1 ZONE_1[BOAT_1[i].second_y + 1][BOAT_1[i].second_x * 2]
    #define PUT_1 BOAT_1[i].first_y + 1
    #define FOR_2 ZONE_1[PUT_1][(BOAT_1[i].first_x * 2) + 1 + index]
    #define FOR2_2 ZONE_1[BOAT_1[i].second_y + 1][(BOAT_1[i].second_x * 2)]
    #define PUT_2 (BOAT_1[i].first_x * 2) + 1 + index
    #define COND_1  ZONE_1[BOAT_1[i].first_y + 1][PUT_2]
    #define COND_0 ZONE_1[BOAT_1[i].first_y + 2 + index][BOAT_1[i].first_x * 2]
    #define MAP_1 full->dim.map
    #define ZONE_2 full->batles.zone2
    #define DIGIT_1 full->anexs.digit

extern float variable_global;
void sig_handler1(int signo);
void sig_handler(int signo);
void sig_handler3(int signo);
void my_get_pid(int sig, siginfo_t *info, void *context);
void send_back(main_t *full, int shoot, int wich);
void recevied_rocket(main_t *full);
void recevied_rocket2(main_t *full);
void attack_management(main_t *full, int letter_x, int y, int shoot);
void attack_management2(main_t *full, int letter_x, int y, int shoot);
void if_win(main_t *full);
int check_up(char map, int cpt);
void miss_or_hit2(main_t *full);
void miss_or_hit1(main_t *full);
void value_back(main_t *full);
void send_attack_to1(main_t *full, int shoot);
void send_attack_to2(main_t *full, int shoot);
void print_pid(int pid);
void print_maps(main_t *full);
void usr1(main_t *full);
void my_putchar(char c);
int my_put_nbr(int n);
int base(main_t *full, int ac, char **av);
int my_strlen(char *str);
void put_value(main_t *full, int pos);
int my_strcopy(char *str1, char *str2);
void my_putstr(char *str);
void put_map(main_t *full, int i);
void put_to_map(main_t *full, int i);
void put_in_map(main_t *full, int i);
void create_map_enemy(main_t *full);
void create_map(main_t *full);
void put_in_map(main_t *full, int i);
void put_to_map(main_t *full, int i);
void put_map(main_t *full, int i);
void put_all(main_t *full);
void verify_is_num(main_t *full, char num);
void put_on_boat(main_t *full, int i, int who);
void print_boat(main_t *full);
void usage(void);
void coll_lines(main_t *full);
void signal_management(main_t *full);
int my_getnbr(char const *str);
int if_good(main_t *full);

#endif
