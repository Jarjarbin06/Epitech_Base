/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.2
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

#include <SFML/Graphics/Text.h>

#include "newcsfml/graphics/text.h"
#include "newcsfml/systems/color.h"
#include "newcsfml/systems/utils.h"

void nsf_text_set_string(nsf_text_t *text, char string[])
{
    if (NSF_UNLIKELY(!text || !string))
        return;
    sfText_setString(text->text, string);
}

void nsf_text_set_size(nsf_text_t *text, const nsf_uint_t size)
{
    if (NSF_UNLIKELY(!text))
        return;
    sfText_setCharacterSize(text->text, size);
}

void nsf_text_set_position(nsf_text_t *text, const nsf_uint_t position)
{
    if (NSF_UNLIKELY(!text))
        return;
    sfText_setCharacterSize(text->text, position);
}

void nsf_text_set_color(nsf_text_t *text, const nsf_color_t color[])
{
    if (NSF_UNLIKELY(!text))
        return;
    sfText_setFillColor(text->text, *color);
}
