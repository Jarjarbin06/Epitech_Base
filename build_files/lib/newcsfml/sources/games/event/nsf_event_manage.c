/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.4
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
#include <SFML/Window/Keyboard.h>

#include "newcsfml/systems/vector.h"
#include "newcsfml/games/event.h"
#include "newcsfml/games/keyboard.h"
#include "newcsfml/systems/utils.h"

bool nsf_event_cmp(const nsf_event_t *event, const nsf_event_type_t event_type)
{
    return (event->type == (sfEventType)event_type);
}

bool nsf_event_cmp_key(const nsf_event_t *event, const nsf_key_code_t key_code)
{
    return (event->key.code == (sfKeyCode)key_code);
}

void nsf_event_get_mouse_move(const nsf_event_t *event,
    nsf_ivector_t out[])
{
    nsf_ivector_t out_tmp = {};

    if (NSF_UNLIKELY(!event || !out))
        return;
    out_tmp.x = event->mouseMove.x;
    out_tmp.y = event->mouseMove.y;
    nsf_ivector_copy(&out_tmp, out);
}

float nsf_event_get_mouse_wheel(const nsf_event_t *event)
{
    if (NSF_UNLIKELY(!event))
        return 0.0f;
    return event->mouseWheelScroll.delta;
}
