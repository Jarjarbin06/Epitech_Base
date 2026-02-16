/*
** EPITECH PROJECT, 2025
** sub_includes - str_typedef.h
** File description:
** <description>
*/

// Typedef //
#ifndef STR_T
    #define STR_T

    #include "str_include.h"

#ifndef STR_T_TYPE
    #define STR_T_TYPE

#ifndef T_VOID_FUNC
    #define T_VOID_FUNC
typedef void *(*void_func)(void *);
#endif

    // add type typedefs here //

#endif

#ifndef STR_T_STRUCT
    #define STR_T_STRUCT

#ifndef T_FREE
    #define T_FREE
typedef struct free_s {
    bool condition;
    void *ptr;
    void_func free_func;
} free_t;
#endif

    // add struct typedefs here //

#endif

#endif
