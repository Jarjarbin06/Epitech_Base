/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include <stdlib.h>

#include "../../includes/newcsfml.h"

nsf_game *nsf_game_create(const char title[])
{
    nsf_game *nsf_new_game = malloc(sizeof(nsf_game));
    char *game_title = my_strdup(title);

    if (!nsf_new_game) {
        free(nsf_new_game);
        return NULL;
    }
    nsf_new_game->allocations = 2;
    if (game_title)
        nsf_new_game->allocations++;
    nsf_new_game->window = NULL;
    nsf_new_game->title = game_title;
    return nsf_new_game;
}

int nsf_game_destroy(nsf_game **nsf_game)
{
    nsf_uint allocs = 0;

    if (!nsf_game || !*nsf_game)
        return EXIT_ERROR;
    nsf_window_destroy(&(*nsf_game)->window, *nsf_game);
    nsf_auto_free(1, (free_t[]){
        {(*nsf_game)->title, &((*nsf_game)->title),
            (void_func_t)free_any}}, *nsf_game);
    allocs = (*nsf_game)->allocations;
    *nsf_game = free_any(*nsf_game);
    if (allocs > 1)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}
