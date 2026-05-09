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

#include "newcsfml/systems/other.h"
#include "newcsfml/systems/utils.h"
#include "newcsfml/systems/watcher.h"

float nsf_watcher_get_float(nsf_watcher_t *watcher)
{
    if (NSF_UNLIKELY(!watcher))
        return 0.0f;
    if (watcher->type == NSF_WTC_FLOAT)
        return *(float *)watcher->ptr;
    if (watcher->type == NSF_WTC_INT)
        return (float)nsf_watcher_get_int(watcher);
    return 0.0f;
}

long int nsf_watcher_get_int(nsf_watcher_t *watcher)
{
    if (NSF_UNLIKELY(!watcher))
        return 0;
    if (watcher->type == NSF_WTC_INT)
        return *(int *)watcher->ptr;
    if (watcher->type == NSF_WTC_FLOAT)
        return (long int)nsf_watcher_get_float(watcher);
    if (watcher->type == NSF_WTC_CHAR)
        return (long int)nsf_watcher_get_char(watcher);
    if (watcher->type == NSF_WTC_STRING)
        return (long int)nsf_watcher_get_string(watcher);
    return 0;
}

char nsf_watcher_get_char(nsf_watcher_t *watcher)
{
    if (NSF_UNLIKELY(!watcher))
        return 0;
    if (watcher->type == NSF_WTC_CHAR)
        return *(char *)watcher->ptr;
    if (watcher->type == NSF_WTC_INT)
        return (char)nsf_watcher_get_int(watcher);
    return 0;
}

char *nsf_watcher_get_string(nsf_watcher_t *watcher)
{
    if (NSF_UNLIKELY(!watcher))
        return NULL;
    if (watcher->type == NSF_WTC_STRING)
        return *(char **)watcher->ptr;
    return NULL;
}

static int get_string_buffer(const long int nb, char *buffer, int idx)
{
    if (nb >= 10)
        idx = get_string_buffer(nb / 10, buffer, idx);
    buffer[idx] = (char)((nb % 10) + '0');
    return idx + 1;
}

int nsf_watcher_get_string_in_buffer(nsf_watcher_t *watcher, char buffer[])
{
    size_t last_idx = 0;

    if (NSF_UNLIKELY(!watcher || !buffer))
        return EXIT_ERROR;
    last_idx = get_string_buffer(nsf_watcher_get_int(watcher), buffer, 0);
    buffer[last_idx] = '\0';
    return EXIT_SUCCESS;
}
