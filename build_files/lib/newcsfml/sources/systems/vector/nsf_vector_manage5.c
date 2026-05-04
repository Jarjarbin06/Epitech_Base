/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.2
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

void nsf_vector_neg(const nsf_fvector_t v[], nsf_fvector_t *out)
{
    if (NSF_UNLIKELY(!v || !out))
        return nsf_fvector_empty(out);
    out->x = -v->x;
    out->y = -v->y;
}

static float squared_length(const nsf_fvector_t v[])
{
    if (NSF_UNLIKELY(!v))
        return -1.0f;
    return (v->x * v->x) + (v->y * v->y);
}

float nsf_vector_len(const nsf_fvector_t v[])
{
    const float squared = squared_length(v);
    float x = squared;

    if (NSF_UNLIKELY(!v))
        return -1.0f;
    if (squared == -1)
        return -1.0f;
    for (int i = 0; i < 64; i++)
        x = (x + squared / x) * 0.5f;
    return x;
}

void nsf_vector_norm(const nsf_fvector_t v[], nsf_fvector_t *out)
{
    const float length = nsf_vector_len(v);

    if (NSF_UNLIKELY(!v || !out))
        return nsf_fvector_empty(out);
    if (length == -1)
        return nsf_fvector_empty(out);
    return nsf_vector_div(v, length, out);
}

float nsf_vector_dist_to(const nsf_fvector_t a[],
    const nsf_fvector_t b[])
{
    nsf_fvector_t out = {};

    if (NSF_UNLIKELY(!a || !b))
        return -1.0f;
    nsf_fvector_empty(&out);
    nsf_vector_sub(b, a, &out);
    return nsf_vector_len(&out);
}

void nsf_vector_dir_to(const nsf_fvector_t a[],
    const nsf_fvector_t b[], nsf_fvector_t *out)
{
    nsf_fvector_t tmp_out = {};

    if (NSF_UNLIKELY(!a || !b || !out))
        return nsf_fvector_empty(out);
    nsf_fvector_empty(&tmp_out);
    nsf_vector_sub(b, a, &tmp_out);
    nsf_vector_norm(&tmp_out, out);
}
