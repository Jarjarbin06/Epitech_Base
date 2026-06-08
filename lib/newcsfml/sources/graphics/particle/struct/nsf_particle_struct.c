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

#include "newcsfml/games/game.h"
#include "newcsfml/graphics/sprite.h"
#include "newcsfml/graphics/texture.h"
#include "newcsfml/graphics/particle.h"
#include "newcsfml/systems/vector.h"
#include "newcsfml/systems/other.h"
#include "newcsfml/systems/utils.h"
#include "newcsfml/systems/clock.h"

static int init_particles(nsf_particle_t *new_particle, nsf_game_t *game)
{
    if (NSF_UNLIKELY(!new_particle || !new_particle->max_particles))
        return nsf_utils_log_failure(NSF_LOG_LVL_ERROR, NSF_PARTICLE,
            __FUNCTION__, "pointer corrupted");
    new_particle->particles = malloc_any(
        sizeof(nsf_single_particle_t) * new_particle->max_particles);
    if (NSF_UNLIKELY(!new_particle->particles))
        return nsf_utils_log_failure(NSF_LOG_LVL_ERROR, NSF_PARTICLE,
            __FUNCTION__, "alloc failed");
    for (size_t idx = 0; idx < new_particle->max_particles; idx++)
        new_particle->particles[idx] = (nsf_single_particle_t){
            .position = (nsf_fvector_t){0.0f, 0.0f},
            .velocity = (nsf_fvector_t){0.0f, 0.0f},
            .rotation = 0.0f,
            .lifetime = 0,
            .max_lifetime = new_particle->max_lifetime,
        };
    if (game)
        game->allocations++;
    return E_SUCCESS;
}

static void base_func(nsf_single_particle_t *particle)
{
    if (NSF_UNLIKELY(!particle))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_PARTICLE, __FUNCTION__,
            "pointer corrupted");
}

static void init_values(nsf_particle_t *new_particle,
    const size_t max_particles)
{
    if (NSF_UNLIKELY(!new_particle))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_PARTICLE, __FUNCTION__,
            "pointer corrupted");
    new_particle->max_particles = max_particles;
    new_particle->max_lifetime = 0;
    new_particle->alive_count = 0;
    new_particle->ups = 0;
    new_particle->source = (nsf_fvector_t){0.0f, 0.0f};
}

nsf_particle_t *nsf_particle_create(const char name[],
    const size_t max_particles, nsf_game_t *game)
{
    nsf_particle_t *new_particle = malloc_any(sizeof(nsf_particle_t));
    nsf_sprite_t *nsf_sprite = nsf_sprite_create(name, game);
    const nsf_cstr_t particle_name = str_dup(name);

    if (NSF_UNLIKELY(!new_particle || !nsf_sprite || !particle_name))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_PARTICLE,
            __FUNCTION__, "alloc failed");
    init_values(new_particle, max_particles);
    if (NSF_UNLIKELY(init_particles(new_particle, game)))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_PARTICLE,
            __FUNCTION__, "particles initialization failed");
    new_particle->sprite = nsf_sprite;
    new_particle->name = particle_name;
    new_particle->start_func = base_func;
    new_particle->update_func = base_func;
    new_particle->clock = nsf_clock_create(name, game);
    if (game)
        game->allocations += 2;
    return new_particle;
}

static void destroy_particles(nsf_particle_t *particle, nsf_game_t *game)
{
    if (NSF_UNLIKELY(!particle || !particle->particles))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_PARTICLE, __FUNCTION__,
            "pointer corrupted");
    free_any(particle->particles);
    if (game)
        game->allocations++;
}

int nsf_particle_destroy(nsf_particle_t **particle, nsf_game_t *game)
{
    if (NSF_UNLIKELY(!particle || !*particle))
        return nsf_utils_log_failure(NSF_LOG_LVL_ERROR, NSF_PARTICLE,
            __FUNCTION__, "pointer corrupted");
    if (NSF_LIKELY((*particle)->particles))
        destroy_particles(*particle, game);
    if (NSF_LIKELY((*particle)->sprite))
        nsf_sprite_destroy(&(*particle)->sprite, game);
    if (NSF_LIKELY((*particle)->name))
        free_any((nsf_str_t)(*particle)->name);
    *particle = free_any(*particle);
    if (game)
        game->allocations -= 2;
    return E_SUCCESS;
}
