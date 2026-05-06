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

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/VertexArray.h>

#include "newcsfml/games/window.h"
#include "newcsfml/graphics/background.h"
#include "newcsfml/graphics/button.h"
#include "newcsfml/graphics/text.h"
#include "newcsfml/graphics/sprite.h"
#include "newcsfml/systems/utils.h"

void nsf_window_fill(const nsf_window_t *window, const nsf_color_t color[])
{
    if (NSF_UNLIKELY(!window))
        return;
    sfRenderWindow_clear(window->window, *color);
}

static void set_values(sfVertexArray *vertex, const size_t len,
    const nsf_fvector_t vect[], const nsf_color_t color[])
{
    sfVertex *tmp_vect = NULL;

    for (size_t idx = 0; idx < len; idx++) {
        tmp_vect = sfVertexArray_getVertex(vertex, idx);
        if (NSF_UNLIKELY(!tmp_vect))
            return;
        tmp_vect->position = vect[idx];
        tmp_vect->color = color[idx];
    }
}

static sfVertexArray *get_vertices(const sfPrimitiveType type, const size_t len,
    const nsf_fvector_t lines[], const nsf_color_t color[])
{
    sfVertexArray *array = NULL;

    if (NSF_UNLIKELY(!lines || !color))
        return NULL;
    array = sfVertexArray_create();
    if (NSF_UNLIKELY(!array))
        return NULL;
    sfVertexArray_setPrimitiveType(array, type);
    sfVertexArray_resize(array, len);
    set_values(array, len, lines, color);
    return array;
}

int nsf_window_draw_lines(const nsf_window_t *window, const size_t len,
    const nsf_fvector_t lines[], const nsf_color_t color[])
{
    sfVertexArray *array = NULL;

    if (NSF_UNLIKELY(!window || !window->window || !lines || !color))
        return EXIT_ERROR;
    array = get_vertices(sfLineStrip, len, lines, color);
    if (NSF_UNLIKELY(!array))
        return EXIT_ERROR;
    sfRenderWindow_drawVertexArray(window->window, array, NULL);
    sfVertexArray_destroy(array);
    return EXIT_SUCCESS;
}

int nsf_window_draw_points(const nsf_window_t *window, const size_t len,
    const nsf_fvector_t points[], const nsf_color_t color[])
{
    sfVertexArray *array = NULL;

    if (NSF_UNLIKELY(!window || !window->window || !points || !color))
        return EXIT_ERROR;
    array = get_vertices(sfPoints, len, points, color);
    if (NSF_UNLIKELY(!array))
        return EXIT_ERROR;
    sfRenderWindow_drawVertexArray(window->window, array, NULL);
    sfVertexArray_destroy(array);
    return EXIT_SUCCESS;
}

void nsf_window_draw(const nsf_window_t *window)
{
    if (NSF_UNLIKELY(!window || !window->elements.elements ||
        !window->background))
        return;
    nsf_background_draw(window->background, window);
    for (size_t idx = 0; idx < window->elements.amount; idx++)
        if (window->elements.elements[idx]->element_type == NSF_SPRITE_ELEMENT)
            nsf_sprite_draw((nsf_sprite_t *)(
                window->elements.elements[idx]->ptr), window);
    for (size_t idx = 0; window->elements.elements[idx]; idx++)
        if (window->elements.elements[idx]->element_type == NSF_BUTTON_ELEMENT)
            nsf_button_draw((nsf_button_t *)(
                window->elements.elements[idx]->ptr), window);
    for (size_t idx = 0; window->elements.elements[idx]; idx++)
        if (window->elements.elements[idx]->element_type == NSF_TEXT_ELEMENT)
            nsf_text_draw((nsf_text_t *)(
                window->elements.elements[idx]->ptr), window);
}
