/*
** EPITECH PROJECT, 2025
** sub_includes - twlist_typedef.h
** File description:
** <description>
*/

// Typedef //
#ifndef TWODLIST_T
    #define TWODLIST_T

    #include "twodlist_include.h"

    #ifndef TWODLIST_T_TYPE
        #define TWODLIST_T_TYPE

        #ifndef T_VOID_FUNC
            #define T_VOID_FUNC
typedef void *(*void_func_t)(void *);
        #endif

// add type typedefs here //

    #endif

    #ifndef TWODLIST_T_STRUCT
        #define TWODLIST_T_STRUCT

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
