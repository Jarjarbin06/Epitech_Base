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

void nsf_game_add_sprite(nsf_game_t *game, nsf_sprite_t *sprite)
{
    if (!game || !sprite)
        return;
    nsf_window_add_sprite(nsf_game_get_window(game), sprite, game);
}

void nsf_game_add_button(nsf_game_t *game, nsf_button_t *button)
{
    if (!game || !button)
        return;
    nsf_window_add_button(nsf_game_get_window(game), button, game);
}

nsf_sprite_t *nsf_game_get_sprite(nsf_game_t *game, const char sprite_name[])
{
    if (!game || !sprite_name)
        return NULL;
    return nsf_window_get_sprite(nsf_game_get_window(game), sprite_name);
}

nsf_button_t *nsf_game_get_button(nsf_game_t *game, const char sprite_name[])
{
    if (!game || !sprite_name)
        return NULL;
    return nsf_window_get_button(nsf_game_get_window(game), sprite_name);
}
