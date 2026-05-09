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

#include <SFML/Audio/Music.h>

#include "newcsfml/systems/utils.h"
#include "newcsfml/audios/music.h"

void nsf_music_play(const nsf_music_t *music)
{
    if (NSF_UNLIKELY(!music))
        return;
    sfMusic_play(music->music);
}

void nsf_music_pause(const nsf_music_t *music)
{
    if (NSF_UNLIKELY(!music))
        return;
    sfMusic_pause(music->music);
}

void nsf_music_stop(const nsf_music_t *music)
{
    if (NSF_UNLIKELY(!music))
        return;
    sfMusic_stop(music->music);
}
