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

#include "newcsfml/graphics/animation.h"
#include "newcsfml/systems/other.h"
#include "newcsfml/systems/utils.h"

void nsf_animation_update(nsf_animation_t *animation)
{
    if (NSF_UNLIKELY(!animation))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_ANIMATION,
            __FUNCTION__, "pointer corrupted");
    if (NSF_UNLIKELY(animation->columns == 0 || animation->rows == 0))
        return nsf_utils_log(NSF_LOG_LVL_WARNING, NSF_ANIMATION,
            __FUNCTION__, "columns or rows not set properly");
    if (NSF_UNLIKELY(animation->sprite_size.x == 0 ||
            animation->sprite_size.y == 0))
        return nsf_utils_log(NSF_LOG_LVL_WARNING, NSF_ANIMATION,
            __FUNCTION__, "sprite size not set properly");
    animation->rect.left = (animation->step % animation->columns) *
        (animation->sprite_size.x + animation->offset.x);
    animation->rect.top = (animation->step / animation->columns) *
        (animation->sprite_size.y + animation->offset.y);
    animation->rect.width = animation->sprite_size.x;
    animation->rect.height = animation->sprite_size.y;
}
