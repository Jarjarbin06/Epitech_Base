/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.4
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

#include <SFML/Graphics/Texture.h>

#include "newcsfml/systems/vector.h"
#include "newcsfml/graphics/texture.h"
#include "newcsfml/graphics/sprite.h"
#include "newcsfml/systems/utils.h"

const nsf_texture_t *nsf_sprite_get_texture(const nsf_sprite_t *sprite)
{
    if (NSF_UNLIKELY(!sprite))
        return NULL;
    return sprite->texture;
}

void nsf_sprite_get_scale(const nsf_sprite_t *sprite, nsf_fvector_t *out)
{
    if (NSF_UNLIKELY(!sprite))
        return nsf_fvector_empty(out);
    nsf_fvector_copy(&sprite->scale, out);
}

void nsf_sprite_get_size(const nsf_sprite_t *sprite, nsf_uvector_t *out)
{
    if (NSF_UNLIKELY(!sprite || !sprite->texture))
        return nsf_uvector_empty(out);
    nsf_uvector_copy((nsf_uvector_t[]){sfTexture_getSize
            (sprite->texture->texture)}, out);
}

void nsf_sprite_get_position(const nsf_sprite_t *sprite, nsf_fvector_t *out)
{
    if (NSF_UNLIKELY(!sprite))
        return nsf_fvector_empty(out);
    nsf_fvector_copy(&sprite->position, out);
}

void nsf_sprite_get_origin(const nsf_sprite_t *sprite, nsf_fvector_t *out)
{
    if (NSF_UNLIKELY(!sprite))
        return nsf_fvector_empty(out);
    nsf_fvector_copy(&sprite->origin, out);
}
