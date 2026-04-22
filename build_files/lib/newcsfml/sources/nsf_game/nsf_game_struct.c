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
    nsf_game_t *new_game = malloc(sizeof(nsf_game_t));

    if (!new_game)
        return NULL;
    new_game->allocations = 1;
    new_game->window = NULL;
    new_game->music = NULL;
    new_game->data = NULL;
    return new_game;
}

int nsf_game_destroy(nsf_game_t **game)
{
    nsf_uint_t allocations = (*game)->allocations;

    if (!game || !*game)
        return -1;
    if ((*game)->window)
        nsf_window_destroy(&(*game)->window, *game);
    if ((*game)->music)
        nsf_music_destroy(&(*game)->music, *game);
    *game = free_any(*game);
    allocations--;
    return (int)allocations;
}
