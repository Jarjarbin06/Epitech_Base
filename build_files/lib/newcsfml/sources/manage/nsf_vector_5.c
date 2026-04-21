/*
** EPITECH PROJECT, 2026
** EpitechBase - nsf_vector_1.c
** File description:
** <description>
*/

#include "../../includes/newcsfml.h"

void nsf_vector_neg(const nsf_fvector_t v[], nsf_fvector_t *out)
{
    if (!v || !out)
        return nsf_fvector_empty(out);
    out->x = -v->x;
    out->y = -v->y;
}

static float squared_length(const nsf_fvector_t v[])
{
    if (!v)
        return -1;
    return (v->x * v->x) + (v->y * v->y);
}

float nsf_vector_len(const nsf_fvector_t v[])
{
    const float squared = squared_length(v);
    float x = squared;

    if (squared == -1)
        return -1;
    for (int i = 0; i < 64; i++)
        x = (x + squared / x) * 0.5f;
    return x;
}

void nsf_vector_norm(const nsf_fvector_t v[], nsf_fvector_t *out)
{
    const float length = nsf_vector_len(v);

    if (length == -1)
        return nsf_fvector_empty(out);
    return nsf_vector_div(v, length, out);
}

float nsf_vector_dist_to(const nsf_fvector_t a[],
    const nsf_fvector_t b[])
{
    nsf_fvector_t out = {};

    nsf_fvector_empty(&out);
    nsf_vector_sub(b, a, &out);
    return nsf_vector_len(&out);
}

void nsf_vector_dir_to(const nsf_fvector_t a[],
    const nsf_fvector_t b[], nsf_fvector_t *out)
{
    nsf_fvector_t tmp_out = {};

    nsf_fvector_empty(&tmp_out);
    nsf_vector_sub(b, a, &tmp_out);
    nsf_vector_norm(&tmp_out, out);
}
