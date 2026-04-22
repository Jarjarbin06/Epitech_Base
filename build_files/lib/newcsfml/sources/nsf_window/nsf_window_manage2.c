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

nsf_sprite_t *nsf_window_get_sprite(nsf_window_t *window,
    const char sprite_name[])
{
    if (!window || !window->elements || !sprite_name)
        return NULL;
    for (int idx = 0; idx < get_elements_len(window->elements); idx++)
        if (window->elements[idx]->element_type == NSF_SPRITE_ELEMENT &&
            !str_strcmp(((nsf_sprite_t *)window->elements[idx]->ptr)->name,
                sprite_name))
            return (nsf_sprite_t *)window->elements[idx]->ptr;
    return NULL;
}

nsf_button_t *nsf_window_get_button(nsf_window_t *window,
    const char button_name[])
{
    if (!window || !window->elements || !button_name)
        return NULL;
    for (int idx = 0; idx < get_elements_len(window->elements); idx++)
        if (window->elements[idx]->element_type == NSF_BUTTON_ELEMENT &&
            !str_strcmp(((nsf_button_t *)window->elements[idx]->ptr)->name,
                button_name))
            return (nsf_button_t *)window->elements[idx]->ptr;
    return NULL;
}

nsf_sound_t *nsf_window_get_sound(nsf_window_t *window,
    const char sound_name[])
{
    if (!window || !window->elements || !sound_name)
        return NULL;
    for (int idx = 0; idx < get_elements_len(window->elements); idx++)
        if (window->elements[idx]->element_type == NSF_SOUND_ELEMENT &&
            !str_strcmp(((nsf_sound_t *)window->elements[idx]->ptr)->name,
                sound_name))
            return (nsf_sound_t *)window->elements[idx]->ptr;
    return NULL;
}
