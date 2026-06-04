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

#include "newcsfml/systems/other.h"
#include "newcsfml/systems/utils.h"

bool nsf_utils_env_check_display(const char *const *env)
{
    if (NSF_UNLIKELY(!env))
        return nsf_utils_log_false(NSF_LOG_LVL_ERROR, NSF_UTILS,
            __FUNCTION__, "pointer corrupted");
    for (size_t idx = 0; env[idx]; idx++)
        if (!str_cmp("DISPLAY=:0", env[idx]))
            return true;
    return false;
}
