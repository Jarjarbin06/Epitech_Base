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

#include "newcsfml/games/joystick.h"
#include "newcsfml/systems/utils.h"

static void set_connection(nsf_joystick_xbox_t *xbox)
{
    for (nsf_joystick_id_t idx = 0; idx < NSF_JOYSTICK_COUNT; idx++) {
        xbox->connected = nsf_joystick_is_connected(idx);
        xbox->id = idx;
        if (xbox->connected)
            return;
    }
    xbox->connected = NSF_FALSE;
    xbox->id = -1;
}

void nsf_joystick_xbox_update(nsf_joystick_xbox_t *xbox)
{
    set_connection(xbox);
    if (!xbox->connected)
        return nsf_utils_log(NSF_LOG_LVL_INFO, NSF_JOYSTICK,
            __FUNCTION__, "No Joystick connected");
    for (size_t a = 0; a < NSF_JOYSTICK_AXIS_XBOX_COUNT; a++)
        xbox->buttons[a] = nsf_joystick_get_axis_position(xbox->id, a);
    for (size_t b = 0; b < NSF_JOYSTICK_BUTTON_XBOX_COUNT; b++)
        xbox->buttons[b] = nsf_joystick_is_button_pressed(xbox->id, b);
}
