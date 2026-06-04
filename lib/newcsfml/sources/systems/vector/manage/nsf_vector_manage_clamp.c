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

void nsf_vector_clamp_x(const nsf_fvector_t v[], const float min,
    const float max, nsf_fvector_t *out)
{
    if (NSF_UNLIKELY(!v)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_VECTOR,
            __FUNCTION__, "pointer corrupted");
        return nsf_fvector_empty(out);
    }
    nsf_fvector_copy(v, out);
    if (v->x < min)
        out->x = min;
    if (v->x > max)
        out->x = max;
}

void nsf_vector_clamp_y(const nsf_fvector_t v[], const float min,
    const float max, nsf_fvector_t *out)
{
    if (NSF_UNLIKELY(!v)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_VECTOR,
            __FUNCTION__, "pointer corrupted");
        return nsf_fvector_empty(out);
    }
    nsf_fvector_copy(v, out);
    if (v->y < min)
        out->y = min;
    if (v->y > max)
        out->y = max;
}

void nsf_vector_clamp(const nsf_fvector_t v[], const float min,
    const float max, nsf_fvector_t *out)
{
    nsf_fvector_t out_tmp = {0, 0};

    if (NSF_UNLIKELY(!v)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_VECTOR,
            __FUNCTION__, "pointer corrupted");
        return nsf_fvector_empty(out);
    }
    nsf_vector_clamp_x(v, min, max, &out_tmp);
    nsf_vector_clamp_y(&out_tmp, min, max, out);
}
