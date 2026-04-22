/*
** EPITECH PROJECT, 2025
** struct - nsf_window_manage1.c
** File description:
** <description>
*/

#include <SFML/Graphics/RenderWindow.h>

#include "../../includes/newcsfml.h"

int nsf_window_display(nsf_window_t *window)
{
    if (!window)
        return EXIT_ERROR;
    sfRenderWindow_display(window->window);
    return EXIT_SUCCESS;
}

bool nsf_window_isopen(nsf_window_t *window)
{
    if (!window)
        return false;
    return (bool)sfRenderWindow_isOpen(window->window);
}

void nsf_window_close(nsf_window_t *window)
{
    if (!window)
        return;
    sfRenderWindow_close(window->window);
}

bool nsf_window_get_event(nsf_window_t *window, nsf_event_t *event)
{
    if (!window || !event)
        return false;
    return (bool)sfRenderWindow_pollEvent(window->window, event);
}
