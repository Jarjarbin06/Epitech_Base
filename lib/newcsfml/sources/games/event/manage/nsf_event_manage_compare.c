/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.8
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

#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>

#include "newcsfml/games/event.h"
#include "newcsfml/games/keyboard.h"
#include "newcsfml/systems/utils.h"

bool nsf_event_cmp(const nsf_event_t *event, const nsf_event_type_t event_type)
{
    if (NSF_UNLIKELY(!event))
        return nsf_utils_log_false(NSF_LOG_LVL_ERROR, NSF_EVENT, __FUNCTION__,
            "pointer corrupted");
    return (event->type == (sfEventType)event_type);
}

bool nsf_event_cmp_key(const nsf_event_t *event, const nsf_key_code_t key_code)
{
    if (NSF_UNLIKELY(!event))
        return nsf_utils_log_false(NSF_LOG_LVL_ERROR, NSF_EVENT, __FUNCTION__,
            "pointer corrupted");
    return (event->key.code == (sfKeyCode)key_code);
}
