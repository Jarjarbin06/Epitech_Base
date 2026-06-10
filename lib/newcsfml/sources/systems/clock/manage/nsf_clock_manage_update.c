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

#include <SFML/System/Clock.h>
#include <SFML/System/Time.h>

#include "newcsfml/systems/clock.h"
#include "newcsfml/systems/utils.h"

void nsf_clock_update(nsf_clock_t *clock)
{
    float current = 0;
    float last = 0.0f;

    if (NSF_UNLIKELY(!clock))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_CLOCK,
            __FUNCTION__, "pointer corrupted");
    last = clock->last;
    current = sfTime_asSeconds(sfClock_getElapsedTime(clock->clock));
    clock->delta = current - last;
    clock->last = current;
    clock->accumulator += clock->delta;
}
