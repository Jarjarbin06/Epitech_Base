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

#ifndef NEWCSFML_COLOR_H
    #define NEWCSFML_COLOR_H

    #include <SFML/Graphics/Color.h>

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
    #define NSF_COLOR "NSF_COLOR"

/// TYPEDEFS ///
typedef sfColor nsf_color_t;

/// EXTERNS ///
typedef struct {
    const nsf_color_t black;
    const nsf_color_t white;
    const nsf_color_t red;
    const nsf_color_t green;
    const nsf_color_t blue;
    const nsf_color_t yellow;
    const nsf_color_t magenta;
    const nsf_color_t cyan;
    const nsf_color_t grey;
    const nsf_color_t transparent;
} nsf_colors_shortcut_t;

extern const nsf_colors_shortcut_t nsf_color;

#endif
