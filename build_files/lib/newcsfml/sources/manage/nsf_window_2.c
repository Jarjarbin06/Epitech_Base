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
    const nsf_uint old_len = get_elements_len(window->elements);
    const nsf_uint new_len = old_len + 1;
    nsf_window_element_t **new_elements = nsf_malloc_any(
        sizeof(nsf_window_element_t *) * (new_len + 1), game);
    nsf_window_element_t *new_element = nsf_malloc_any(
        sizeof(nsf_window_element_t), game);

    if (!window->elements || !new_elements || !new_element)
        return NULL;
    new_element->element_type = element->element_type;
    new_element->ptr = element->ptr;
    for (int idx = 0; (nsf_uint)idx < old_len; idx++)
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
        (nsf_window_element_t[]){{SPRITE_ELEMENT, (void *)sprite}}, game);
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
        (nsf_window_element_t[]){{BUTTON_ELEMENT, (void *)button}}, game);
    if (!new_elements)
        return;
    nsf_free_any(window->elements, game);
    window->elements = new_elements;
}

nsf_sprite_t *nsf_window_get_sprite(nsf_window_t *window,
    const char sprite_name[])
{
    if (!window || !window->elements || !sprite_name)
        return NULL;
    for (int idx = 0; idx < get_elements_len(window->elements); idx++)
        if (!(window->elements[idx]->element_type == SPRITE_ELEMENT &&
            str_strcmp(((nsf_sprite_t *)window->elements[idx]->ptr)->name,
                sprite_name)))
            return (nsf_sprite_t *)window->elements[idx]->ptr;
    return NULL;
}

nsf_button_t *nsf_window_get_button(nsf_window_t *window,
    const char button_name[])
{
    if (!window || !window->elements || !button_name)
        return NULL;
    for (int idx = 0; idx < get_elements_len(window->elements); idx++)
        if (!(window->elements[idx]->element_type == BUTTON_ELEMENT &&
            str_strcmp(((nsf_button_t *)window->elements[idx]->ptr)->name,
                button_name)))
            return (nsf_button_t *)window->elements[idx]->ptr;
    return NULL;
}
