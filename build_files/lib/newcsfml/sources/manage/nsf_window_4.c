/*
** EPITECH PROJECT, 2025
** struct - nsf_window_1.c
** File description:
** <description>
*/

#include "../../includes/newcsfml.h"

int nsf_window_play_sound(nsf_window_t *window,
    const char sound_name[])
{
    if (!window || !sound_name)
        return EXIT_ERROR;
    nsf_sound_play(nsf_window_get_sound(window, sound_name));
    return EXIT_SUCCESS;
}

int nsf_window_pause_sound(nsf_window_t *window,
    const char sound_name[])
{
    if (!window || !sound_name)
        return EXIT_ERROR;
    nsf_sound_pause(nsf_window_get_sound(window, sound_name));
    return EXIT_SUCCESS;
}

int nsf_window_stop_sound(nsf_window_t *window,
    const char sound_name[])
{
    if (!window || !sound_name)
        return EXIT_ERROR;
    nsf_sound_stop(nsf_window_get_sound(window, sound_name));
    return EXIT_SUCCESS;
}
