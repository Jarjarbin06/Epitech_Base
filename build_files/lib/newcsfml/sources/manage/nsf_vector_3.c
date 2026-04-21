/*
** EPITECH PROJECT, 2026
** EpitechBase - nsf_vector_1.c
** File description:
** <description>
*/

#include "../../includes/newcsfml.h"

void nsf_uvector_empty(nsf_uvector_t *out)
{
    if (!out)
        return;
    out->x = 0;
    out->y = 0;
}

void nsf_uvector_from_f(const nsf_fvector_t v[],
    nsf_uvector_t *out)
{
    if (!v || !out)
        return nsf_uvector_empty(out);
    out->x = (unsigned int)v->x;
    out->y = (unsigned int)v->y;
}

void nsf_uvector_from_i(const nsf_ivector_t v[],
    nsf_uvector_t *out)
{
    if (!v || !out)
        return nsf_uvector_empty(out);
    out->x = (unsigned int)v->x;
    out->y = (unsigned int)v->y;
}

void nsf_uvector_copy(const nsf_uvector_t v[],
    nsf_uvector_t *out)
{
    if (!v || !out)
        return nsf_uvector_empty(out);
    out->x = v->x;
    out->y = v->y;
}
