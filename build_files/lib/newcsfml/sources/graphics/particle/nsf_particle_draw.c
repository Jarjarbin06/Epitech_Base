/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.5
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
#include "newcsfml/graphics/particle.h"
#include "newcsfml/graphics/sprite.h"
#include "newcsfml/systems/utils.h"
#include "newcsfml/systems/vector.h"
#include "newcsfml/systems/clock.h"

static void update_and_draw_every_particles(const nsf_particle_t *particle,
    const nsf_window_t *window)
{
    nsf_single_particle_t *current_particle = NULL;

    for (size_t idx = 0; idx < particle->alive_count; idx++) {
        current_particle = &particle->particles[idx];
        nsf_vector_add(&current_particle->position,
            &current_particle->velocity, &current_particle->position);
        nsf_sprite_set_position(particle->sprite,
            &current_particle->position);
        nsf_sprite_draw(particle->sprite, window);
    }
}

void nsf_particle_draw(const nsf_particle_t *particle,
    const nsf_window_t *window)
{
    float seconds = 0.0f;

    if (NSF_UNLIKELY(!particle || !window))
        return;
    seconds = 1.0f / particle->ups;
    nsf_clock_update(particle->clock);
    if (nsf_clock_is_new_loop(particle->clock, seconds)) {
        nsf_clock_set_new_loop(particle->clock, seconds);
        nsf_particle_update((nsf_particle_t *)particle);
    }
    update_and_draw_every_particles(particle, window);
}
