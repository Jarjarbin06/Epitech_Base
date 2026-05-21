/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.7
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

#include "newcsfml/systems/other.h"
#include "newcsfml/systems/utils.h"
#include "newcsfml/graphics/view.h"
#include "newcsfml/systems/vector.h"

void nsf_view_get_center(nsf_view_t *view, nsf_fvector_t *out)
{
    if (NSF_UNLIKELY(!view || !out)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_VIEW, __FUNCTION__,
            "pointer corrupted");
        return nsf_fvector_empty(out);
    }
    nsf_fvector_copy(&view->center, out);
}

void nsf_view_get_size(nsf_view_t *view, nsf_uvector_t *out)
{
    if (NSF_UNLIKELY(!view || !out)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_VIEW, __FUNCTION__,
            "pointer corrupted");
        return nsf_uvector_empty(out);
    }
    nsf_uvector_copy(&view->size, out);
}
