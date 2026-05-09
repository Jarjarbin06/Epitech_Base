/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.4
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

#include <stdio.h>

#include "newcsfml/systems/utils.h"
#include "newcsfml/systems/vector.h"

float nsf_vector_dot(const nsf_fvector_t a[],
    const nsf_fvector_t b[])
{
    if (NSF_UNLIKELY(!a || !b))
        return 0;
    return (a->x * b->x) + (a->y * b->y);
}

float nsf_vector_cross(const nsf_fvector_t a[],
    const nsf_fvector_t b[])
{
    if (NSF_UNLIKELY(!a || !b))
        return 0;
    return (a->x * b->y) - (a->y * b->x);
}

float nsf_vector_get_angle(const nsf_fvector_t v[])
{
    double angle = 0.0;

    if (NSF_UNLIKELY(!v))
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

    if (NSF_UNLIKELY(!v))
        return nsf_fvector_empty(out);
    out->x = (v->x * cos_res) - (v->y * sin_res);
    out->y = (v->x * sin_res) + (v->y * cos_res);
}

void nsf_vector_print(const nsf_fvector_t v[])
{
    if (NSF_UNLIKELY(!v))
        printf("{corrupted}\n");
    else
        printf("{.x = %f, .y = %f}\n", v->x, v->y);
}
