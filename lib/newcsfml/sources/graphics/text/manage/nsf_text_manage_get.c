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

#include <SFML/Graphics/Text.h>

#include "newcsfml/graphics/text.h"
#include "newcsfml/systems/utils.h"
#include "newcsfml/systems/vector.h"

nsf_cstr_t nsf_text_get_string(nsf_text_t *text)
{
    if (NSF_UNLIKELY(!text))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_TEXT, __FUNCTION__,
            "pointer corrupted");
    return (nsf_cstr_t)text->buffer;
}

nsf_fvector_t nsf_text_get_size(nsf_text_t *text)
{
    sfFloatRect bounds = {0.0f, 0.0f, 0.0f, 0.0f};

    if (NSF_UNLIKELY(!text)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_TEXT, __FUNCTION__,
            "pointer corrupted");
        return nsf_fvector_empty();
    }
    bounds = sfText_getLocalBounds(text->text);
    return (nsf_fvector_t){bounds.width, bounds.height};
}

nsf_fvector_t nsf_text_get_position(nsf_text_t *text)
{
    if (NSF_UNLIKELY(!text)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_TEXT, __FUNCTION__,
            "pointer corrupted");
        return nsf_fvector_empty();
    }
    return text->postition;
}
