/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.8
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

#include "newcsfml/systems/other.h"
#include "newcsfml/audios/sound.h"
#include "newcsfml/games/game.h"
#include "newcsfml/graphics/sprite.h"
#include "newcsfml/graphics/button.h"
#include "newcsfml/graphics/text.h"
#include "newcsfml/graphics/particle.h"
#include "newcsfml/games/window.h"
#include "newcsfml/systems/utils.h"

static void resize_elements(nsf_element_list_t *element, nsf_game_t *game)
{
    nsf_uint_t new_size = 0;
    nsf_elements_t **new_elements = NULL;

    if (NSF_UNLIKELY(!element || !game))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
            "pointer corrupted");
    new_size = element->size * 2;
    new_elements = malloc_any(sizeof(*new_elements) * new_size);
    if (NSF_UNLIKELY(!new_elements))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
            "alloc failed");
    for (size_t i = 0; i < element->amount; i++)
        new_elements[i] = element->elements[i];
    for (size_t i = element->amount; i < new_size; i++)
        new_elements[i] = NULL;
    free_any(element->elements);
    element->elements = new_elements;
    element->size = new_size;
}

static void append_element(nsf_window_t *window,
    const nsf_elements_t element[], nsf_game_t *game)
{
    nsf_elements_t *new_element = malloc_any(
        sizeof(nsf_elements_t));

    if (NSF_UNLIKELY(!window->elements.elements || !new_element || !game))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
            "pointer corrupted");
    *new_element = (nsf_elements_t){element->element_type, element->ptr,
        str_dup(element->name)};
    if (window->elements.amount >= window->elements.size)
        resize_elements(&window->elements, game);
    window->elements.elements[window->elements.amount] = new_element;
    window->elements.amount++;
    if (game)
        game->allocations++;
}

void nsf_window_add_sprite(nsf_window_t *window, const nsf_sprite_t *sprite,
    nsf_game_t *game)
{
    if (NSF_UNLIKELY(!window || !window->elements.elements || !sprite))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
            "pointer corrupted");
    append_element(window, (nsf_elements_t[])
        {{NSF_SPRITE_ELEMENT, (void *)sprite, sprite->name}}, game);
    if (game)
        game->allocations--;
}

void nsf_window_add_button(nsf_window_t *window, const nsf_button_t *button,
    nsf_game_t *game)
{
    if (NSF_UNLIKELY(!window || !window->elements.elements || !button))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
            "pointer corrupted");
    append_element(window, (nsf_elements_t[])
        {{NSF_BUTTON_ELEMENT, (void *)button, button->name}}, game);
    if (game)
        game->allocations--;
}

void nsf_window_add_sound(nsf_window_t *window, const nsf_sound_t *sound,
    nsf_game_t *game)
{
    if (NSF_UNLIKELY(!window || !window->elements.elements || !sound))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
            "pointer corrupted");
    append_element(window, (nsf_elements_t[])
        {{NSF_SOUND_ELEMENT, (void *)sound, sound->name}}, game);
    if (game)
        game->allocations--;
}

void nsf_window_add_text(nsf_window_t *window, const nsf_text_t *text,
    nsf_game_t *game)
{
    if (NSF_UNLIKELY(!window || !window->elements.elements || !text))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
            "pointer corrupted");
    append_element(window, (nsf_elements_t[])
        {{NSF_TEXT_ELEMENT, (void *)text, text->name}}, game);
    if (game)
        game->allocations--;
}

void nsf_window_add_particle(nsf_window_t *window,
    const nsf_particle_t *particle, nsf_game_t *game)
{
    if (NSF_UNLIKELY(!window || !window->elements.elements || !particle))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
            "pointer corrupted");
    append_element(window, (nsf_elements_t[])
        {{NSF_PARTICLE_ELEMENT, (void *)particle, particle->name}}, game);
    if (game)
        game->allocations--;
}
