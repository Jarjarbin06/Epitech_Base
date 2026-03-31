/*
** EPITECH PROJECT, 2025
** sub_includes - utils_typedef.h
** File description:
** <description>
*/

// Typedef //
#ifndef UTILS_T
    #define UTILS_T

    #include "utils_include.h"

    #ifndef UTILS_T_TYPE
        #define UTILS_T_TYPE

        #ifndef T_VOID_FUNC
            #define T_VOID_FUNC
typedef void *(*void_func_t)(void *);
        #endif

// add type typedefs here //

    #endif

    #ifndef UTILS_T_STRUCT
        #define UTILS_T_STRUCT

        #ifndef T_FREE
            #define T_FREE
typedef struct {
    bool condition;
    void *ptr;
    void_func_t free_func;
} free_t;
        #endif

// add struct typedefs here //

    #endif

#endif
