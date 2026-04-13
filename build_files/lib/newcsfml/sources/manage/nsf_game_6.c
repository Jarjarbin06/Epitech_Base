/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include "../../includes/newcsfml.h"

int nsf_game_all_sound_volume(nsf_game_t *game,
    const float volume)
{
    if (!game)
        return EXIT_ERROR;
    nsf_window_all_sound_volume(nsf_game_get_window(game), volume);
    return EXIT_SUCCESS;
}

int nsf_game_stop_all_sound(nsf_game_t *game)
{
    if (!game)
        return EXIT_ERROR;
    nsf_window_stop_all_sound(nsf_game_get_window(game));
    return EXIT_SUCCESS;
}
