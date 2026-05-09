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

#include <SFML/Audio/Sound.h>

#include "newcsfml/audios/sound.h"
#include "newcsfml/systems/utils.h"

void nsf_sound_set_looping(const nsf_sound_t *sound, const bool looping)
{
    if (NSF_UNLIKELY(!sound))
        return;
    sfSound_setLoop(sound->sound, looping);
}

void nsf_sound_set_volume(const nsf_sound_t *sound, const float volume)
{
    if (NSF_UNLIKELY(!sound))
        return;
    sfSound_setVolume(sound->sound, volume);
}

nsf_sound_status_t nsf_sound_get_status(const nsf_sound_t *sound)
{
    if (NSF_UNLIKELY(!sound))
        return NSF_STT_SND_UNKNOWN;
    return (nsf_sound_status_t)sfSound_getStatus(sound->sound);
}
