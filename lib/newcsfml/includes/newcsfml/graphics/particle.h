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

#ifndef NEWCSFML_PARTICLE_H
    #define NEWCSFML_PARTICLE_H

    #include <SFML/System/Vector2.h>

    #include <stdbool.h>
    #include <stddef.h>

    #ifndef EXIT_D
        #define EXIT_D

        #ifndef E_SUCCESS
            #define E_SUCCESS (0)
        #endif

        #ifndef E_ERROR
            #define E_ERROR (84)
        #endif

        #ifndef E_FAILURE
            #define E_FAILURE (-1)
        #endif

    #endif

/// MACRO ///
    #define NSF_PARTICLE "NSF_PARTICLE"

/// TMP ///
typedef struct nsf_sprite_s nsf_sprite_t;
typedef sfVector2f nsf_fvector_t;
typedef sfVector2u nsf_uvector_t;
typedef struct nsf_game_s nsf_game_t;
typedef struct nsf_window_s nsf_window_t;
typedef const char *nsf_cstr_t;
typedef unsigned int nsf_uint_t;
typedef struct nsf_clock_s nsf_clock_t;
typedef struct nsf_texture_s nsf_texture_t;

/// TYPEDEFS ///
typedef struct nsf_single_particle_s {
    nsf_fvector_t position;
    nsf_fvector_t velocity;
    float rotation;
    nsf_uint_t lifetime;
    nsf_uint_t max_lifetime;
    void *data;
} nsf_single_particle_t;

typedef void (*nsf_particle_modifier_func_t)(nsf_single_particle_t *particle);
typedef nsf_particle_modifier_func_t nsf_particle_update_func_t;
typedef nsf_particle_modifier_func_t nsf_particle_start_func_t;

typedef struct nsf_particle_s {
    nsf_sprite_t *sprite;
    nsf_single_particle_t *particles;
    nsf_fvector_t source;
    size_t max_particles;
    size_t alive_count;
    nsf_particle_update_func_t update_func;
    nsf_particle_start_func_t start_func;
    nsf_uint_t max_lifetime;
    nsf_clock_t *clock;
    nsf_uint_t spawn_rate;
    nsf_cstr_t name;
} nsf_particle_t;

/// PROTOTYPES ///
// SPRITE //
nsf_particle_t *nsf_particle_create(const char name[], size_t max_particles,
    nsf_game_t *game);
int nsf_particle_destroy(nsf_particle_t **particle, nsf_game_t *game);

// MANAGE //
void nsf_particle_set_texture(nsf_particle_t *particle,
    nsf_texture_t *texture);
void nsf_particle_set_max_lifetime(nsf_particle_t *particle,
    nsf_uint_t max_lifetime);
void nsf_particle_set_scale(nsf_particle_t *particle,
    const nsf_fvector_t scale[]);
void nsf_particle_set_size(nsf_particle_t *particle,
    const nsf_uvector_t size[]);
void nsf_particle_set_source(nsf_particle_t *particle,
    const nsf_fvector_t source[]);
void nsf_particle_set_update(nsf_particle_t *particle,
    nsf_particle_update_func_t update_func);
void nsf_particle_set_start(nsf_particle_t *particle,
    nsf_particle_start_func_t start_func);
void nsf_particle_set_spawn_rate(nsf_particle_t *particle,
    nsf_uint_t spawn_rate);
void nsf_particle_update(nsf_particle_t *particle);
void nsf_particle_set_data(nsf_particle_t *particle, void *data);
void *nsf_particle_get_data(nsf_particle_t *particle);
void nsf_particle_clear(nsf_particle_t *particle);

// DRAW //
void nsf_particle_draw(const nsf_particle_t *particle,
    const nsf_window_t *window);

#endif
