/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include "../../includes/newcsfml.h"

int nsf_game_display(nsf_game_t *game)
{
    if (!game || !game->window)
        return EXIT_ERROR;
    nsf_window_display(game->window);
    return EXIT_SUCCESS;
}

bool nsf_game_isopen(nsf_game_t *game)
{
    if (!game || !game->window)
        return false;
    return nsf_window_isopen(game->window);
}

void nsf_game_close(nsf_game_t *game)
{
    if (!game || !game->window)
        return;
    nsf_window_close(game->window);
}

bool nsf_game_get_event(nsf_game_t *game, nsf_event_t *event)
{
    if (!game || !game->window)
        return false;
    return nsf_window_get_event(game->window, event);
}

void nsf_game_set_window(nsf_game_t *game, nsf_window_t *window)
{
    if (!game || !window)
        return;
    game->window = window;
}
