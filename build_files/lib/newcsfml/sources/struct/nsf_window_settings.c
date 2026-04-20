/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include <SFML/Graphics/RenderWindow.h>

#include "../../includes/newcsfml.h"

nsf_window_settings_t *nsf_window_settings_create(
    const nsf_window_settings_t settings[], nsf_game_t *game)
{
    nsf_window_settings_t *new_settings = malloc_any(
        sizeof(nsf_window_settings_t));

    if (!new_settings)
        return NULL;
    new_settings->bpp = settings->bpp;
    new_settings->fps = settings->fps;
    new_settings->height = settings->height;
    new_settings->width = settings->width;
    if (game)
        game->allocations++;
    return new_settings;
}

int nsf_window_settings_destroy(nsf_window_settings_t **settings,
    nsf_game_t *game)
{
    if (!settings || !*settings)
        return EXIT_ERROR;
    *settings = free_any(*settings);
    if (game)
        game->allocations--;
    return EXIT_SUCCESS;
}
