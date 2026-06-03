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

#include <SFML/System/Clock.h>
#include <SFML/System/Time.h>

#include "newcsfml/systems/clock.h"
#include "newcsfml/systems/utils.h"

float nsf_clock_restart(const nsf_clock_t *clock)
{
    sfTime time = {0};

    if (NSF_UNLIKELY(!clock))
        return (float)nsf_utils_log_zero(NSF_LOG_LVL_ERROR, NSF_CLOCK,
            __FUNCTION__, "pointer corrupted");
    time = sfClock_restart(clock->clock);
    return sfTime_asSeconds(time);
}

void nsf_clock_reset(nsf_clock_t *clock)
{
    if (NSF_UNLIKELY(!clock))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_CLOCK,
            __FUNCTION__, "pointer corrupted");
    clock->accumulator = 0.0f;
}

bool nsf_clock_is_new_loop(nsf_clock_t *clock, const float seconds)
{
    if (NSF_UNLIKELY(!clock))
        return nsf_utils_log_false(NSF_LOG_LVL_ERROR, NSF_CLOCK,
            __FUNCTION__, "pointer corrupted");
    return clock->accumulator >= seconds;
}

void nsf_clock_set_new_loop(nsf_clock_t *clock, const float seconds)
{
    if (NSF_UNLIKELY(!clock))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_CLOCK,
            __FUNCTION__, "pointer corrupted");
    clock->accumulator -= seconds;
}
