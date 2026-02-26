/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include <SFML/Graphics/RenderWindow.h>

#include "../../includes/newcsfml.h"

int nsf_sprite_set_texture(nsf_sprite_t *sprite, nsf_texture_t *texture)
{
    if (!sprite || !texture)
        return EXIT_ERROR;
    sprite->texture = texture;
    sfSprite_setTexture(sprite->sprite, sprite->texture->texture, sfFalse);
    return EXIT_SUCCESS;
}
