/*
** EPITECH PROJECT, 2025
** struct - nsf_window_1.c
** File description:
** <description>
*/

#include <SFML/Graphics/RenderWindow.h>

#include "../../includes/newcsfml.h"

int nsf_window_update_settings(nsf_window_t *window)
{
    sfVector2u size = {};
    if (!window || !window->window || !window->settings)
        return EXIT_ERROR;
    size = sfRenderWindow_getSize(window->window);
    window->settings->width = size.x;
    window->settings->height = size.y;
    return EXIT_SUCCESS;
}

void nsf_window_get_mouse(nsf_window_t *window, nsf_ivector_t vect[])
{
    if (!window || !vect)
        return;
    *vect = sfMouse_getPositionRenderWindow(window->window);
}
