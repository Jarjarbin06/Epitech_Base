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

#include "newcsfml/systems/utils.h"
#include "newcsfml/systems/vector.h"

void nsf_fvector_empty(nsf_fvector_t *out)
{
    if (NSF_UNLIKELY(!out))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_VECTOR,
            __FUNCTION__, "pointer corrupted");
    out->x = 0.0f;
    out->y = 0.0f;
}

void nsf_fvector_from_i(const nsf_ivector_t v[], nsf_fvector_t *out)
{
    if (NSF_UNLIKELY(!v || !out)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_VECTOR,
            __FUNCTION__, "pointer corrupted");
        return nsf_fvector_empty(out);
    }
    out->x = (float)v->x;
    out->y = (float)v->y;
}

void nsf_fvector_from_u(const nsf_uvector_t v[],
    nsf_fvector_t *out)
{
    if (NSF_UNLIKELY(!v || !out)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_VECTOR,
            __FUNCTION__, "pointer corrupted");
        return nsf_fvector_empty(out);
    }
    out->x = (float)v->x;
    out->y = (float)v->y;
}

void nsf_fvector_copy(const nsf_fvector_t v[],
    nsf_fvector_t *out)
{
    if (NSF_UNLIKELY(!v || !out)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_VECTOR,
            __FUNCTION__, "pointer corrupted");
        return nsf_fvector_empty(out);
    }
    out->x = v->x;
    out->y = v->y;
}
