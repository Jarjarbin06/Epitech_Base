/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include "../../includes/newcsfml.h"

nsf_sprite_t *nsf_game_get_sprite(nsf_game_t *game, const char sprite_name[])
{
    if (!game || !sprite_name)
        return NULL;
    return nsf_window_get_sprite(nsf_game_get_window(game), sprite_name);
}

nsf_button_t *nsf_game_get_button(nsf_game_t *game, const char button_name[])
{
    if (!game || !button_name)
        return NULL;
    return nsf_window_get_button(nsf_game_get_window(game), button_name);
}

nsf_sound_t *nsf_game_get_sound(nsf_game_t *game, const char sound_name[])
{
    if (!game || !sound_name)
        return NULL;
    return nsf_window_get_sound(nsf_game_get_window(game), sound_name);
}
