/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.3
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

#include "newcsfml/graphics/background.h"
#include "newcsfml/games/window.h"
#include "newcsfml/systems/utils.h"

void nsf_window_set_background(nsf_window_t *window,
    nsf_background_t *background)
{
    if (NSF_UNLIKELY(!window || !background))
        return;
    window->background = background;
}

const nsf_background_t *nsf_window_get_background(const nsf_window_t *window)
{
    if (NSF_UNLIKELY(!window))
        return NULL;
    return window->background;
}
