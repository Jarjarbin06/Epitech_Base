/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.1
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
#include "newcsfml/systems/vector.h"
#include "newcsfml/games/window_settings.h"
#include "newcsfml/games/window.h"
#include "newcsfml/graphics/sprite.h"
#include "newcsfml/graphics/texture.h"
#include "newcsfml/systems/other.h"
#include "newcsfml/graphics/background.h"
#include "newcsfml/systems/utils.h"

nsf_background_t *nsf_background_create(const char path[],
    const nsf_window_t *window, nsf_game_t *game)
{
    nsf_background_t *new_background = malloc_any(sizeof(nsf_background_t));
    nsf_sprite_t *new_sprite = nsf_sprite_create("background", game);
    nsf_texture_t *new_texture = nsf_texture_create(path, "background", game);
    nsf_uvector_t window_size = {0, 0};

    if (NSF_UNLIKELY(!new_background || !new_sprite || !new_texture))
        return NULL;
    window_size.x = window->settings->width;
    window_size.y = window->settings->height;
    nsf_sprite_set_texture(new_sprite, new_texture);
    nsf_sprite_set_size(new_sprite, &window_size);
    nsf_sprite_set_position(new_sprite, (nsf_fvector_t[]){{0.0f, 0.0f}});
    new_background->sprite = new_sprite;
    new_background->texture = new_texture;
    if (game)
        game->allocations++;
    return new_background;
}

int nsf_background_destroy(nsf_background_t **background, nsf_game_t *game)
{
    if (NSF_UNLIKELY(!background || !*background))
        return EXIT_ERROR;
    if (NSF_LIKELY((*background)->sprite))
        nsf_sprite_destroy(&(*background)->sprite, game);
    *background = free_any(*background);
    if (game)
        game->allocations--;
    return EXIT_SUCCESS;
}
