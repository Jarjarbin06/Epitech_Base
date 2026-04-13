/*
** EPITECH PROJECT, 2025
** struct - nsf_window_1.c
** File description:
** <description>
*/

#include "../../includes/newcsfml.h"

static int get_elements_len(nsf_window_element_t **element)
{
    int idx = 0;

    if (!element)
        return idx;
    for (; element[idx]; idx++);
    return idx;
}

int nsf_window_all_sound_volume(nsf_window_t *window,
    const float volume)
{
    if (!window || !window->elements)
        return EXIT_ERROR;
    for (int idx = 0; idx < get_elements_len(window->elements); idx++)
        if (window->elements[idx]->element_type == NSF_SPRITE_ELEMENT)
            nsf_sound_volume((nsf_sound_t *)window->elements[idx]->ptr, volume);
    return EXIT_SUCCESS;
}

int nsf_window_stop_all_sound(nsf_window_t *window)
{
    if (!window || !window->elements)
        return EXIT_ERROR;
    for (int idx = 0; idx < get_elements_len(window->elements); idx++)
        if (window->elements[idx]->element_type == NSF_SPRITE_ELEMENT)
            nsf_sound_stop((nsf_sound_t *)window->elements[idx]->ptr);
    return EXIT_SUCCESS;
}
