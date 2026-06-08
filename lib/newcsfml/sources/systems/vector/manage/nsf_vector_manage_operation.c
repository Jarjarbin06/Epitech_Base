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

#include "newcsfml/systems/utils.h"
#include "newcsfml/systems/vector.h"

nsf_fvector_t nsf_vector_add(const nsf_fvector_t a[], const nsf_fvector_t b[])
{
    if (NSF_UNLIKELY(!a || !b)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_VECTOR,
            __FUNCTION__, "pointer corrupted");
        return nsf_fvector_empty();
    }
    return (nsf_fvector_t){a->x + b->x, a->y + b->y};
}

nsf_fvector_t nsf_vector_sub(const nsf_fvector_t a[], const nsf_fvector_t b[])
{
    if (NSF_UNLIKELY(!a || !b)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_VECTOR,
            __FUNCTION__, "pointer corrupted");
        return nsf_fvector_empty();
    }
    return (nsf_fvector_t){a->x - b->x, a->y - b->y};
}

nsf_fvector_t nsf_vector_mul(const nsf_fvector_t v[], const float scalar)
{
    if (NSF_UNLIKELY(!v)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_VECTOR,
            __FUNCTION__, "pointer corrupted");
        return nsf_fvector_empty();
    }
    return (nsf_fvector_t){v->x * scalar, v->y * scalar};
}

nsf_fvector_t nsf_vector_div(const nsf_fvector_t v[], float scalar)
{
    if (NSF_UNLIKELY(!v)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_VECTOR,
            __FUNCTION__, "pointer corrupted");
        return nsf_fvector_empty();
    }
    if (scalar == 0.0f)
        scalar = 1.0f;
    return (nsf_fvector_t){v->x / scalar, v->y / scalar};
}
