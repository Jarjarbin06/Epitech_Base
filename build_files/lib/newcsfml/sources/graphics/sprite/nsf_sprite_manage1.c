/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.5
** Author: Jarjarbin06
** License: GPL v3
** •
** This library is inspired by SFML/CSFML and is designed for
** educational and game-development purposes.
** •
** It provides higher-level abstractions over CSFML to reduce
** boilerplate code and enforce safer usage patterns.
** •
** WARNING:
** This is NOT the original SFML/CSFML library.
** It is a custom implementation layer built on top of CSFML.
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>

#include "newcsfml/systems/vector.h"
#include "newcsfml/graphics/texture.h"
#include "newcsfml/graphics/sprite.h"
#include "newcsfml/systems/utils.h"

void nsf_sprite_set_texture(nsf_sprite_t *sprite, const nsf_texture_t *texture)
{
    if (NSF_UNLIKELY(!sprite || !texture))
        return;
    sprite->texture = texture;
    sfSprite_setTexture(sprite->sprite, sprite->texture->texture, sfFalse);
}

void nsf_sprite_set_scale(nsf_sprite_t *sprite, const nsf_fvector_t scale[])
{
    if (NSF_UNLIKELY(!sprite || !scale))
        return;
    nsf_fvector_copy(scale, &sprite->scale);
    sfSprite_setScale(sprite->sprite, sprite->scale);
}

void nsf_sprite_set_size(nsf_sprite_t *sprite, const nsf_uvector_t size[])
{
    nsf_uvector_t texture_size = {};
    nsf_fvector_t scale = {};

    if (NSF_UNLIKELY(!sprite || !size || !sprite->texture))
        return;
    texture_size = sfTexture_getSize(sprite->texture->texture);
    scale.x = (float)size->x / (float)texture_size.x;
    scale.y = (float)size->y / (float)texture_size.y;
    nsf_sprite_set_scale(sprite, &scale);
}

void nsf_sprite_set_position(nsf_sprite_t *sprite,
    const nsf_fvector_t position[])
{
    if (NSF_UNLIKELY(!sprite || !position))
        return;
    nsf_fvector_copy(position, &sprite->position);
    sfSprite_setPosition(sprite->sprite, *position);
}

void nsf_sprite_set_origin(nsf_sprite_t *sprite, const nsf_fvector_t origin[])
{
    nsf_uvector_t texture_size = {};
    nsf_fvector_t origin_tmp = {};

    if (NSF_UNLIKELY(!sprite || !origin || !sprite->texture))
        return;
    texture_size = sfTexture_getSize(sprite->texture->texture);
    if (texture_size.x == 0 || texture_size.y == 0)
        return;
    nsf_vector_clamp_x(origin,
        0.0f, (float)texture_size.x, &origin_tmp);
    nsf_vector_clamp_y(&origin_tmp,
        0.0f, (float)texture_size.y, &sprite->origin);
    sfSprite_setOrigin(sprite->sprite, *origin);
}
