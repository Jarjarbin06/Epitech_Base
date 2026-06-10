/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.10
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
#include "newcsfml/systems/utils.h"

static void set_values(sfVertexArray *vertex, const size_t len,
    const nsf_fvector_t vect[], const nsf_color_t color[])
{
    sfVertex *tmp_vect = NULL;

    if (NSF_UNLIKELY(!vertex || !vect || !color))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
            "pointer corrupted");
    for (size_t idx = 0; idx < len; idx++) {
        tmp_vect = sfVertexArray_getVertex(vertex, idx);
        if (NSF_UNLIKELY(!tmp_vect))
            return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
                "vertex retrieval failed");
        tmp_vect->position = vect[idx];
        tmp_vect->color = color[idx];
    }
}

static sfVertexArray *get_vertices(const sfPrimitiveType type, const size_t len,
    const nsf_fvector_t lines[], const nsf_color_t color[])
{
    sfVertexArray *array = NULL;

    if (NSF_UNLIKELY(!lines || !color))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
            "pointer corrupted");
    array = sfVertexArray_create();
    if (NSF_UNLIKELY(!array))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
            "alloc failed");
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
        return nsf_utils_log_failure(NSF_LOG_LVL_ERROR, NSF_WINDOW,
            __FUNCTION__, "pointer corrupted");
    array = get_vertices(sfLineStrip, len, lines, color);
    if (NSF_UNLIKELY(!array))
        return nsf_utils_log_failure(NSF_LOG_LVL_ERROR, NSF_WINDOW,
            __FUNCTION__, "array retrieval failed");
    sfRenderWindow_drawVertexArray(window->window, array, NULL);
    sfVertexArray_destroy(array);
    return E_SUCCESS;
}

int nsf_window_draw_points(const nsf_window_t *window, const size_t len,
    const nsf_fvector_t points[], const nsf_color_t color[])
{
    sfVertexArray *array = NULL;

    if (NSF_UNLIKELY(!window || !window->window || !points || !color))
        return nsf_utils_log_failure(NSF_LOG_LVL_ERROR, NSF_WINDOW,
            __FUNCTION__, "pointer corrupted");
    array = get_vertices(sfPoints, len, points, color);
    if (NSF_UNLIKELY(!array))
        return nsf_utils_log_failure(NSF_LOG_LVL_ERROR, NSF_WINDOW,
            __FUNCTION__, "array retrieval failed");
    sfRenderWindow_drawVertexArray(window->window, array, NULL);
    sfVertexArray_destroy(array);
    return E_SUCCESS;
}
