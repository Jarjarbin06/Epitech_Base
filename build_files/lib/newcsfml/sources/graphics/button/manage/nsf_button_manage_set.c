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

#include "newcsfml/graphics/texture.h"
#include "newcsfml/systems/utils.h"
#include "newcsfml/systems/vector.h"
#include "newcsfml/games/window.h"
#include "newcsfml/graphics/button.h"

void nsf_button_set_texture(nsf_button_t *button, const nsf_texture_t *texture)
{
    nsf_uvector_t tmp = {0, 0};

    if (NSF_UNLIKELY(!button || !texture))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_BUTTON, __FUNCTION__,
            "pointer corrupted");
    button->texture = texture;
    sfRectangleShape_setTexture(button->button, button->texture->texture,
        sfTrue);
    tmp = sfTexture_getSize(button->texture->texture);
    nsf_button_set_size(button, &tmp);
}

void nsf_button_set_position(nsf_button_t *button,
    const nsf_fvector_t position[])
{
    if (NSF_UNLIKELY(!button))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_BUTTON, __FUNCTION__,
            "pointer corrupted");
    button->position = *position;
    sfRectangleShape_setPosition(button->button, button->position);
}

void nsf_button_set_size(nsf_button_t *button, const nsf_uvector_t size[])
{
    nsf_fvector_t tmp = {0, 0};

    if (NSF_UNLIKELY(!button))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_BUTTON, __FUNCTION__,
            "pointer corrupted");
    button->size = *size;
    sfRectangleShape_setOrigin(button->button, (nsf_fvector_t){0.0f, 0.0f});
    nsf_fvector_from_u(&button->size, &tmp);
    sfRectangleShape_setSize(button->button, tmp);
}

void nsf_button_set_colors(nsf_button_t *button,
    const nsf_color_t fill_color[], const nsf_color_t outline_color[],
    const int outline_thickness)
{
    if (NSF_UNLIKELY(!button))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_BUTTON, __FUNCTION__,
            "pointer corrupted");
    if (fill_color) {
        button->fill_color = *fill_color;
        sfRectangleShape_setFillColor(button->button, button->fill_color);
    }
    if (outline_color) {
        button->outline_color = *outline_color;
        sfRectangleShape_setOutlineColor(button->button,
            button->outline_color);
    }
    if (outline_thickness >= 0)
        sfRectangleShape_setOutlineThickness(button->button,
            (float)outline_thickness);
}
