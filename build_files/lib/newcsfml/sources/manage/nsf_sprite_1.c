/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>

#include "../../includes/newcsfml.h"

void nsf_sprite_set_texture(nsf_sprite_t *sprite, nsf_texture_t *texture)
{
    nsf_uvector_t texture_size = {0, 0};

    if (!sprite || !texture)
        return;
    sprite->texture = texture;
    sfSprite_setTexture(sprite->sprite, sprite->texture->texture, sfFalse);
    texture_size = sfTexture_getSize(texture->texture);
    nsf_sprite_set_size(sprite, &texture_size);
}

void nsf_sprite_set_scale(nsf_sprite_t *sprite, nsf_fvector_t scale[])
{
    if (!sprite || !scale)
        return;
    sprite->scale.x = scale->x;
    sprite->scale.y = scale->y;
    sfSprite_setScale(sprite->sprite, *scale);
}

void nsf_sprite_set_size(nsf_sprite_t *sprite, nsf_uvector_t size[])
{
    nsf_uvector_t texture_size = {0, 0};
    nsf_fvector_t scale = {1.0f, 1.0f};

    if (!sprite || !size || !sprite->texture)
        return;
    texture_size = sfTexture_getSize(sprite->texture->texture);
    scale.x = size->x / (float)texture_size.x;
    scale.y = size->y / (float)texture_size.y;
    nsf_sprite_set_scale(sprite, &scale);
}

void nsf_sprite_set_position(nsf_sprite_t *sprite, nsf_fvector_t position[])
{
    if (!sprite || !position)
        return;
    sprite->position.x = position->x;
    sprite->position.y = position->y;
    sfSprite_setPosition(sprite->sprite, *position);
}

void nsf_sprite_set_origin(nsf_sprite_t *sprite, nsf_fvector_t origin[])
{
    sfVector2u texture_size = {0, 0};

    if (!sprite || !origin || !sprite->texture)
        return;
    texture_size = sfTexture_getSize(sprite->texture->texture);
    if (texture_size.x == 0 || texture_size.y == 0)
        return;
    if (origin->x < 0)
        origin->x = 0;
    if (origin->x > (float)texture_size.x)
        origin->x = (float)texture_size.x;
    if (origin->y < 0)
        origin->y = 0;
    if (origin->y > (float)texture_size.y)
        origin->y = (float)texture_size.y;
    sprite->origin.x = origin->x;
    sprite->origin.y = origin->y;
    sfSprite_setOrigin(sprite->sprite, *origin);
}
