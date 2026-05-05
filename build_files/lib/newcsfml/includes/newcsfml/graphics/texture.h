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

#ifndef NEWCSFML_TEXTURE_H
    #define NEWCSFML_TEXTURE_H

    #include <SFML/Graphics/Texture.h>

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

// TMP //
typedef struct nsf_game_s nsf_game_t;
typedef const char *nsf_cstr_t;

/// TYPEDEFS ///
typedef struct nsf_texture_s {
    sfTexture *texture;
    nsf_cstr_t name;
} nsf_texture_t;

/// PROTOTYPES ///
// STRUCT //
nsf_texture_t *nsf_texture_create(const char path[], const char name[],
    nsf_game_t *game);
int nsf_texture_destroy(nsf_texture_t **texture, nsf_game_t *game);

#endif
