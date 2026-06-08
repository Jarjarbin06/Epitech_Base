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

#include <SFML/Window/Joystick.h>

#include "newcsfml/games/joystick.h"
#include "newcsfml/systems/utils.h"

nsf_bool_t nsf_joystick_is_connected(const nsf_joystick_id_t joystick_id)
{
    if (joystick_id >= NSF_JOYSTICK_COUNT)
        return nsf_utils_log_false(NSF_LOG_LVL_WARNING, NSF_JOYSTICK,
            __FUNCTION__, "invalid joystick ID");
    return sfJoystick_isConnected(joystick_id);
}
