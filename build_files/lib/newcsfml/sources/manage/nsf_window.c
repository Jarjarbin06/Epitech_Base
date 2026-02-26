/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include <SFML/Graphics/RenderWindow.h>

#include "../../includes/newcsfml.h"

int nsf_window_display(nsf_window_t *nsf_window)
{
    if (!nsf_window)
        return EXIT_ERROR;
    sfRenderWindow_display(nsf_window->window);
    return EXIT_SUCCESS;
}

bool nsf_window_isopen(nsf_window_t *nsf_window)
{
    if (!nsf_window)
        return false;
    return (bool)sfRenderWindow_isOpen(nsf_window->window);
}

void nsf_window_close(nsf_window_t *nsf_window)
{
    if (!nsf_window)
        return;
    sfRenderWindow_close(nsf_window->window);
}

bool nsf_window_get_event(nsf_window_t *nsf_window, nsf_event *event)
{
    if (!nsf_window || !event)
        return false;
    return (bool)sfRenderWindow_pollEvent(nsf_window->window, event);
}
