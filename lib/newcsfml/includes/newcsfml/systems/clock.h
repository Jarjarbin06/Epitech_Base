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

#ifndef NEWCSFML_CLOCK_H
    #define NEWCSFML_CLOCK_H

    #include <SFML/System/Time.h>
    #include <SFML/System/Clock.h>
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
    #define NSF_CLOCK "NSF_CLOCK"

/// TMP ///
typedef const char *nsf_cstr_t;
typedef struct nsf_game_s nsf_game_t;

/// TYPEDEFS ///
typedef struct nsf_clock_s {
    sfClock *clock;
    float last;
    float delta;
    float accumulator;
    nsf_cstr_t name;
} nsf_clock_t;

/// PROTOTYPES ///
// STRUCT //
nsf_clock_t *nsf_clock_create(const char name[], nsf_game_t *game);
int nsf_clock_destroy(nsf_clock_t **clock, nsf_game_t *game);

// MANAGE //
float nsf_clock_restart(const nsf_clock_t *clock);
float nsf_clock_get_elapsed(const nsf_clock_t *clock);
float nsf_clock_get_delta(const nsf_clock_t *clock);
void nsf_clock_update(nsf_clock_t *clock);
void nsf_clock_reset(nsf_clock_t *clock);
bool nsf_clock_is_new_loop(nsf_clock_t *clock, float seconds);
void nsf_clock_set_new_loop(nsf_clock_t *clock, float seconds);

#endif
