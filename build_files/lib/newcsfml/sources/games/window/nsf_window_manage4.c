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

#include "newcsfml/games/window.h"
#include "newcsfml/audios/sound.h"
#include "newcsfml/systems/utils.h"

static int get_elements_len(nsf_window_elements_t **element)
{
    int idx = 0;

    if (NSF_UNLIKELY(!element))
        return idx;
    for (; element[idx]; idx++);
    return idx;
}

int nsf_window_play_sound(const nsf_window_t *window,
    const char sound_name[])
{
    if (NSF_UNLIKELY(!window || !sound_name))
        return EXIT_ERROR;
    nsf_sound_play(nsf_window_get_sound(window, sound_name));
    return EXIT_SUCCESS;
}

int nsf_window_pause_sound(const nsf_window_t *window,
    const char sound_name[])
{
    if (NSF_UNLIKELY(!window || !sound_name))
        return EXIT_ERROR;
    nsf_sound_pause(nsf_window_get_sound(window, sound_name));
    return EXIT_SUCCESS;
}

int nsf_window_stop_sound(const nsf_window_t *window,
    const char sound_name[])
{
    if (NSF_UNLIKELY(!window || !sound_name))
        return EXIT_ERROR;
    nsf_sound_stop(nsf_window_get_sound(window, sound_name));
    return EXIT_SUCCESS;
}

int nsf_window_all_sound_volume(const nsf_window_t *window,
    const float volume)
{
    if (NSF_UNLIKELY(!window || !window->elements))
        return EXIT_ERROR;
    for (int idx = 0; idx < get_elements_len(window->elements); idx++)
        if (window->elements[idx]->element_type == NSF_SPRITE_ELEMENT)
            nsf_sound_volume((nsf_sound_t *)window->elements[idx]->ptr, volume);
    return EXIT_SUCCESS;
}

int nsf_window_stop_all_sound(const nsf_window_t *window)
{
    if (NSF_UNLIKELY(!window || !window->elements))
        return EXIT_ERROR;
    for (int idx = 0; idx < get_elements_len(window->elements); idx++)
        if (window->elements[idx]->element_type == NSF_SPRITE_ELEMENT)
            nsf_sound_stop((nsf_sound_t *)window->elements[idx]->ptr);
    return EXIT_SUCCESS;
}
