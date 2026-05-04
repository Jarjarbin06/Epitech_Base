/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.2
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

#ifndef NEWCSFML_UTILS_H
    #define NEWCSFML_UTILS_H

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

    #ifndef OPTIMIZATION_D
        #define OPTIMIZATION_D

        #define NSF_LIKELY(x) __builtin_expect(!!(x), 1)
        #define NSF_UNLIKELY(x) __builtin_expect(!!(x), 0)

    #endif

/// TMP //
typedef struct nsf_game_s nsf_game_t;

/// TYPEDEFS ///
typedef unsigned int nsf_uint_t;
typedef char *nsf_str_t;
typedef const char *nsf_cstr_t;
typedef void *(*nsf_free_f_t)(void *);

typedef struct {
    const bool condition;
    void *ptr;
    void *free_func;
} nsf_free_t;

/// PROTOTYPES ///
// BASE //
void newcsfml_exist(void);

// MEMORY//
void *nsf_malloc_any(nsf_uint_t size, nsf_game_t *game);
void *nsf_free_any(void *ptr, nsf_game_t *game);
int nsf_auto_free(nsf_uint_t len, const nsf_free_t free_list[],
    nsf_game_t *game);

#endif
