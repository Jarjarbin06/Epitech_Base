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

#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>

#include "newcsfml/systems/utils.h"
#include "newcsfml/systems/vector.h"
#include "newcsfml/games/mouse.h"
#include "newcsfml/games/window.h"
#include "newcsfml/graphics/button.h"
#include "newcsfml/games/mouse.h"

nsf_button_status_t nsf_button_get_state(const nsf_button_t *button,
    const nsf_window_t *window, const nsf_mouse_button_t mouse_button)
{
    nsf_ivector_t pixelPos = {0, 0};
    nsf_fvector_t worldPos = {0, 0};
    sfFloatRect bounds = {0, 0, 0, 0};
    bool hovered = false;
    bool pressed = false;

    if (NSF_UNLIKELY(!button || !button->button || !window)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_BUTTON, __FUNCTION__,
            "pointer corrupted");
        return NSF_STT_BTN_UNKNOWN;
    }
    pixelPos = sfMouse_getPositionRenderWindow(window->window);
    worldPos = sfRenderWindow_mapPixelToCoords(window->window,
        pixelPos, NULL);
    bounds = sfRectangleShape_getGlobalBounds(button->button);
    hovered = sfFloatRect_contains(&bounds, worldPos.x, worldPos.y);
    pressed = sfMouse_isButtonPressed((sfMouseButton)mouse_button);
    if (hovered) {
        if (!pressed)
            return NSF_STT_BTN_HOVERED;
        return NSF_STT_BTN_PRESSED;
    }
    return NSF_STT_BTN_NONE;
}
