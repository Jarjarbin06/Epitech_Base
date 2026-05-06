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

#include "newcsfml/systems/other.h"
#include "newcsfml/graphics/sprite.h"
#include "newcsfml/graphics/button.h"
#include "newcsfml/graphics/text.h"
#include "newcsfml/audios/sound.h"
#include "newcsfml/games/window.h"
#include "newcsfml/systems/utils.h"

nsf_sprite_t *nsf_window_get_sprite(const nsf_window_t *window,
    const char sprite_name[])
{
    if (NSF_UNLIKELY(!window || !window->elements.elements || !sprite_name))
        return NULL;
    for (size_t idx = 0; idx < window->elements.amount; idx++)
        if (window->elements.elements[idx]->element_type == NSF_SPRITE_ELEMENT &&
            !str_cmp(((nsf_sprite_t *)window->elements.elements[idx]->ptr)->name,
                sprite_name))
            return (nsf_sprite_t *)window->elements.elements[idx]->ptr;
    return NULL;
}

nsf_button_t *nsf_window_get_button(const nsf_window_t *window,
    const char button_name[])
{
    if (NSF_UNLIKELY(!window || !window->elements.elements || !button_name))
        return NULL;
    for (size_t idx = 0; idx < window->elements.amount; idx++)
        if (window->elements.elements[idx]->element_type == NSF_BUTTON_ELEMENT &&
            !str_cmp(((nsf_button_t *)window->elements.elements[idx]->ptr)->name,
                button_name))
            return (nsf_button_t *)window->elements.elements[idx]->ptr;
    return NULL;
}

nsf_sound_t *nsf_window_get_sound(const nsf_window_t *window,
    const char sound_name[])
{
    if (NSF_UNLIKELY(!window || !window->elements.elements || !sound_name))
        return NULL;
    for (size_t idx = 0; idx < window->elements.amount; idx++)
        if (window->elements.elements[idx]->element_type == NSF_SOUND_ELEMENT &&
            !str_cmp(((nsf_sound_t *)window->elements.elements[idx]->ptr)->name,
                sound_name))
            return (nsf_sound_t *)window->elements.elements[idx]->ptr;
    return NULL;
}

nsf_text_t *nsf_window_get_text(const nsf_window_t *window,
    const char text_name[])
{
    if (NSF_UNLIKELY(!window || !window->elements.elements || !text_name))
        return NULL;
    for (size_t idx = 0; idx < window->elements.amount; idx++)
        if (window->elements.elements[idx]->element_type == NSF_TEXT_ELEMENT &&
            !str_cmp(((nsf_text_t *)window->elements.elements[idx]->ptr)->name,
                text_name))
            return (nsf_text_t *)window->elements.elements[idx]->ptr;
    return NULL;
}
