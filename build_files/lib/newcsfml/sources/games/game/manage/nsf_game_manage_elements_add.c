/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.8
** Author: Jarjarbin06
** Licence: GPL v3
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
#include "newcsfml/graphics/button.h"
#include "newcsfml/graphics/sprite.h"
#include "newcsfml/graphics/text.h"
#include "newcsfml/systems/utils.h"

void nsf_game_add_sprite(nsf_game_t *game, nsf_sprite_t *sprite)
{
    if (NSF_UNLIKELY(!game || !game->window || !sprite))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_GAME, __FUNCTION__,
            "pointer corrupted");
    nsf_window_add_sprite(game->window, sprite, game);
}

void nsf_game_add_button(nsf_game_t *game, nsf_button_t *button)
{
    if (NSF_UNLIKELY(!game || !game->window || !button))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_GAME, __FUNCTION__,
            "pointer corrupted");
    nsf_window_add_button(game->window, button, game);
}

void nsf_game_add_sound(nsf_game_t *game, nsf_sound_t *sound)
{
    if (NSF_UNLIKELY(!game || !game->window || !sound))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_GAME, __FUNCTION__,
            "pointer corrupted");
    nsf_window_add_sound(game->window, sound, game);
}

void nsf_game_add_text(nsf_game_t *game, nsf_text_t *text)
{
    if (NSF_UNLIKELY(!game || !game->window || !text))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_GAME, __FUNCTION__,
            "pointer corrupted");
    nsf_window_add_text(game->window, text, game);
}

void nsf_game_add_particle(nsf_game_t *game, nsf_particle_t *particle)
{
    if (NSF_UNLIKELY(!game || !game->window || !particle))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_GAME, __FUNCTION__,
            "pointer corrupted");
    nsf_window_add_particle(game->window, particle, game);
}
