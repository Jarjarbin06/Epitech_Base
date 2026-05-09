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

#include "newcsfml/systems/vector.h"
#include "newcsfml/graphics/texture.h"
#include "newcsfml/graphics/sprite.h"
#include "newcsfml/graphics/particle.h"
#include "newcsfml/systems/utils.h"

void nsf_particle_set_texture(nsf_particle_t *particle,
    const nsf_texture_t *texture)
{
    if (NSF_UNLIKELY(!particle || !texture))
        return;
    nsf_sprite_set_texture(particle->sprite, texture);
}

void nsf_particle_set_max_lifetime(nsf_particle_t *particle,
    const nsf_uint_t max_lifetime)
{
    if (NSF_UNLIKELY(!particle))
        return;
    particle->max_lifetime = max_lifetime;
    for (size_t idx = 0; idx < particle->max_particles; idx++)
        particle->particles[idx].max_lifetime = particle->max_lifetime;
}

void nsf_particle_set_scale(nsf_particle_t *particle,
    const nsf_fvector_t scale[])
{
    if (NSF_UNLIKELY(!particle || !scale))
        return;
    nsf_sprite_set_scale(particle->sprite, scale);
}

void nsf_particle_set_size(nsf_particle_t *particle,
    const nsf_uvector_t size[])
{
    if (NSF_UNLIKELY(!particle || !size))
        return;
    nsf_sprite_set_size(particle->sprite, size);
}

void nsf_particle_set_source(nsf_particle_t *particle,
    const nsf_fvector_t source[])
{
    if (NSF_UNLIKELY(!particle))
        return;
    nsf_fvector_copy(source, &particle->source);
}
