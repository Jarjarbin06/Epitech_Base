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

#include "newcsfml/games/window_settings.h"
#include "newcsfml/systems/vector.h"
#include "newcsfml/games/window.h"
#include "newcsfml/systems/utils.h"

int nsf_window_update_settings(const nsf_window_t *window)
{
    nsf_uvector_t size = {0, 0};

    if (NSF_UNLIKELY(!window || !window->window || !window->settings))
        return nsf_utils_log_error(NSF_LOG_LVL_ERROR, NSF_WINDOW,
            __FUNCTION__, "pointer corrupted");
    size = sfRenderWindow_getSize(window->window);
    window->settings->width = size.x;
    window->settings->height = size.y;
    return E_SUCCESS;
}
