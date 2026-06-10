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

#include "newcsfml/systems/utils.h"

bool nsf_utils_logic_or(const bool a, const bool b)
{
    return a || b;
}

bool nsf_utils_logic_or_batch(const size_t len, const bool values[])
{
    if (NSF_UNLIKELY(!values))
        return nsf_utils_log_false(NSF_LOG_LVL_ERROR, NSF_UTILS,
            __FUNCTION__, "pointer corrupted");
    for (size_t idx = 0; idx < len; idx++)
        if (values[idx])
            return true;
    return false;
}

bool nsf_utils_logic_nor(const bool a, const bool b)
{
    return !(a || b);
}

bool nsf_utils_logic_nor_batch(const size_t len, const bool values[])
{
    if (NSF_UNLIKELY(!values))
        return nsf_utils_log_false(NSF_LOG_LVL_ERROR, NSF_UTILS,
            __FUNCTION__, "pointer corrupted");
    return !nsf_utils_logic_or_batch(len, values);
}
