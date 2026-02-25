/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>

#include "../../includes/newcsfml.h"

int nsf_sprite_set_texture(nsf_sprite *sprite, char path[], nsf_game *game)
{
    sfTexture *texture;

    if (!sprite || !path)
        return EXIT_ERROR;
    texture = sfTexture_createFromFile(path, NULL);
    if (!texture)
        return EXIT_ERROR;
    if (game)
        game->allocations++;
    sprite->texture = texture;
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    return EXIT_SUCCESS;
}

int nsf_sprite_draw(nsf_sprite *sprite, nsf_window *window)
{
    if (!sprite || !window)
        return EXIT_ERROR;
    sfRenderWindow_drawSprite(window->window, sprite->sprite, NULL);
    return EXIT_SUCCESS;
}
