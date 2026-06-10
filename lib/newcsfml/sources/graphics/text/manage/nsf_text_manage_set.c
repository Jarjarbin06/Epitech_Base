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

#include <SFML/Graphics/Text.h>

#include "newcsfml/graphics/text.h"
#include "newcsfml/systems/color.h"
#include "newcsfml/systems/other.h"
#include "newcsfml/systems/utils.h"
#include "newcsfml/systems/vector.h"

void nsf_text_set_string(nsf_text_t *text, const char string[])
{
    size_t idx = 0;

    if (NSF_UNLIKELY(!text || !string))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_TEXT, __FUNCTION__,
            "pointer corrupted");
    for (; string[idx] != '\0'; idx++)
        text->buffer[idx] = string[idx];
    text->buffer[idx] = '\0';
    sfText_setString(text->text, text->buffer);
}

void nsf_text_set_size(nsf_text_t *text, const nsf_uint_t size)
{
    if (NSF_UNLIKELY(!text))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_TEXT, __FUNCTION__,
            "pointer corrupted");
    text->size = size;
    sfText_setCharacterSize(text->text, text->size);
}

void nsf_text_set_position(nsf_text_t *text, const nsf_fvector_t position[])
{
    if (NSF_UNLIKELY(!text))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_TEXT, __FUNCTION__,
            "pointer corrupted");
    text->postition = nsf_fvector_copy(position);
    sfText_setPosition(text->text, text->postition);
}

void nsf_text_set_color(nsf_text_t *text, const nsf_color_t color[])
{
    if (NSF_UNLIKELY(!text))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_TEXT, __FUNCTION__,
            "pointer corrupted");
    text->color = *color;
    sfText_setFillColor(text->text, text->color);
}
