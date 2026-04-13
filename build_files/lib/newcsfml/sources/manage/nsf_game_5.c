/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include "../../includes/newcsfml.h"

int nsf_game_play_sound(nsf_game_t *game,
    const char sound_name[])
{
    if (!game || !sound_name)
        return EXIT_ERROR;
    nsf_window_play_sound(nsf_game_get_window(game), sound_name);
    return EXIT_SUCCESS;
}

int nsf_game_pause_sound(nsf_game_t *game,
    const char sound_name[])
{
    if (!game || !sound_name)
        return EXIT_ERROR;
    nsf_window_pause_sound(nsf_game_get_window(game), sound_name);
    return EXIT_SUCCESS;
}

int nsf_game_stop_sound(nsf_game_t *game,
    const char sound_name[])
{
    if (!game || !sound_name)
        return EXIT_ERROR;
    nsf_window_stop_sound(nsf_game_get_window(game), sound_name);
    return EXIT_SUCCESS;
}
