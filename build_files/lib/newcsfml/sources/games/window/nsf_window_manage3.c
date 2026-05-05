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
#include "newcsfml/audios/sound.h"
#include "newcsfml/games/game.h"
#include "newcsfml/games/window.h"
#include "newcsfml/systems/utils.h"

static int get_elements_len(nsf_window_elements_t **element)
{
    int idx = 0;

    if (NSF_UNLIKELY(!element))
        return idx;
    for (; element[idx]; idx++);
    return idx;
}

static nsf_window_elements_t **append_element(const nsf_window_t *window,
    const nsf_window_elements_t element[], nsf_game_t *game)
{
    const nsf_uint_t old_len = get_elements_len(window->elements);
    const nsf_uint_t new_len = old_len + 1;
    nsf_window_elements_t **new_elements = malloc_any(
        sizeof(nsf_window_elements_t *) * (new_len + 1));
    nsf_window_elements_t *new_element = malloc_any(
        sizeof(nsf_window_elements_t));

    if (NSF_UNLIKELY(!window->elements || !new_elements || !new_element))
        return NULL;
    new_element->element_type = element->element_type;
    new_element->ptr = element->ptr;
    for (int idx = 0; (nsf_uint_t)idx < old_len; idx++)
        new_elements[idx] = window->elements[idx];
    new_elements[old_len] = new_element;
    new_elements[new_len] = NULL;
    if (game)
        game->allocations += 2;
    return new_elements;
}

void nsf_window_add_sprite(nsf_window_t *window, const nsf_sprite_t *sprite,
    nsf_game_t *game)
{
    nsf_window_elements_t **new_elements = NULL;

    if (NSF_UNLIKELY(!window || !window->elements || !sprite))
        return;
    new_elements = append_element(window,
        (nsf_window_elements_t[]){{NSF_SPRITE_ELEMENT, (void *)sprite}}, game);
    if (NSF_UNLIKELY(!new_elements))
        return;
    free_any(window->elements);
    window->elements = new_elements;
    if (game)
        game->allocations--;
}

void nsf_window_add_button(nsf_window_t *window, const nsf_button_t *button,
    nsf_game_t *game)
{
    nsf_window_elements_t **new_elements = NULL;

    if (NSF_UNLIKELY(!window || !window->elements || !button))
        return;
    new_elements = append_element(window,
        (nsf_window_elements_t[]){{NSF_BUTTON_ELEMENT, (void *)button}}, game);
    if (NSF_UNLIKELY(!new_elements))
        return;
    free_any(window->elements);
    window->elements = new_elements;
    if (game)
        game->allocations--;
}

void nsf_window_add_sound(nsf_window_t *window, const nsf_sound_t *sound,
    nsf_game_t *game)
{
    nsf_window_elements_t **new_elements = NULL;

    if (NSF_UNLIKELY(!window || !window->elements || !sound))
        return;
    new_elements = append_element(window,
        (nsf_window_elements_t[]){{NSF_SOUND_ELEMENT, (void *)sound}}, game);
    if (NSF_UNLIKELY(!new_elements))
        return;
    free_any(window->elements);
    window->elements = new_elements;
    if (game)
        game->allocations--;
}

void nsf_window_add_text(nsf_window_t *window, const nsf_text_t *text,
    nsf_game_t *game)
{
    nsf_window_elements_t **new_elements = NULL;

    if (NSF_UNLIKELY(!window || !window->elements || !text))
        return;
    new_elements = append_element(window,
        (nsf_window_elements_t[]){{NSF_TEXT_ELEMENT, (void *)text}}, game);
    if (NSF_UNLIKELY(!new_elements))
        return;
    free_any(window->elements);
    window->elements = new_elements;
    if (game)
        game->allocations--;
}
