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

#include "newcsfml/systems/other.h"
#include "newcsfml/graphics/sprite.h"
#include "newcsfml/graphics/button.h"
#include "newcsfml/graphics/text.h"
#include "newcsfml/graphics/particle.h"
#include "newcsfml/audios/sound.h"
#include "newcsfml/games/window.h"
#include "newcsfml/systems/utils.h"

static const void *get_element(const nsf_window_t *window,
    const char name[], const nsf_element_type_t type)
{
    nsf_elements_t *current_element = NULL;

    if (NSF_UNLIKELY(!window || !window->elements.elements || !name))
        return NULL;
    for (size_t idx = 0; idx < window->elements.amount; idx++) {
        current_element = window->elements.elements[idx];
        if (current_element->element_type == type &&
            !str_cmp(current_element->name, name))
            return current_element->ptr;
    }
    return NULL;
}

nsf_sprite_t *nsf_window_get_sprite(const nsf_window_t *window,
    const char sprite_name[])
{
    if (NSF_UNLIKELY(!window || !sprite_name))
        return NULL;
    return (nsf_sprite_t *)get_element(window, sprite_name, NSF_SPRITE_ELEMENT);
}

nsf_button_t *nsf_window_get_button(const nsf_window_t *window,
    const char button_name[])
{
    if (NSF_UNLIKELY(!window || !button_name))
        return NULL;
    return (nsf_button_t *)get_element(window, button_name, NSF_BUTTON_ELEMENT);
}

nsf_sound_t *nsf_window_get_sound(const nsf_window_t *window,
    const char sound_name[])
{
    if (NSF_UNLIKELY(!window || !sound_name))
        return NULL;
    return (nsf_sound_t *)get_element(window, sound_name, NSF_SOUND_ELEMENT);
}

nsf_text_t *nsf_window_get_text(const nsf_window_t *window,
    const char text_name[])
{
    if (NSF_UNLIKELY(!window || !text_name))
        return NULL;
    return (nsf_text_t *)get_element(window, text_name, NSF_TEXT_ELEMENT);
}

nsf_particle_t *nsf_window_get_particle(const nsf_window_t *window,
    const char particle_name[])
{
    if (NSF_UNLIKELY(!window || !particle_name))
        return NULL;
    return (nsf_particle_t *)get_element(window, particle_name,
        NSF_PARTICLE_ELEMENT);
}
