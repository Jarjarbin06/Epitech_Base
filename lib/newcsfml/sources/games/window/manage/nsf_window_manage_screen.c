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

#include "newcsfml/games/window.h"
#include "newcsfml/systems/other.h"
#include "newcsfml/systems/utils.h"

void nsf_window_add_screen(nsf_window_t *window, const nsf_cstr_t screen_name)
{
    if (NSF_UNLIKELY(!window || !screen_name))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
            "pointer corrupted");
    if (NSF_UNLIKELY(window->screen_len >= MAX_SCREENS))
        return nsf_utils_log(NSF_LOG_LVL_WARNING, NSF_WINDOW, __FUNCTION__,
            "max screens amount reached");
    for (size_t idx = 0; idx < window->screen_len; idx++)
        if (!str_cmp(window->screens[idx], screen_name))
            return nsf_utils_log(NSF_LOG_LVL_WARNING, NSF_WINDOW, __FUNCTION__,
                "screen already exists");
    window->screens[window->screen_len] = str_dup(screen_name);
    window->screen_len++;
}

int nsf_window_set_screen(nsf_window_t *window, const nsf_cstr_t screen_name)
{
    if (NSF_UNLIKELY(!window))
        return nsf_utils_log_failure(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
            "pointer corrupted");
    if (NSF_UNLIKELY(!screen_name)) {
        window->current_screen = -1;
        return E_SUCCESS;
    }
    for (size_t idx = 0; idx < window->screen_len; idx++)
        if (!str_cmp(window->screens[idx], screen_name)) {
            window->current_screen = idx;
            return E_SUCCESS;
        }
    return nsf_utils_log_failure(NSF_LOG_LVL_WARNING, NSF_WINDOW, __FUNCTION__,
        "screen doesn't exist");
}

int nsf_window_get_screen_idx(nsf_window_t *window)
{
    if (NSF_UNLIKELY(!window))
        return nsf_utils_log_failure(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
            "pointer corrupted");
    return window->current_screen;
}

nsf_cstr_t nsf_window_get_screen_name(nsf_window_t *window)
{
    if (NSF_UNLIKELY(!window))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
            "pointer corrupted");
    return window->screens[nsf_window_get_screen_idx(window)];
}
