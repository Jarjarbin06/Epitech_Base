/*
** EPITECH PROJECT, 2025
** concat_params.c
** File description:
** None
*/

#include <stdlib.h>
#include "my.h"

char *concat_params(int argc, char **argv)
{
    int total_len = 0;
    int dest_idx = 0;
    char *dest;

    for (int argv_idx = 0; argv_idx < argc; argv_idx++) {
        for (int idx = 0; argv[argv_idx][idx] != '\0'; idx++)
            total_len++;
        total_len++;
    }
    dest = malloc(total_len);
    for (int argv_idx = 0; argv_idx < argc; argv_idx++) {
        for (int idx = 0; argv[argv_idx][idx] != '\0'; idx++) {
            dest[dest_idx] = argv[argv_idx][idx];
            dest_idx++;
        }
        dest[dest_idx] = '\n';
        dest_idx++;
    }
    dest[dest_idx - 1] = '\0';
    return dest;
}
