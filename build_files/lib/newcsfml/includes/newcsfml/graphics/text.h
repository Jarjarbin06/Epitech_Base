/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.4
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

#ifndef NEWCSFML_TEXT_H
    #define NEWCSFML_TEXT_H

    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Text.h>
    #include <SFML/Graphics/Font.h>

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

// MACRO //
    #define NSF_TEXT_MAX_SIZE 4096

// TMP //
typedef unsigned int nsf_uint_t;
typedef const char *nsf_cstr_t;
typedef char *nsf_str_t;
typedef sfVector2f nsf_fvector_t;
typedef sfColor nsf_color_t;
typedef struct nsf_game_s nsf_game_t;
typedef struct nsf_window_s nsf_window_t;
typedef struct nsf_watcher_s nsf_watcher_t;

/// TYPEDEFS ///
typedef struct nsf_text_s {
    sfText *text;
    const sfFont *font;
    nsf_fvector_t postition;
    nsf_fvector_t origin;
    nsf_uint_t size;
    float rotation;
    nsf_watcher_t *watcher;
    nsf_color_t color;
    nsf_cstr_t name;
    char buffer[NSF_TEXT_MAX_SIZE];
} nsf_text_t;

/// PROTOTYPES ///
// STRUCT //
nsf_text_t *nsf_text_create(const char name[], const char font_path[],
    nsf_game_t *game);
int nsf_text_destroy(nsf_text_t **text, nsf_game_t *game);

// MANAGE //
void nsf_text_set_string(nsf_text_t *text, const char string[]);
void nsf_text_set_size(nsf_text_t *text, nsf_uint_t size);
void nsf_text_set_position(nsf_text_t *text, const nsf_fvector_t position[]);
void nsf_text_set_color(nsf_text_t *text, const nsf_color_t color[]);
void nsf_text_set_watcher(nsf_text_t *text, nsf_watcher_t *watcher);
nsf_watcher_t *nsf_text_get_watcher(nsf_text_t *text);
void nsf_text_update_from_watcher(nsf_text_t *text);

// DRAW //
void nsf_text_draw(const nsf_text_t *text, const nsf_window_t *window);

#endif
