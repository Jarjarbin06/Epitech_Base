/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include "../../includes/newcsfml.h"

int nsf_game_update(nsf_game_t *game)
{
    if (!game)
        return EXIT_ERROR;
    nsf_window_update_settings(nsf_game_get_window(game));
    return EXIT_SUCCESS;
}
