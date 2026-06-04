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

#include "newcsfml/graphics/particle.h"
#include "newcsfml/graphics/sprite.h"
#include "newcsfml/systems/utils.h"

void nsf_particle_set_update(nsf_particle_t *particle,
    const nsf_particle_update_func_t update_func)
{
    if (NSF_UNLIKELY(!particle || !update_func))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_PARTICLE, __FUNCTION__,
            "pointer corrupted");
    particle->update_func = update_func;
}

void nsf_particle_set_start(nsf_particle_t *particle,
    const nsf_particle_start_func_t start_func)
{
    if (NSF_UNLIKELY(!particle || !start_func))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_PARTICLE, __FUNCTION__,
            "pointer corrupted");
    particle->start_func = start_func;
}

void nsf_particle_set_ups(nsf_particle_t *particle,
    const nsf_uint_t ups)
{
    if (NSF_UNLIKELY(!particle))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_PARTICLE, __FUNCTION__,
            "pointer corrupted");
    particle->ups = ups;
}
