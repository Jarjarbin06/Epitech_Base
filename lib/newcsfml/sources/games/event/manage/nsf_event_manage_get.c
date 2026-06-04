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

#include <SFML/Window/Event.h>

#include "newcsfml/systems/vector.h"
#include "newcsfml/games/event.h"
#include "newcsfml/games/mouse.h"
#include "newcsfml/systems/utils.h"

void nsf_event_get_mouse_move(const nsf_event_t *event,
    nsf_ivector_t out[])
{
    nsf_ivector_t out_tmp = {0, 0};

    if (NSF_UNLIKELY(!event || !out))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_EVENT, __FUNCTION__,
            "pointer corrupted");
    out_tmp.x = event->mouseMove.x;
    out_tmp.y = event->mouseMove.y;
    nsf_ivector_copy(&out_tmp, out);
}

float nsf_event_get_mouse_wheel(const nsf_event_t *event)
{
    if (NSF_UNLIKELY(!event))
        return (float)nsf_utils_log_zero(NSF_LOG_LVL_ERROR, NSF_EVENT,
            __FUNCTION__, "pointer corrupted");
    return event->mouseWheelScroll.delta;
}
