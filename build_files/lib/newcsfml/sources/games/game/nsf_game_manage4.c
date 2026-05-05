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

#include "newcsfml/audios/music.h"
#include "newcsfml/games/game.h"
#include "newcsfml/systems/utils.h"

void nsf_game_set_music(nsf_game_t *game, nsf_music_t *music)
{
    if (NSF_UNLIKELY(!game || !music))
        return;
    game->music = music;
}

nsf_music_t *nsf_game_get_music(const nsf_game_t *game)
{
    if (NSF_UNLIKELY(!game || !game->music))
        return NULL;
    return game->music;
}

void nsf_game_play_music(const nsf_game_t *game)
{
    if (NSF_UNLIKELY(!game || !game->music))
        return;
    nsf_music_play(game->music);
}

void nsf_game_stop_music(const nsf_game_t *game)
{
    if (NSF_UNLIKELY(!game || !game->music))
        return;
    nsf_music_stop(game->music);
}

void nsf_game_set_music_volume(const nsf_game_t *game, const float volume)
{
    if (NSF_UNLIKELY(!game || !game->music))
        return;
    nsf_music_volume(game->music, volume);
}
