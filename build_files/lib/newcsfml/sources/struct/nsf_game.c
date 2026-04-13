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

    if (!new_game) {
        free(new_game);
        return NULL;
    }
    new_game->allocations = 0;
    new_game->window = NULL;
    new_game->music = NULL;
    return new_game;
}

int nsf_game_destroy(nsf_game_t **game)
{
    if (!game || !*game)
        return EXIT_ERROR;
    nsf_auto_free(2, (nsf_free_t[]){
        {(*game)->window, &(*game)->window, sfMusic_destroy},
        {(*game)->music, &(*game)->music, free_any}
    }, *game);
    return EXIT_SUCCESS;
}
