/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.3
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

#include <SFML/System/Clock.h>
#include <SFML/System/Time.h>

#include "newcsfml/systems/clock.h"
#include "newcsfml/systems/utils.h"

float nsf_clock_restart(const nsf_clock_t *clock)
{
    sfTime time = {};

    if (NSF_UNLIKELY(!clock))
        return 0.0f;
    time = sfClock_restart(clock->clock);
    return sfTime_asSeconds(time);
}

float nsf_clock_get_elapsed(const nsf_clock_t *clock)
{
    if (NSF_UNLIKELY(!clock))
        return 0.0f;
    return sfTime_asSeconds(sfClock_getElapsedTime(clock->clock));
}

float nsf_clock_get_delta(const nsf_clock_t *clock)
{
    if (NSF_UNLIKELY(!clock))
        return 0.0f;
    return clock->delta;
}
