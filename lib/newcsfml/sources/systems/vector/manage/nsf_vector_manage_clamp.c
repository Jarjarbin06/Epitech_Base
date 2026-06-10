/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.10
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

#include "newcsfml/systems/utils.h"
#include "newcsfml/systems/vector.h"

nsf_fvector_t nsf_vector_clamp_x(const nsf_fvector_t v[], const float min,
    const float max)
{
    nsf_fvector_t tmp = nsf_fvector_copy(v);

    if (NSF_UNLIKELY(!v)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_VECTOR,
            __FUNCTION__, "pointer corrupted");
        return nsf_fvector_empty();
    }
    if (v->x < min)
        tmp.x = min;
    if (v->x > max)
        tmp.x = max;
    return nsf_fvector_copy(&tmp);
}

nsf_fvector_t nsf_vector_clamp_y(const nsf_fvector_t v[], const float min,
    const float max)
{
    nsf_fvector_t tmp = nsf_fvector_copy(v);

    if (NSF_UNLIKELY(!v)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_VECTOR,
            __FUNCTION__, "pointer corrupted");
        return nsf_fvector_empty();
    }
    if (v->y < min)
        tmp.y = min;
    if (v->y > max)
        tmp.y = max;
    return nsf_fvector_copy(&tmp);
}

nsf_fvector_t nsf_vector_clamp(const nsf_fvector_t v[], const float min,
    const float max)
{
    nsf_fvector_t tmp = nsf_fvector_copy(v);

    if (NSF_UNLIKELY(!v)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_VECTOR,
            __FUNCTION__, "pointer corrupted");
        return nsf_fvector_empty();
    }
    tmp = nsf_vector_clamp_x(&tmp, min, max);
    tmp = nsf_vector_clamp_y(&tmp, min, max);
    return nsf_fvector_copy(&tmp);
}
