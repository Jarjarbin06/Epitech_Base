/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.10
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

#include "newcsfml/games/game.h"
#include "newcsfml/graphics/view.h"
#include "newcsfml/systems/other.h"
#include "newcsfml/systems/utils.h"

nsf_view_t *nsf_view_create(nsf_game_t *game)
{
    nsf_view_t *new_view = malloc_any(sizeof(nsf_view_t));
    sfView *sf_view = sfView_create();

    if (NSF_UNLIKELY(!new_view || !sf_view))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_VIEW, __FUNCTION__,
            "alloc failed");
    new_view->view = sf_view;
    new_view->center = (nsf_fvector_t){0.0f, 0.0f};
    new_view->size = (nsf_uvector_t){0.0f, 0.0f};
    new_view->rotation = 0.0f;
    if (game)
        game->allocations++;
    return new_view;
}

int nsf_view_destroy(nsf_view_t **view, nsf_game_t *game)
{
    if (NSF_UNLIKELY(!view || !*view))
        return nsf_utils_log_failure(NSF_LOG_LVL_ERROR, NSF_VIEW, __FUNCTION__,
            "pointer corrupted");
    if (NSF_LIKELY((*view)->view))
        sfView_destroy((*view)->view);
    *view = free_any(*view);
    if (game)
        game->allocations--;
    return E_SUCCESS;
}
