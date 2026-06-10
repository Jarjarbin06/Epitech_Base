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

#include "newcsfml/systems/vector.h"
#include "newcsfml/games/window.h"
#include "newcsfml/systems/utils.h"

int nsf_window_display(const nsf_window_t *window)
{
    if (NSF_UNLIKELY(!window))
        return nsf_utils_log_failure(NSF_LOG_LVL_ERROR, NSF_WINDOW,
            __FUNCTION__, "pointer corrupted");
    sfRenderWindow_display(window->window);
    return E_SUCCESS;
}

bool nsf_window_get_event(const nsf_window_t *window, nsf_event_t *event)
{
    if (NSF_UNLIKELY(!window || !event))
        return nsf_utils_log_false(NSF_LOG_LVL_ERROR, NSF_WINDOW,
            __FUNCTION__, "pointer corrupted");
    return (bool)sfRenderWindow_pollEvent(window->window, event);
}

nsf_ivector_t nsf_window_get_mouse(const nsf_window_t *window)
{
    nsf_ivector_t pixel = {0, 0};
    nsf_fvector_t world = {0.0f, 0.0f};

    if (NSF_UNLIKELY(!window)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
            "pointer corrupted");
        return nsf_ivector_empty();
    }
    pixel = sfMouse_getPositionRenderWindow(window->window);
    world = sfRenderWindow_mapPixelToCoords(window->window, pixel, NULL);
    return (nsf_ivector_t){(int)world.x, (int)world.y};
}
