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

#ifndef NEWCSFML_WINDOW_SETTINGS_H
    #define NEWCSFML_WINDOW_SETTINGS_H

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
    #define NSF_WINDOW_SETTINGS "NSF_WINDOW_SETTINGS"

/// TMP ///
typedef struct nsf_game_s nsf_game_t;
typedef unsigned int nsf_uint_t;

/// TYPEDEFS ///
typedef struct nsf_window_settings_s {
    nsf_uint_t width;
    nsf_uint_t height;
    nsf_uint_t bpp;
    nsf_uint_t fps;
} nsf_window_settings_t;

/// PROTOTYPES
// STRUCT //
nsf_window_settings_t *nsf_window_settings_create(
    const nsf_window_settings_t settings[], nsf_game_t *game);
int nsf_window_settings_destroy(nsf_window_settings_t **settings,
    nsf_game_t *game);

#endif
