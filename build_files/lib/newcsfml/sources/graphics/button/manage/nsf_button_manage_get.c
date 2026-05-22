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
#include "newcsfml/systems/other.h"

static bool is_ui(const nsf_cstr_t name)
{
    if (NSF_UNLIKELY(!name)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_WINDOW,
            __FUNCTION__, "pointer corrupted");
        return true;
    }
    for (size_t idx = 0; name[idx] != '\0' &&
        SPECIAL_STR_UI[idx] != '\0'; idx++)
        if (name[idx] != SPECIAL_STR_UI[idx])
            return false;
    return true;
}

static bool is_universal(nsf_cstr_t name)
{
    if (NSF_UNLIKELY(!name)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_WINDOW,
            __FUNCTION__, "pointer corrupted");
        return true;
    }
    if (is_ui(name))
        name = &name[str_len(SPECIAL_STR_UI)];
    for (size_t idx = 0; name[idx] != '\0' &&
        SPECIAL_STR_UNIVERSAL[idx] != '\0'; idx++)
        if (name[idx] != SPECIAL_STR_UNIVERSAL[idx])
            return false;
    return true;
}

static bool is_correct_screen(const nsf_window_t *window, nsf_cstr_t name)
{
    if (NSF_UNLIKELY(!window || !name)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_WINDOW,
            __FUNCTION__, "pointer corrupted");
        return true;
    }
    if (window->current_screen == -1 || is_universal(name))
        return true;
    if (is_ui(name))
        name = &name[str_len(SPECIAL_STR_UI)];
    for (size_t idx = 0; name[idx] != '\0' &&
        window->screens[window->current_screen][idx] != '\0'; idx++)
        if (name[idx] != window->screens[window->current_screen][idx])
            return false;
    return true;
}

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
    if (is_correct_screen(window, button->name)) {
        pixelPos = sfMouse_getPositionRenderWindow(window->window);
        worldPos = sfRenderWindow_mapPixelToCoords(window->window,
            pixelPos, NULL);
        bounds = sfRectangleShape_getGlobalBounds(button->button);
        hovered = sfFloatRect_contains(&bounds, worldPos.x, worldPos.y);
        pressed = sfMouse_isButtonPressed((sfMouseButton)mouse_button);
        if (hovered)
            return (pressed) ? (NSF_STT_BTN_PRESSED) : (NSF_STT_BTN_HOVERED);
    }
    return NSF_STT_BTN_NONE;
}
