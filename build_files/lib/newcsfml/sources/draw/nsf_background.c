/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include <SFML/Graphics/RenderWindow.h>

#include "../../includes/newcsfml.h"

void nsf_background_draw(nsf_background_t *background, nsf_window_t *window)
{
    if (!background || !window)
        return;
    nsf_sprite_draw(background->sprite, window);
}
