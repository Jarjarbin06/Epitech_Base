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

#include "newcsfml/graphics/sprite.h"
#include "newcsfml/graphics/particle.h"
#include "newcsfml/systems/utils.h"

void nsf_particle_set_data(nsf_particle_t *particle, void *data)
{
    if (NSF_UNLIKELY(!particle || !data))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_PARTICLE, __FUNCTION__,
            "pointer corrupted");
    nsf_sprite_set_data(particle->sprite, data);
}

void *nsf_particle_get_data(nsf_particle_t *particle)
{
    if (NSF_UNLIKELY(!particle))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_PARTICLE, __FUNCTION__,
            "pointer corrupted");
    return nsf_sprite_get_data(particle->sprite);
}
