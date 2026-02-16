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

#ifndef _T_VOID_FUNC
    #define _T_VOID_FUNC
typedef void *(*void_func)(void *);
#endif

// add type typedefs here //

#endif

#ifndef UTILS_T_STRUCT
    #define UTILS_T_STRUCT

#ifndef _T_FREE
    #define _T_FREE
typedef struct free_s {
    bool condition;
    void *ptr;
    void_func free_func;
} free_t;
#endif

// add struct typedefs here //

#endif

#endif
