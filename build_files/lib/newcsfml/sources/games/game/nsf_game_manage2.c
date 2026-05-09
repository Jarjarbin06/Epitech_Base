/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.4
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

#include "newcsfml/audios/sound.h"
#include "newcsfml/games/window.h"
#include "newcsfml/games/game.h"
#include "newcsfml/graphics/sprite.h"
#include "newcsfml/graphics/button.h"
#include "newcsfml/graphics/text.h"
#include "newcsfml/graphics/particle.h"
#include "newcsfml/systems/utils.h"

nsf_sprite_t *nsf_game_get_sprite(const nsf_game_t *game,
    const char sprite_name[])
{
    if (NSF_UNLIKELY(!game || !game->window || !sprite_name))
        return NULL;
    return nsf_window_get_sprite(game->window, sprite_name);
}

nsf_button_t *nsf_game_get_button(const nsf_game_t *game, const char
    button_name[])
{
    if (NSF_UNLIKELY(!game || !game->window || !button_name))
        return NULL;
    return nsf_window_get_button(game->window, button_name);
}

nsf_sound_t *nsf_game_get_sound(const nsf_game_t *game, const char sound_name[])
{
    if (NSF_UNLIKELY(!game || !game->window || !sound_name))
        return NULL;
    return nsf_window_get_sound(game->window, sound_name);
}

nsf_text_t *nsf_game_get_text(const nsf_game_t *game, const char text_name[])
{
    if (NSF_UNLIKELY(!game || !game->window || !text_name))
        return NULL;
    return nsf_window_get_text(game->window, text_name);
}

nsf_particle_t *nsf_game_get_particle(const nsf_game_t *game,
    const char particle_name[])
{
    if (NSF_UNLIKELY(!game || !game->window || !particle_name))
        return NULL;
    return nsf_window_get_particle(game->window, particle_name);
}
