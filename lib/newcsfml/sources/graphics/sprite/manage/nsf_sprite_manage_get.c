/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.9
** Author: Jarjarbin06
** Licence: GPL v3
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

nsf_fvector_t nsf_sprite_get_scale(const nsf_sprite_t *sprite)
{
    if (NSF_UNLIKELY(!sprite)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_SPRITE, __FUNCTION__,
            "pointer corrupted");
        return nsf_fvector_empty();
    }
    return nsf_fvector_copy(&sprite->scale);
}

nsf_uvector_t nsf_sprite_get_size(const nsf_sprite_t *sprite)
{
    if (NSF_UNLIKELY(!sprite)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_SPRITE, __FUNCTION__,
            "pointer corrupted");
        return nsf_uvector_empty();
    }
    return nsf_uvector_copy(
        U_TO_PTR(sfTexture_getSize(nsf_sprite_get_deep_texture(sprite))));
}

nsf_fvector_t nsf_sprite_get_position(const nsf_sprite_t *sprite)
{
    if (NSF_UNLIKELY(!sprite)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_SPRITE, __FUNCTION__,
            "pointer corrupted");
        return nsf_fvector_empty();
    }
    return nsf_fvector_copy(&sprite->position);
}

nsf_fvector_t nsf_sprite_get_origin(const nsf_sprite_t *sprite)
{
    if (NSF_UNLIKELY(!sprite)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_SPRITE, __FUNCTION__,
            "pointer corrupted");
        return nsf_fvector_empty();
    }
    return nsf_fvector_copy(&sprite->origin);
}

void *nsf_sprite_get_data(nsf_sprite_t *sprite)
{
    if (NSF_UNLIKELY(!sprite))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_SPRITE, __FUNCTION__,
            "pointer corrupted");
    return sprite->data;
}