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

float nsf_vector_get_angle(const nsf_fvector_t v[])
{
    double angle = 0.0;

    if (NSF_UNLIKELY(!v))
        return (float)nsf_utils_log_zero(NSF_LOG_LVL_ERROR, NSF_VECTOR,
            __FUNCTION__, "pointer corrupted");
    angle = atan2((double)v->y, (double)v->x);
    return ((float)NSF_DEGREE((double)angle));
}

void nsf_vector_rotate(const nsf_fvector_t v[], const float angle,
    nsf_fvector_t *out)
{
    const double rad_angle = NSF_RADIAN((double)angle);
    const float cos_res = (float)cos(rad_angle);
    const float sin_res = (float)sin(rad_angle);

    if (NSF_UNLIKELY(!v)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_VECTOR,
            __FUNCTION__, "pointer corrupted");
        return nsf_fvector_empty(out);
    }
    out->x = (v->x * cos_res) - (v->y * sin_res);
    out->y = (v->x * sin_res) + (v->y * cos_res);
}
