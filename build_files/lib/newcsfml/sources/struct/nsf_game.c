/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include <stdlib.h>

#include "../../includes/newcsfml.h"

nsf_game_t *nsf_game_create(void)
{
    nsf_game_t *nsf_new_game = malloc(sizeof(nsf_game_t));

    if (!nsf_new_game) {
        free(nsf_new_game);
        return NULL;
    }
    nsf_new_game->allocations = 0;
    nsf_new_game->window = NULL;
    return nsf_new_game;
}

int nsf_game_destroy(nsf_game_t **nsf_game)
{
    if (!nsf_game || !*nsf_game)
        return EXIT_ERROR;
    if ((*nsf_game)->window)
        nsf_window_destroy(&(*nsf_game)->window, *nsf_game);
    *nsf_game = free_any(*nsf_game);
    return EXIT_SUCCESS;
}
