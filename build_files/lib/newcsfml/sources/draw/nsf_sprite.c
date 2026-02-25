/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include <SFML/Graphics/RenderWindow.h>

#include "../../includes/newcsfml.h"

int nsf_sprite_draw(nsf_sprite *sprite, nsf_window *window)
{
    if (!sprite || !window)
        return EXIT_ERROR;
    sfRenderWindow_drawSprite(window->window, sprite->sprite, NULL);
    return EXIT_SUCCESS;
}
