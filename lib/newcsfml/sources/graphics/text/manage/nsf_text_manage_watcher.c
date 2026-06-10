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

#include "newcsfml/graphics/text.h"
#include "newcsfml/systems/utils.h"
#include "newcsfml/systems/watcher.h"

void nsf_text_set_watcher(nsf_text_t *text, nsf_watcher_t *watcher)
{
    if (NSF_UNLIKELY(!text || !watcher))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_TEXT, __FUNCTION__,
            "pointer corrupted");
    text->watcher = watcher;
}

nsf_watcher_t *nsf_text_get_watcher(nsf_text_t *text)
{
    if (NSF_UNLIKELY(!text))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_TEXT, __FUNCTION__,
            "pointer corrupted");
    return text->watcher;
}

void nsf_text_update_from_watcher(nsf_text_t *text)
{
    if (NSF_UNLIKELY(!text))
        return;
    if (!text->watcher)
        return;
    if (NSF_UNLIKELY(
            nsf_watcher_get_string_in_buffer(text->watcher, text->buffer)))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_TEXT, __FUNCTION__,
            "watcher value retrieval failed");
    nsf_text_set_string(text, text->buffer);
}
