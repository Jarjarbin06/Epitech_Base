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

#ifndef NEWCSFML_MOUSE_H
    #define NEWCSFML_MOUSE_H

    #include <SFML/Window/Mouse.h>

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
    #define NSF_MOUSE "NSF_MOUSE"

/// TMP ///

/// TYPEDEFS ///
typedef enum nsf_mouse_button_e {
    NSF_MSE_UNKNOWN = -1,
    NSF_MSE_LEFT,
    NSF_MSE_RIGHT,
    NSF_MSE_MIDDLE,
    NSF_MSE_X_BTTN_1,
    NSF_MSE_X_BTTN_2,
    NSF_MSE_COUNT
} nsf_mouse_button_t;

/// PROTOTYPES ///

#endif
