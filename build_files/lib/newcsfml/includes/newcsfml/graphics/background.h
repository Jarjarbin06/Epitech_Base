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

#ifndef NEWCSFML_BACKGROUND_H
    #define NEWCSFML_BACKGROUND_H

    #include <stdbool.h>
    #include <stddef.h>

    #ifndef EXIT_D
        #define EXIT_D

        #ifndef EXIT_SUCCESS
            #define EXIT_SUCCESS 0
        #endif

        #ifndef EXIT_ERROR
            #define EXIT_ERROR 84
        #endif

    #endif

/// TMP ///
typedef struct nsf_sprite_s nsf_sprite_t;
typedef struct nsf_texture_s nsf_texture_t;
typedef struct nsf_game_s nsf_game_t;
typedef struct nsf_window_s nsf_window_t;

/// TYPEDEFS ///
typedef struct nsf_background_s {
    nsf_sprite_t *sprite;
    nsf_texture_t *texture;
    // add effects later
} nsf_background_t;

/// PROTOTYPES ///
// STRUCT //
nsf_background_t *nsf_background_create(const char path[],
    const nsf_window_t *window, nsf_game_t *game);
int nsf_background_destroy(nsf_background_t **background, nsf_game_t *game);

// DRAW //
void nsf_background_draw(const nsf_background_t *background,
    const nsf_window_t *window);

#endif
