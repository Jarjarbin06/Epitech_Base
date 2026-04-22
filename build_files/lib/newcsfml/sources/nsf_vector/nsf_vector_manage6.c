/*
** EPITECH PROJECT, 2026
** EpitechBase - nsf_vector_1.c
** File description:
** <description>
*/

#include <stdio.h>
#include <math.h>

#include "../../includes/newcsfml.h"

float nsf_vector_dot(const nsf_fvector_t a[],
    const nsf_fvector_t b[])
{
    if (!a || !b)
        return 0;
    return (a->x * b->x) + (a->y * b->y);
}

float nsf_vector_cross(const nsf_fvector_t a[],
    const nsf_fvector_t b[])
{
    if (!a || !b)
        return 0;
    return (a->x * b->y) - (a->y * b->x);
}

float nsf_vector_get_angle(const nsf_fvector_t v[])
{
    double angle = 0.0;

    if (!v)
        return 0;
    angle = atan2((double)v->y, (double)v->x);
    return ((float)NSF_DEGREE((double)angle));
}

void nsf_vector_rotate(const nsf_fvector_t v[], const float angle,
    nsf_fvector_t *out)
{
    const double rad_angle = NSF_RADIAN((double)angle);
    const float cos_res = (float)cos(rad_angle);
    const float sin_res = (float)sin(rad_angle);

    if (!v)
        return nsf_fvector_empty(out);
    out->x = (v->x * cos_res) - (v->y * sin_res);
    out->y = (v->x * sin_res) + (v->y * cos_res);
}

void nsf_vector_print(const nsf_fvector_t v[])
{
    if (!v)
        printf("{corrupted}\n");
    else
        printf("{.x = %f, .y = %f}\n", v->x, v->y);
}
