/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.8
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
#include "newcsfml/systems/vector.h"
#include "newcsfml/systems/utils.h"

void nsf_animation_set_line(nsf_animation_t *animation,
    const int line)
{
    if (NSF_UNLIKELY(!animation))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_ANIMATION,
            __FUNCTION__, "pointer corrupted");
    animation->current_line = line;
}

void nsf_animation_set_offset(nsf_animation_t *animation,
    const nsf_uvector_t offset[])
{
    if (NSF_UNLIKELY(!animation))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_ANIMATION,
            __FUNCTION__, "pointer corrupted");
    animation->offset = nsf_uvector_copy(offset);
}

void nsf_animation_set_step(nsf_animation_t *animation, const nsf_uint_t step)
{
    if (NSF_UNLIKELY(!animation))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_ANIMATION,
            __FUNCTION__, "pointer corrupted");
    if (NSF_UNLIKELY(animation->columns == 0 || animation->rows == 0))
        return nsf_utils_log(NSF_LOG_LVL_WARNING, NSF_ANIMATION,
            __FUNCTION__, "columns or rows not set properly");
    animation->step = step;
    animation->step %= animation->columns * animation->rows;
}
