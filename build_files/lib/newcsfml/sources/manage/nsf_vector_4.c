/*
** EPITECH PROJECT, 2026
** EpitechBase - nsf_vector_1.c
** File description:
** <description>
*/

#include "../../includes/newcsfml.h"

void nsf_vector_add(const nsf_fvector_t a[],
    const nsf_fvector_t b[], nsf_fvector_t *out)
{
    if (!a || !b || !out)
        return nsf_fvector_empty(out);
    out->x = a->x + b->x;
    out->y = a->y + b->y;
}

void nsf_vector_sub(const nsf_fvector_t a[],
    const nsf_fvector_t b[], nsf_fvector_t *out)
{
    if (!a || !b || !out)
        return nsf_fvector_empty(out);
    out->x = a->x - b->x;
    out->y = a->y - b->y;
}

void nsf_vector_mul(const nsf_fvector_t v[], const float scalar,
    nsf_fvector_t *out)
{
    if (!v || !out)
        return nsf_fvector_empty(out);
    out->x = v->x * scalar;
    out->y = v->y * scalar;
}

void nsf_vector_div(const nsf_fvector_t v[], float scalar,
    nsf_fvector_t *out)
{
    if (!v || !out)
        return nsf_fvector_empty(out);
    if (scalar == 0.0f)
        scalar = 1.0f;
    out->x = v->x / scalar;
    out->y = v->y / scalar;
}
