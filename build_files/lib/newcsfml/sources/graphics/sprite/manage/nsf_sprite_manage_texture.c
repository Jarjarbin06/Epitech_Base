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

#include "newcsfml/systems/vector.h"
#include "newcsfml/graphics/animation.h"
#include "newcsfml/graphics/texture.h"
#include "newcsfml/graphics/sprite.h"
#include "newcsfml/systems/utils.h"

void nsf_sprite_set_texture(nsf_sprite_t *sprite, nsf_texture_t *texture)
{
    if (NSF_UNLIKELY(!sprite || !texture))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_SPRITE, __FUNCTION__,
            "pointer corrupted");
    sprite->texture.texture = texture;
    sprite->texture_type = NSF_TXR_TEXTURE;
    sfSprite_setTexture(sprite->sprite, sprite->texture.texture->texture,
        NSF_FALSE);
    nsf_sprite_set_scale(sprite, &sprite->scale);
}

void nsf_sprite_set_animation(nsf_sprite_t *sprite, nsf_animation_t *animation)
{
    if (NSF_UNLIKELY(!sprite || !animation))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_SPRITE, __FUNCTION__,
            "pointer corrupted");
    sprite->texture.animation = animation;
    sprite->texture_type = NSF_TXR_ANIMATION;
    sfSprite_setTexture(sprite->sprite, sprite->texture.animation->texture,
        NSF_FALSE);
    sfSprite_setTextureRect(sprite->sprite, sprite->texture.animation->rect);
}

nsf_texture_t *nsf_sprite_get_texture(const nsf_sprite_t *sprite)
{
    if (NSF_UNLIKELY(!sprite))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_SPRITE, __FUNCTION__,
            "pointer corrupted");
    if (NSF_UNLIKELY(sprite->texture_type != NSF_TXR_TEXTURE))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_SPRITE, __FUNCTION__,
            "invalid texture type");
    return sprite->texture.texture;
}

nsf_animation_t *nsf_sprite_get_animation(const nsf_sprite_t *sprite)
{
    if (NSF_UNLIKELY(!sprite))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_SPRITE, __FUNCTION__,
        "pointer corrupted");
    if (NSF_UNLIKELY(sprite->texture_type != NSF_TXR_ANIMATION))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_SPRITE, __FUNCTION__,
            "invalid texture type");
    return sprite->texture.animation;
}

sfTexture *nsf_sprite_get_deep_texture(const nsf_sprite_t *sprite)
{
    if (NSF_UNLIKELY(!sprite))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_SPRITE, __FUNCTION__,
            "pointer corrupted");
    if (NSF_UNLIKELY(sprite->texture_type == NSF_TXR_TEXTURE))
        return sprite->texture.texture->texture;
    if (NSF_UNLIKELY(sprite->texture_type == NSF_TXR_ANIMATION))
        return sprite->texture.animation->texture;
    return NULL;
}
