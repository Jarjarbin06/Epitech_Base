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
** Licence: GPL v3
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

float nsf_vector_dist_to(const nsf_fvector_t a[],
    const nsf_fvector_t b[])
{
    nsf_fvector_t out = {0, 0};

    if (NSF_UNLIKELY(!a || !b)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_VECTOR,
            __FUNCTION__, "pointer corrupted");
        return -1.0f;
    }
    nsf_fvector_empty(&out);
    nsf_vector_sub(b, a, &out);
    return nsf_vector_len(&out);
}

void nsf_vector_dir_to(const nsf_fvector_t a[],
    const nsf_fvector_t b[], nsf_fvector_t *out)
{
    nsf_fvector_t tmp_out = {0, 0};

    if (NSF_UNLIKELY(!a || !b || !out)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_VECTOR,
            __FUNCTION__, "pointer corrupted");
        return nsf_fvector_empty(out);
    }
    nsf_fvector_empty(&tmp_out);
    nsf_vector_sub(b, a, &tmp_out);
    nsf_vector_norm(&tmp_out, out);
}
