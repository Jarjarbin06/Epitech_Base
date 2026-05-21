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

#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>

#include "newcsfml/games/game.h"
#include "newcsfml/systems/utils.h"
#include "newcsfml/systems/other.h"
#include "newcsfml/audios/sound.h"

nsf_sound_t *nsf_sound_create(const char path[], const char name[],
    nsf_game_t *game)
{
    nsf_sound_t *new_sound = malloc_any(sizeof(nsf_sound_t));
    sfSoundBuffer *sf_sound_buffer = sfSoundBuffer_createFromFile(path);
    sfSound *sf_sound = sfSound_create();
    const nsf_cstr_t name_str = str_dup((const char *const)name);

    if (NSF_UNLIKELY(!new_sound || !sf_sound || !sf_sound_buffer || !name_str))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_SOUND, __FUNCTION__,
            "alloc failed");
    sfSound_setBuffer(sf_sound, sf_sound_buffer);
    new_sound->sound = sf_sound;
    new_sound->buffer = sf_sound_buffer;
    new_sound->name = name_str;
    if (game)
        game->allocations += 4;
    return new_sound;
}

int nsf_sound_destroy(nsf_sound_t **sound, nsf_game_t *game)
{
    if (NSF_UNLIKELY(!sound || !*sound))
        return nsf_utils_log_error(NSF_LOG_LVL_ERROR, NSF_SOUND, __FUNCTION__,
            "pointer corrupted");
    if (NSF_LIKELY((*sound)->sound))
        sfSound_destroy((*sound)->sound);
    if (NSF_LIKELY((*sound)->buffer))
        sfSoundBuffer_destroy((*sound)->buffer);
    if (NSF_LIKELY((*sound)->name))
        free_any((nsf_str_t)(*sound)->name);
    *sound = free_any(*sound);
    if (game)
        game->allocations -= 4;
    return E_SUCCESS;
}
