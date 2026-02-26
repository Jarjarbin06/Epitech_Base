/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/VertexArray.h>

#include "../../includes/newcsfml.h"

void nsf_window_fill(const nsf_window_t *window, const nsf_color color)
{
    sfRenderWindow_clear(window->window, color);
}

void nsf_window_draw_line(const nsf_window_t *window,
    const nsf_vector a, const nsf_vector b, nsf_color color)
{
    sfVertexArray *line = sfVertexArray_create();
    const sfVertex vertex1 = {(sfVector2f)a, (sfColor)color};
    const sfVertex vertex2 = {(sfVector2f)b, (sfColor)color};

    if (!line || !window)
        return;
    sfVertexArray_setPrimitiveType(line, sfLines);
    sfVertexArray_append(line, vertex1);
    sfVertexArray_append(line, vertex2);
    sfRenderWindow_drawVertexArray(window->window, line, NULL);
    sfVertexArray_destroy(line);
}
