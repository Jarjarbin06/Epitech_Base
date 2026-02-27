/*
** EPITECH PROJECT, 2025
** struct - nsf_sprite.c
** File description:
** <description>
*/

#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>

#include "../../includes/newcsfml.h"

void nsf_button_set_texture(nsf_button_t *button, nsf_texture_t *texture)
{
    if (!button || !texture)
        return;
    button->texture = texture;
    sfRectangleShape_setTexture(button->button, button->texture->texture,
        sfFalse);
}

void nsf_button_set_position(nsf_button_t *button, const nsf_vector position)
{
    if (!button)
        return;
    sfRectangleShape_setPosition(button->button, (sfVector2f)position);
}

void nsf_button_set_size(nsf_button_t *button, const nsf_vector position)
{
    if (!button)
        return;
    sfRectangleShape_setSize(button->button, (sfVector2f)position);
}

void nsf_button_set_colors(nsf_button_t *button,
    const nsf_color_t fill_color, const nsf_color_t outline_color,
    const nsf_uint outline_thickness)
{
    if (!button)
        return;
    if (fill_color.a)
        sfRectangleShape_setFillColor(button->button, (sfColor)fill_color);
    if (outline_color.a)
    sfRectangleShape_setOutlineColor(button->button, (sfColor)outline_color);
    sfRectangleShape_setOutlineThickness(button->button,
        (float)outline_thickness);
}

bool nsf_button_check_click(nsf_button_t *button, nsf_window_t *window,
    nsf_mouse mouse_button)
{
    sfVector2i mousePos = {};
    sfFloatRect bounds = {};

    if (!button || !window)
        return false;
    mousePos = sfMouse_getPositionRenderWindow(window->window);
    bounds = sfRectangleShape_getGlobalBounds(button->button);
    return (sfFloatRect_contains(&bounds, mousePos.x, mousePos.y) &&
        sfMouse_isButtonPressed((sfMouseButton)mouse_button));
}
