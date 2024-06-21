/*
** EPITECH PROJECT, 2023
** HEADER
** File description:
** HEADER
*/

#ifndef _STRUCT_
    #define _STRUCT_
    #include "def.h"

typedef struct open_file {
    int fd;
    int size;
    char *buffer;
}open_file_t;

typedef struct dimension_ {
    int coll;
    int line;
    char **map;
    char **map2;
    int i;
    int y;
    int error;
} dimension_t;

typedef struct batle {
    char **zone;
    char **zone2;
}batle_t;

typedef struct pid_usr {
    int pid_usr1;
    int pid_usr2;
}pid_usr_t;

typedef struct boot2 {
    int ref;
    int first_x;
    int first_y;
    int second_x;
    int second_y;
    int direction_boat;
}boot2_t;

typedef struct anex {
    int dead;
    int win;
    int indice;
    int let;
    int nbr;
    int digit;
}anex_t;

typedef struct rocket {
    int coorx;
    int coory;
    float send;
    int x;
    int y;
    int one_two;
}rocket_t;

typedef struct main {
    open_file_t open_file;
    anex_t anexs;
    dimension_t dim;
    boot2_t *boot;
    batle_t batles;
    pid_usr_t pids;
    rocket_t rockets;
    int player;
}main_t;

#endif
