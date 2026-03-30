/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include "newcsfml.h"

void nsf_game_draw(nsf_game_t *game)
{
    if (!game)
        return;
    nsf_window_draw(nsf_game_get_window(game));
}
