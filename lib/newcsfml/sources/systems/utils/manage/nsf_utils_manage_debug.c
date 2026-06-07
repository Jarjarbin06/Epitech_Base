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

#include <stdio.h>

#include "newcsfml/systems/other.h"
#include "newcsfml/systems/utils.h"

static const nsf_cstr_t log_level_terminal[] = {
    NSF_TERMINAL_UNKNOWN,
    NSF_TERMINAL_DEBUG,
    NSF_TERMINAL_INFO,
    NSF_TERMINAL_OK,
    NSF_TERMINAL_WARNING,
    NSF_TERMINAL_ERROR
};

static const nsf_cstr_t log_level_str[] = {
    NSF_TEXT_UNKNOWN,
    NSF_TEXT_DEBUG,
    NSF_TEXT_INFO,
    NSF_TEXT_OK,
    NSF_TEXT_WARNING,
    NSF_TEXT_ERROR
};

static bool is_nsf_module(const nsf_cstr_t module)
{
    for (size_t idx = 0; module[idx] != '\0' &&
        SPECIAL_STR_MODULE_NSF[idx] != '\0'; idx++)
        if (module[idx] != SPECIAL_STR_MODULE_NSF[idx])
            return false;
    return true;
}

void nsf_utils_log(const nsf_log_level_t log_level, nsf_cstr_t module,
    nsf_cstr_t name, nsf_cstr_t message)
{
    if (!module)
        module = "UNKNOWN";
    if (!name)
        name = "-";
    if (!message)
        message = "(null)";
    if (is_nsf_module(module))
        printf("[NSF-LOG] - ");
    else
        printf("[LOG] - ");
    printf("[%s%s%s] [%s] [%s] %s%s%s\n",
        log_level_terminal[log_level + 1],
        log_level_str[log_level + 1],
        NSF_TERMINAL_RESET,
        module,
        name,
        log_level_terminal[log_level + 1],
        message,
        NSF_TERMINAL_RESET);
}

void *nsf_utils_log_null(const nsf_log_level_t log_level,
    const nsf_cstr_t module, const nsf_cstr_t name, const nsf_cstr_t message)
{
    nsf_utils_log(log_level, module, name, message);
    return NULL;
}

bool nsf_utils_log_false(const nsf_log_level_t log_level,
    const nsf_cstr_t module, const nsf_cstr_t name, const nsf_cstr_t message)
{
    nsf_utils_log(log_level, module, name, message);
    return NSF_FALSE;
}

int nsf_utils_log_failure(const nsf_log_level_t log_level,
    const nsf_cstr_t module, const nsf_cstr_t name, const nsf_cstr_t message)
{
    nsf_utils_log(log_level, module, name, message);
    return E_FAILURE;
}

int nsf_utils_log_zero(const nsf_log_level_t log_level,
    const nsf_cstr_t module, const nsf_cstr_t name, const nsf_cstr_t message)
{
    nsf_utils_log(log_level, module, name, message);
    return 0;
}
