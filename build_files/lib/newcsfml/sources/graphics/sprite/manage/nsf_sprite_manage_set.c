/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.7
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

#include "newcsfml/graphics/animation.h"
#include "newcsfml/systems/vector.h"
#include "newcsfml/graphics/texture.h"
#include "newcsfml/graphics/sprite.h"
#include "newcsfml/systems/utils.h"

void nsf_sprite_set_scale(nsf_sprite_t *sprite, const nsf_fvector_t scale[])
{
    if (NSF_UNLIKELY(!sprite || !scale))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_SPRITE, __FUNCTION__,
            "pointer corrupted");
    nsf_fvector_copy(scale, &sprite->scale);
    sfSprite_setScale(sprite->sprite, sprite->scale);
}

void nsf_sprite_set_size(nsf_sprite_t *sprite, const nsf_uvector_t size[])
{
    nsf_uvector_t texture_size = {0, 0};
    nsf_fvector_t scale = {0, 0};

    if (NSF_UNLIKELY(!sprite || !size))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_SPRITE, __FUNCTION__,
            "pointer corrupted");
    if (sprite->texture_type == NSF_TXR_TEXTURE)
        texture_size = sfTexture_getSize(nsf_sprite_get_deep_texture(sprite));
    if (sprite->texture_type == NSF_TXR_ANIMATION)
        nsf_uvector_copy(&nsf_sprite_get_animation(sprite)->sprite_size,
            &texture_size);
    scale.x = (float)size->x / (float)texture_size.x;
    scale.y = (float)size->y / (float)texture_size.y;
    nsf_sprite_set_scale(sprite, &scale);
}

void nsf_sprite_set_position(nsf_sprite_t *sprite,
    const nsf_fvector_t position[])
{
    if (NSF_UNLIKELY(!sprite || !position))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_SPRITE, __FUNCTION__,
            "pointer corrupted");
    nsf_fvector_copy(position, &sprite->position);
    sfSprite_setPosition(sprite->sprite, *position);
}

void nsf_sprite_set_origin(nsf_sprite_t *sprite, const nsf_fvector_t origin[])
{
    nsf_uvector_t texture_size = {0, 0};
    nsf_fvector_t origin_tmp = {0, 0};

    if (NSF_UNLIKELY(!sprite || !origin))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_SPRITE, __FUNCTION__,
            "pointer corrupted");
    texture_size = sfTexture_getSize(nsf_sprite_get_deep_texture(sprite));
    if (texture_size.x == 0 || texture_size.y == 0)
        return nsf_utils_log(NSF_LOG_LVL_WARNING, NSF_SPRITE, __FUNCTION__,
            "pointer corrupted");
    nsf_vector_clamp_x(origin,
        0.0f, (float)texture_size.x, &origin_tmp);
    nsf_vector_clamp_y(&origin_tmp,
        0.0f, (float)texture_size.y, &sprite->origin);
    sfSprite_setOrigin(sprite->sprite, sprite->origin);
}
