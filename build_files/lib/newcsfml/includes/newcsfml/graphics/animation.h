/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.7
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

#ifndef NEWCSFML_ANIMATION_H
    #define NEWCSFML_ANIMATION_H

    #include <SFML/Graphics/Texture.h>
    #include <SFML/Graphics/Rect.h>

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
    #define NSF_ANIMATION "NSF_ANIMATION"

// TMP //
typedef struct nsf_game_s nsf_game_t;
typedef const char *nsf_cstr_t;
typedef sfVector2u nsf_uvector_t;
typedef unsigned int nsf_uint_t;

/// TYPEDEFS ///
typedef struct nsf_animation_s {
    sfTexture *texture;
    sfIntRect rect;
    nsf_uvector_t sheet_size;
    nsf_uvector_t sprite_size;
    nsf_uvector_t offset;
    int current_line;
    nsf_uint_t rows;
    nsf_uint_t columns;
    nsf_uint_t step;
    nsf_cstr_t name;
} nsf_animation_t;

/// PROTOTYPES ///
// MANAGE //
void nsf_animation_set_offset(nsf_animation_t *animation,
    const nsf_uvector_t offset[]);
void nsf_animation_set_step(nsf_animation_t *animation, nsf_uint_t step);
void nsf_animation_update(nsf_animation_t *animation);

// STRUCT //
nsf_animation_t *nsf_animation_create(const char path[], const char name[],
    nsf_uvector_t size[], nsf_game_t *game);
int nsf_animation_destroy(nsf_animation_t **animation, nsf_game_t *game);

#endif
