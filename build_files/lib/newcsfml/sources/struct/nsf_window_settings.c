/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include <SFML/Graphics/RenderWindow.h>

#include "../../includes/newcsfml.h"

static int check_ptr(nsf_window_settings_t **settings, nsf_game_t *game)
{
    if (!settings || !*settings) {
        nsf_window_setting_destroy(settings, game);
        return 1;
    }
    return 0;
}

nsf_window_settings_t *nsf_window_setting_create(
    const nsf_window_settings_t settings[], nsf_game_t *game)
{
    nsf_window_settings_t *new_settings = nsf_malloc_any(
        sizeof(nsf_window_settings_t), game);

    if (check_ptr(&new_settings, game))
        return NULL;
    new_settings->bpp = settings->bpp;
    new_settings->fps = settings->fps;
    new_settings->height = settings->height;
    new_settings->width = settings->width;
    return new_settings;
}

int nsf_window_setting_destroy(nsf_window_settings_t **settings,
    nsf_game_t *game)
{
    if (!settings || !*settings)
        return EXIT_ERROR;
    *settings = nsf_free_any(settings, game);
    return EXIT_SUCCESS;
}
