/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.7
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

#include "newcsfml/systems/other.h"
#include "newcsfml/systems/utils.h"
#include "newcsfml/systems/watcher.h"

static int get_string_buffer(const long int nb, char *buffer, int idx)
{
    if (NSF_UNLIKELY(!buffer))
        return nsf_utils_log_error(NSF_LOG_LVL_ERROR, NSF_WATCHER,
            __FUNCTION__, "pointer corrupted");
    if (nb >= 10)
        idx = get_string_buffer(nb / 10, buffer, idx);
    buffer[idx] = (char)((nb % 10) + '0');
    return idx + 1;
}

int nsf_watcher_get_string_in_buffer(nsf_watcher_t *watcher, char buffer[])
{
    size_t last_idx = 0;

    if (NSF_UNLIKELY(!watcher || !buffer))
        return nsf_utils_log_error(NSF_LOG_LVL_ERROR, NSF_WATCHER,
            __FUNCTION__, "pointer corrupted");
    last_idx = get_string_buffer(nsf_watcher_get_int(watcher), buffer, 0);
    buffer[last_idx] = '\0';
    return E_SUCCESS;
}
