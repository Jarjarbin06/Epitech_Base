/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/VertexArray.h>

#include "../../includes/newcsfml.h"

void nsf_window_fill(const nsf_window_t *window, const nsf_color_t color[])
{
    if (!window)
        return;
    sfRenderWindow_clear(window->window, *color);
}

static void set_values(sfVertexArray *triangle, const size_t len,
    const nsf_fvector_t vect[], const nsf_color_t *color)
{
    sfVertex *tmp_vect = NULL;

    for (size_t idx = 0; idx < len; idx++) {
        tmp_vect = sfVertexArray_getVertex(triangle, idx);
        if (!tmp_vect)
            return;
        tmp_vect->position = vect[idx];
        tmp_vect->color = *color;
    }
}

int nsf_window_draw_lines(const nsf_window_t *window, const size_t len,
    const nsf_fvector_t points[], const nsf_color_t color[])
{
    sfVertexArray *triangle = sfVertexArray_create();

    if (!triangle)
        return EXIT_ERROR;
    sfVertexArray_setPrimitiveType(triangle, sfLineStrip);
    sfVertexArray_resize(triangle, len);
    set_values(triangle, len, points, color);
    sfRenderWindow_drawVertexArray(window->window, triangle, NULL);
    sfVertexArray_destroy(triangle);
    return EXIT_SUCCESS;
}

void nsf_window_draw(nsf_window_t *window)
{
    if (!window || !window->elements)
        return;
    for (int idx = 0; window->elements[idx]; idx++)
        if (window->elements[idx]->element_type == NSF_BUTTON_ELEMENT)
            nsf_button_draw((nsf_button_t *)(window->elements[idx]->ptr),
                window);
    for (int idx = 0; window->elements[idx]; idx++)
        if (window->elements[idx]->element_type == NSF_SPRITE_ELEMENT)
            nsf_sprite_draw((nsf_sprite_t *)(window->elements[idx]->ptr),
                window);
}
