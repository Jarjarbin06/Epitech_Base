/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.9
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

#include "newcsfml/games/window.h"
#include "newcsfml/audios/sound.h"
#include "newcsfml/systems/utils.h"

int nsf_window_play_sound(const nsf_window_t *window,
    const char sound_name[])
{
    if (NSF_UNLIKELY(!window || !sound_name))
        return nsf_utils_log_failure(NSF_LOG_LVL_ERROR, NSF_WINDOW,
            __FUNCTION__, "pointer corrupted");
    nsf_sound_play(nsf_window_get_sound(window, sound_name));
    return E_SUCCESS;
}

int nsf_window_pause_sound(const nsf_window_t *window,
    const char sound_name[])
{
    if (NSF_UNLIKELY(!window || !sound_name))
        return nsf_utils_log_failure(NSF_LOG_LVL_ERROR, NSF_WINDOW,
            __FUNCTION__, "pointer corrupted");
    nsf_sound_pause(nsf_window_get_sound(window, sound_name));
    return E_SUCCESS;
}

int nsf_window_stop_sound(const nsf_window_t *window,
    const char sound_name[])
{
    if (NSF_UNLIKELY(!window || !sound_name))
        return nsf_utils_log_failure(NSF_LOG_LVL_ERROR, NSF_WINDOW,
            __FUNCTION__, "pointer corrupted");
    nsf_sound_stop(nsf_window_get_sound(window, sound_name));
    return E_SUCCESS;
}

int nsf_window_all_sound_volume(const nsf_window_t *window,
    const float volume)
{
    if (NSF_UNLIKELY(!window || !window->elements.elements))
        return nsf_utils_log_failure(NSF_LOG_LVL_ERROR, NSF_WINDOW,
            __FUNCTION__, "pointer corrupted");
    for (size_t idx = 0; idx < window->elements.amount; idx++)
        if (window->elements.elements[idx]->element_type == NSF_SPRITE_ELEMENT)
            nsf_sound_set_volume(
                (nsf_sound_t *)window->elements.elements[idx]->ptr, volume);
    return E_SUCCESS;
}

int nsf_window_stop_all_sound(const nsf_window_t *window)
{
    if (NSF_UNLIKELY(!window || !window->elements.elements))
        return nsf_utils_log_failure(NSF_LOG_LVL_ERROR, NSF_WINDOW,
            __FUNCTION__, "pointer corrupted");
    for (size_t idx = 0; idx < window->elements.amount; idx++)
        if (window->elements.elements[idx]->element_type == NSF_SPRITE_ELEMENT)
            nsf_sound_stop((nsf_sound_t *)window->elements.elements[idx]->ptr);
    return E_SUCCESS;
}
