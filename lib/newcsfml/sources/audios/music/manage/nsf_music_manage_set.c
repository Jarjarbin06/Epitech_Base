/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.10
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

#include <SFML/Audio/Music.h>

#include "newcsfml/audios/music.h"
#include "newcsfml/audios/sound.h"
#include "newcsfml/systems/utils.h"

void nsf_music_set_looping(const nsf_music_t *music, const bool looping)
{
    if (NSF_UNLIKELY(!music))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_MUSIC, __FUNCTION__,
            "pointer corrupted");
    sfMusic_setLoop(music->music, looping);
}

void nsf_music_set_volume(const nsf_music_t *music, const float volume)
{
    if (NSF_UNLIKELY(!music))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_MUSIC, __FUNCTION__,
            "pointer corrupted");
    sfMusic_setVolume(music->music, volume);
}

nsf_sound_status_t nsf_music_get_status(const nsf_music_t *music)
{
    if (NSF_UNLIKELY(!music)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_MUSIC, __FUNCTION__,
            "pointer corrupted");
        return NSF_STT_SND_UNKNOWN;
    }
    return (nsf_sound_status_t)sfMusic_getStatus(music->music);
}
