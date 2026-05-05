/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.3
** Author: Jarjarbin06
** License: GPL v3
** •
** This library is inspired by SFML/CSFML and is designed for
** educational and game-development purposes.
** •
** It provides higher-level abstractions over CSFML to reduce
** boilerplate code and enforce safer usage patterns.
** •
** WARNING:
** This is NOT the original SFML/CSFML library.
** It is a custom implementation layer built on top of CSFML.
*/

#include "newcsfml/games/game.h"
#include "newcsfml/games/window_settings.h"
#include "newcsfml/systems/other.h"
#include "newcsfml/systems/utils.h"

nsf_window_settings_t *nsf_window_settings_create(
    const nsf_window_settings_t settings[], nsf_game_t *game)
{
    nsf_window_settings_t *new_settings = malloc_any(
        sizeof(nsf_window_settings_t));

    if (NSF_UNLIKELY(!new_settings))
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
    if (NSF_UNLIKELY(!settings || !*settings))
        return EXIT_ERROR;
    *settings = free_any(*settings);
    if (game)
        game->allocations--;
    return EXIT_SUCCESS;
}
