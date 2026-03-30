/*
** EPITECH PROJECT, 2025
** sub_includes - llist_typedef.h
** File description:
** <description>
*/

// Typedef //
#ifndef LLIST_T
    #define LLIST_T

    #include "llist_include.h"

    #ifndef LLIST_T_TYPE
        #define LLIST_T_TYPE

        #ifndef T_VOID_FUNC
            #define T_VOID_FUNC
typedef void *(*void_func_t)(void *);
        #endif

// add type typedefs here //

    #endif

    #ifndef LLIST_T_STRUCT
        #define LLIST_T_STRUCT

        #ifndef T_FREE
            #define T_FREE
typedef struct free_s {
    bool condition;
    void *ptr;
    void_func_t free_func;
} free_t;
        #endif

// add struct typedefs here //

    #endif

#endif
