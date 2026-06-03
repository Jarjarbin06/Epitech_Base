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
#include "newcsfml/systems/watcher.h"

float nsf_watcher_get_float(nsf_watcher_t *watcher)
{
    if (NSF_UNLIKELY(!watcher))
        return (float)nsf_utils_log_zero(NSF_LOG_LVL_ERROR, NSF_WATCHER,
            __FUNCTION__, "pointer corrupted");
    if (watcher->type == NSF_WTC_FLOAT)
        return *(float *)watcher->ptr;
    if (watcher->type == NSF_WTC_INT)
        return (float)nsf_watcher_get_int(watcher);
    return nsf_utils_log_zero(NSF_LOG_LVL_WARNING, NSF_WATCHER,
        __FUNCTION__, "invalid type");
}

long int nsf_watcher_get_int(nsf_watcher_t *watcher)
{
    if (NSF_UNLIKELY(!watcher))
        return nsf_utils_log_zero(NSF_LOG_LVL_ERROR, NSF_WATCHER,
            __FUNCTION__, "pointer corrupted");
    if (watcher->type == NSF_WTC_INT)
        return *(int *)watcher->ptr;
    if (watcher->type == NSF_WTC_UINT)
        return *(long unsigned int *)watcher->ptr;
    if (watcher->type == NSF_WTC_FLOAT)
        return (long int)nsf_watcher_get_float(watcher);
    if (watcher->type == NSF_WTC_CHAR)
        return (long int)nsf_watcher_get_char(watcher);
    if (watcher->type == NSF_WTC_STRING)
        return (long int)nsf_watcher_get_string(watcher);
    return nsf_utils_log_zero(NSF_LOG_LVL_WARNING, NSF_WATCHER,
        __FUNCTION__, "invalid type");
}

char nsf_watcher_get_char(nsf_watcher_t *watcher)
{
    if (NSF_UNLIKELY(!watcher))
        return nsf_utils_log_zero(NSF_LOG_LVL_ERROR, NSF_WATCHER,
            __FUNCTION__, "pointer corrupted");
    if (watcher->type == NSF_WTC_CHAR)
        return *(char *)watcher->ptr;
    if (watcher->type == NSF_WTC_INT)
        return (char)nsf_watcher_get_int(watcher);
    return nsf_utils_log_zero(NSF_LOG_LVL_WARNING, NSF_WATCHER,
        __FUNCTION__, "invalid type");
}

char *nsf_watcher_get_string(nsf_watcher_t *watcher)
{
    if (NSF_UNLIKELY(!watcher))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_WATCHER,
            __FUNCTION__, "pointer corrupted");
    if (watcher->type == NSF_WTC_STRING)
        return *(char **)watcher->ptr;
    return nsf_utils_log_null(NSF_LOG_LVL_WARNING, NSF_WATCHER, __FUNCTION__,
        "invalid type");
}
