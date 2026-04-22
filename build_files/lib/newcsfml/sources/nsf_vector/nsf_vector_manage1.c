/*
** EPITECH PROJECT, 2026
** EpitechBase - nsf_vector_1.c
** File description:
** <description>
*/

#include "../../includes/newcsfml.h"

void nsf_fvector_empty(nsf_fvector_t *out)
{
    if (!out)
        return;
    out->x = 0.0f;
    out->y = 0.0f;
}

void nsf_fvector_from_i(const nsf_ivector_t v[], nsf_fvector_t *out)
{
    if (!v || !out)
        return nsf_fvector_empty(out);
    out->x = (float)v->x;
    out->y = (float)v->y;
}

void nsf_fvector_from_u(const nsf_uvector_t v[],
    nsf_fvector_t *out)
{
    if (!v || !out)
        return nsf_fvector_empty(out);
    out->x = (float)v->x;
    out->y = (float)v->y;
}

void nsf_fvector_copy(const nsf_fvector_t v[],
    nsf_fvector_t *out)
{
    if (!v || !out)
        return nsf_fvector_empty(out);
    out->x = v->x;
    out->y = v->y;
}
