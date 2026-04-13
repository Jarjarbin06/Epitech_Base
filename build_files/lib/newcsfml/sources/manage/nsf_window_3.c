/*
** EPITECH PROJECT, 2025
** struct - nsf_window_1.c
** File description:
** <description>
*/

#include <SFML/Graphics/RenderWindow.h>

#include "../../includes/newcsfml.h"

static int get_elements_len(nsf_window_element_t **element)
{
    int idx = 0;

    if (!element)
        return idx;
    for (; element[idx]; idx++);
    return idx;
}

static nsf_window_element_t **append_element(const nsf_window_t *window,
    const nsf_window_element_t element[], nsf_game_t *game)
{
    const nsf_uint_t old_len = get_elements_len(window->elements);
    const nsf_uint_t new_len = old_len + 1;
    nsf_window_element_t **new_elements = nsf_malloc_any(
        sizeof(nsf_window_element_t *) * (new_len + 1), game);
    nsf_window_element_t *new_element = nsf_malloc_any(
        sizeof(nsf_window_element_t), game);

    if (!window->elements || !new_elements || !new_element)
        return NULL;
    new_element->element_type = element->element_type;
    new_element->ptr = element->ptr;
    for (int idx = 0; (nsf_uint_t)idx < old_len; idx++)
        new_elements[idx] = window->elements[idx];
    new_elements[old_len] = new_element;
    new_elements[new_len] = NULL;
    return new_elements;
}

void nsf_window_add_sprite(nsf_window_t *window, nsf_sprite_t *sprite,
    nsf_game_t *game)
{
    nsf_window_element_t **new_elements = NULL;

    if (!window || !window->elements || !sprite)
        return;
    new_elements = append_element(window,
        (nsf_window_element_t[]){{NSF_SPRITE_ELEMENT, (void *)sprite}}, game);
    if (!new_elements)
        return;
    nsf_free_any(window->elements, game);
    window->elements = new_elements;
}

void nsf_window_add_button(nsf_window_t *window, nsf_button_t *button,
    nsf_game_t *game)
{
    nsf_window_element_t **new_elements = NULL;

    if (!window || !window->elements || !button)
        return;
    new_elements = append_element(window,
        (nsf_window_element_t[]){{NSF_BUTTON_ELEMENT, (void *)button}}, game);
    if (!new_elements)
        return;
    nsf_free_any(window->elements, game);
    window->elements = new_elements;
}

void nsf_window_add_sound(nsf_window_t *window, nsf_sound_t *sound,
    nsf_game_t *game)
{
    nsf_window_element_t **new_elements = NULL;

    if (!window || !window->elements || !sound)
        return;
    new_elements = append_element(window,
        (nsf_window_element_t[]){{NSF_SOUND_ELEMENT, (void *)sound}}, game);
    if (!new_elements)
        return;
    nsf_free_any(window->elements, game);
    window->elements = new_elements;
}
