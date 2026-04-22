/*
** EPITECH PROJECT, 2026
** EpitechBase - nsf_vector_1.c
** File description:
** <description>
*/

#include "../../includes/newcsfml.h"

void nsf_ivector_empty(nsf_ivector_t *out)
{
    if (!out)
        return;
    out->x = 0;
    out->y = 0;
}

void nsf_ivector_from_f(const nsf_fvector_t v[],
    nsf_ivector_t *out)
{
    if (!v || !out)
        return nsf_ivector_empty(out);
    out->x = (int)v->x;
    out->y = (int)v->y;
}

void nsf_ivector_from_u(const nsf_uvector_t v[],
    nsf_ivector_t *out)
{
    if (!v || !out)
        return nsf_ivector_empty(out);
    out->x = (int)v->x;
    out->y = (int)v->y;
}

void nsf_ivector_copy(const nsf_ivector_t v[],
    nsf_ivector_t *out)
{
    if (!v || !out)
        return nsf_ivector_empty(out);
    out->x = v->x;
    out->y = v->y;
}
