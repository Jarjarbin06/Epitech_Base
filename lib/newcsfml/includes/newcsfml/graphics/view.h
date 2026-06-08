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

#ifndef NEWCSFML_VIEW_H
    #define NEWCSFML_VIEW_H

    #include <SFML/Graphics/View.h>
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
    #define NSF_VIEW "NSF_VIEW"

/// TMP ///
typedef struct nsf_game_s nsf_game_t;
typedef sfVector2f nsf_fvector_t;
typedef sfVector2u nsf_uvector_t;

/// TYPEDEFS ///
typedef struct nsf_view_s {
    sfView *view;
    nsf_fvector_t center;
    nsf_uvector_t size;
    float rotation;
} nsf_view_t;

/// PROTOTYPES ///
// STRUCT //
nsf_view_t *nsf_view_create(nsf_game_t *game);
int nsf_view_destroy(nsf_view_t **view, nsf_game_t *game);

// MANAGE //
void nsf_view_set_center(nsf_view_t *view, const nsf_fvector_t *center);
void nsf_view_set_size(nsf_view_t *view, const nsf_uvector_t *size);
nsf_fvector_t nsf_view_get_center(nsf_view_t *view);
nsf_uvector_t nsf_view_get_size(nsf_view_t *view);

#endif
