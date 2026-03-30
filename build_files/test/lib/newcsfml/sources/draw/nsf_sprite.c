/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include <SFML/Graphics/RenderWindow.h>

#include "newcsfml.h"

void nsf_sprite_draw(nsf_sprite_t *sprite, nsf_window_t *window)
{
    if (!sprite || !window)
        return;
    sfRenderWindow_drawSprite(window->window, sprite->sprite, NULL);
}
