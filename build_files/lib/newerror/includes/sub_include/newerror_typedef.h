/*
** EPITECH PROJECT, 2025
** sub_includes - newerror_typedef.h
** File description:
** <description>
*/

// Typedef //
#ifndef NEWERROR_T
    #define NEWERROR_T

    #include "newerror_include.h"

    #ifndef NEWERROR_T_TYPE
        #define NEWERROR_T_TYPE

typedef char const *title_t;
typedef char const *message_t;
typedef char const *file_name_t;
typedef char const *function_t;
typedef int const line_t;
typedef bool fatal_t;

// add type typedefs here //

    #endif

    #ifndef NEWERROR_T_STRUCT
        #define NEWERROR_T_STRUCT

typedef struct {
    title_t title;
    message_t msg;
    file_name_t file;
    function_t func;
    line_t line;
    fatal_t fatal;
} err_t;

// add struct typedefs here //

    #endif

#endif
