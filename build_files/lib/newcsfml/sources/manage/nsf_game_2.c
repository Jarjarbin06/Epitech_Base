/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include "../../includes/newcsfml.h"

nsf_window_t *nsf_game_get_window(nsf_game_t *game)
{
    if (!game)
        return NULL;
    return game->window;
}
