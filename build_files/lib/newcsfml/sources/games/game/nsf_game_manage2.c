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

#include "newcsfml/audios/sound.h"
#include "newcsfml/games/window.h"
#include "newcsfml/games/game.h"
#include "newcsfml/systems/utils.h"

nsf_sprite_t *nsf_game_get_sprite(const nsf_game_t *game,
    const char sprite_name[])
{
    if (NSF_UNLIKELY(!game || !sprite_name))
        return NULL;
    return nsf_window_get_sprite(nsf_game_get_window(game), sprite_name);
}

nsf_button_t *nsf_game_get_button(const nsf_game_t *game, const char
    button_name[])
{
    if (NSF_UNLIKELY(!game || !button_name))
        return NULL;
    return nsf_window_get_button(nsf_game_get_window(game), button_name);
}

nsf_sound_t *nsf_game_get_sound(const nsf_game_t *game, const char sound_name[])
{
    if (NSF_UNLIKELY(!game || !sound_name))
        return NULL;
    return nsf_window_get_sound(nsf_game_get_window(game), sound_name);
}
