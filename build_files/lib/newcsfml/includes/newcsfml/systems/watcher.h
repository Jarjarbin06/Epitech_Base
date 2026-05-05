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

#ifndef NEWCSFML_WATCHER_H
    #define NEWCSFML_WATCHER_H

    #include <SFML/System/Vector2.h>

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
typedef struct nsf_game_s nsf_game_t;

/// TYPEDEFS ///
typedef enum {
    NSF_WTC_UNKNOWN = -1,
    NSF_WTC_FLOAT,
    NSF_WTC_INT,
    NSF_WTC_CHAR,
    NSF_WTC_STRING
} nsf_watcher_type_t;

typedef struct nsf_watcher_s {
    void *ptr;
    nsf_watcher_type_t type;
} nsf_watcher_t;

/// PROTOTYPES ///
// STRUCT //
nsf_watcher_t *nsf_watcher_create(void *ptr, nsf_watcher_type_t type,
    nsf_game_t *game);
int nsf_watcher_destroy(nsf_watcher_t **watcher, nsf_game_t *game);

// MANAGE //
float nsf_watcher_get_float(nsf_watcher_t *watcher);
long int nsf_watcher_get_int(nsf_watcher_t *watcher);
char nsf_watcher_get_char(nsf_watcher_t *watcher);
char *nsf_watcher_get_string(nsf_watcher_t *watcher);
int nsf_watcher_get_string_in_buffer(nsf_watcher_t *watcher, char buffer[]);

#endif
