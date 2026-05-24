/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.7
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

#include <SFML/Audio/Sound.h>

#include "newcsfml/audios/sound.h"
#include "newcsfml/systems/utils.h"

void nsf_sound_play(const nsf_sound_t *sound)
{
    if (NSF_UNLIKELY(!sound))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_SOUND, __FUNCTION__,
            "pointer corrupted");
    sfSound_play(sound->sound);
}

void nsf_sound_pause(const nsf_sound_t *sound)
{
    if (NSF_UNLIKELY(!sound))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_SOUND, __FUNCTION__,
            "pointer corrupted");
    sfSound_pause(sound->sound);
}

void nsf_sound_stop(const nsf_sound_t *sound)
{
    if (NSF_UNLIKELY(!sound))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_SOUND, __FUNCTION__,
            "pointer corrupted");
    sfSound_stop(sound->sound);
}
