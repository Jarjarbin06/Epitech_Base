/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.5
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

#include "newcsfml/graphics/texture.h"
#include "newcsfml/systems/utils.h"
#include "newcsfml/systems/vector.h"
#include "newcsfml/games/event.h"
#include "newcsfml/games/window.h"
#include "newcsfml/graphics/button.h"

void nsf_button_set_texture(nsf_button_t *button, const nsf_texture_t *texture)
{
    if (NSF_UNLIKELY(!button || !texture))
        return;
    button->texture = texture;
    sfRectangleShape_setTexture(button->button, button->texture->texture,
        sfTrue);
    button->size = sfRectangleShape_getSize(button->button);
}

void nsf_button_set_position(nsf_button_t *button,
    const nsf_fvector_t position[])
{
    if (NSF_UNLIKELY(!button))
        return;
    button->position = *position;
    sfRectangleShape_setPosition(button->button, button->position);
}

void nsf_button_set_size(nsf_button_t *button, const nsf_fvector_t size[])
{
    if (NSF_UNLIKELY(!button))
        return;
    button->size = *size;
    sfRectangleShape_setOrigin(button->button, (sfVector2f){0.0f, 0.0f});
    sfRectangleShape_setSize(button->button, button->size);
}

void nsf_button_set_colors(nsf_button_t *button,
    const nsf_color_t fill_color[], const nsf_color_t outline_color[],
    const nsf_uint_t outline_thickness)
{
    if (NSF_UNLIKELY(!button))
        return;
    button->fill_color = *fill_color;
    sfRectangleShape_setFillColor(button->button, button->fill_color);
    button->outline_color = *outline_color;
    sfRectangleShape_setOutlineColor(button->button,
        button->outline_color);
    sfRectangleShape_setOutlineThickness(button->button,
        (float)outline_thickness);
}

nsf_button_status_t nsf_button_get_state(const nsf_button_t *button,
    const nsf_window_t *window, const nsf_mouse_button_t mouse_button)
{
    sfVector2i pixelPos = {};
    nsf_fvector_t worldPos = {};
    sfFloatRect bounds = {};
    bool hovered = false;
    bool pressed = false;

    if (NSF_UNLIKELY(!button || !button->button || !window))
        return NSF_STT_BTN_UNKNOWN;
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
