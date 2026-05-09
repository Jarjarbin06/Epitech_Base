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

#ifndef NEWCSFML_OTHER_H
    #define NEWCSFML_OTHER_H

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

// LIB UTILS //
    #ifndef T_VOID_FUNC
        #define T_VOID_FUNC
typedef void *(*void_func_t)(void *);
    #endif

    #ifndef T_FREE
        #define T_FREE
typedef struct {
    bool condition;
    void *ptr;
    void_func_t free_func;
} free_t;
    #endif

    #ifndef P_MALLOC_ANY
        #define P_MALLOC_ANY
void *malloc_any(unsigned size);
    #endif

    #ifndef P_FREE_ANY
        #define P_FREE_ANY
void *free_any(void *ptr);
    #endif

    #ifndef P_AUTO_FREE
        #define P_AUTO_FREE
int auto_free(unsigned len, free_t free_list[]);
    #endif

    #ifndef P_FREE_ARRAY
        #define P_FREE_ARRAY
void *free_array(void **array);
    #endif

// LIB STR //
    #ifndef T_STR
        #define T_STR
typedef char *str_t;
    #endif

    #ifndef T_CSTR
        #define T_CSTR
typedef const char *cstr_t;
    #endif

    #ifndef T_CC
        #define T_CC
typedef const char cc_t;
    #endif

    #ifndef P_STR_DUP
        #define P_STR_DUP
str_t str_dup(cstr_t src);
    #endif

    #ifndef P_STR_LEN
        #define P_STR_LEN
int str_len(cstr_t string);
    #endif

    #ifndef P_STR_CMP
        #define P_STR_CMP
int str_cmp(cstr_t str1, cstr_t str2);
    #endif

#endif
