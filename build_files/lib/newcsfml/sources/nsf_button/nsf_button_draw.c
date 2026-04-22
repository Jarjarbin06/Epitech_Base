/*
** EPITECH PROJECT, 2025
** struct - nsf_sprite.c
** File description:
** <description>
*/

#include <SFML/Graphics/RenderWindow.h>

#include "../../includes/newcsfml.h"

void nsf_button_draw(nsf_button_t *button, nsf_window_t *window)
{
    if (!button || !window)
        return;
    sfRenderWindow_drawRectangleShape(window->window, button->button, NULL);
}
