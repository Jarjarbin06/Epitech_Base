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

#include "newcsfml/graphics/particle.h"
#include "newcsfml/graphics/sprite.h"
#include "newcsfml/systems/clock.h"
#include "newcsfml/systems/utils.h"

static void spawn_particles(nsf_particle_t *particle)
{
    nsf_single_particle_t *ptr = NULL;

    if (NSF_UNLIKELY(!particle))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_PARTICLE, __FUNCTION__,
            "pointer corrupted");
    if (particle->alive_count < particle->max_particles) {
        ptr = &particle->particles[particle->alive_count];
        *ptr = (nsf_single_particle_t){
            .position = particle->source,
            .velocity = (nsf_fvector_t){0.0f, 0.0f},
            .rotation = 0.0f,
            .lifetime = particle->max_lifetime,
            .max_lifetime = particle->max_lifetime,
            .data = nsf_sprite_get_data(particle->sprite)
        };
        particle->start_func(ptr);
        particle->alive_count++;
    }
}

static void update_particles(nsf_particle_t *particle)
{
    nsf_single_particle_t *ptr = NULL;

    if (NSF_UNLIKELY(!particle))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_PARTICLE, __FUNCTION__,
            "pointer corrupted");
    for (size_t idx = 0; idx < particle->alive_count; idx++) {
        ptr = &particle->particles[idx];
        ptr->lifetime--;
        if (ptr->lifetime <= 0) {
            *ptr = particle->particles[particle->alive_count - 1];
            particle->alive_count--;
            spawn_particles(particle);
        }
        particle->update_func(ptr);
    }
}

void nsf_particle_update(nsf_particle_t *particle)
{
    if (NSF_UNLIKELY(!particle))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_PARTICLE, __FUNCTION__,
            "pointer corrupted");
    nsf_particle_set_max_lifetime(particle, particle->max_lifetime);
    spawn_particles(particle);
    update_particles(particle);
}
