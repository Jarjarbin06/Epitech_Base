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

void nsf_vector_add(const nsf_fvector_t a[],
    const nsf_fvector_t b[], nsf_fvector_t *out)
{
    if (NSF_UNLIKELY(!a || !b || !out)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_VECTOR,
            __FUNCTION__, "pointer corrupted");
        return nsf_fvector_empty(out);
    }
    out->x = a->x + b->x;
    out->y = a->y + b->y;
}

void nsf_vector_sub(const nsf_fvector_t a[],
    const nsf_fvector_t b[], nsf_fvector_t *out)
{
    if (NSF_UNLIKELY(!a || !b || !out)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_VECTOR,
            __FUNCTION__, "pointer corrupted");
        return nsf_fvector_empty(out);
    }
    out->x = a->x - b->x;
    out->y = a->y - b->y;
}

void nsf_vector_mul(const nsf_fvector_t v[], const float scalar,
    nsf_fvector_t *out)
{
    if (NSF_UNLIKELY(!v || !out)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_VECTOR,
            __FUNCTION__, "pointer corrupted");
        return nsf_fvector_empty(out);
    }
    out->x = v->x * scalar;
    out->y = v->y * scalar;
}

void nsf_vector_div(const nsf_fvector_t v[], float scalar,
    nsf_fvector_t *out)
{
    if (NSF_UNLIKELY(!v || !out)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_VECTOR,
            __FUNCTION__, "pointer corrupted");
        return nsf_fvector_empty(out);
    }
    if (scalar == 0.0f)
        scalar = 1.0f;
    out->x = v->x / scalar;
    out->y = v->y / scalar;
}
