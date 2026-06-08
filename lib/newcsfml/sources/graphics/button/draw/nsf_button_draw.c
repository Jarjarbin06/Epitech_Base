/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.9
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

#include <SFML/Graphics/RenderWindow.h>

#include "newcsfml/games/window.h"
#include "newcsfml/graphics/button.h"
#include "newcsfml/systems/utils.h"

void nsf_button_draw(const nsf_button_t *button, const nsf_window_t *window)
{
    if (NSF_UNLIKELY(!button || !window))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_BUTTON, __FUNCTION__,
            "pointer corrupted");
    sfRenderWindow_drawRectangleShape(window->window, button->button, NULL);
}
