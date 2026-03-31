/*
** EPITECH PROJECT, 2025
** sub_includes - error_typedef.h
** File description:
** <description>
*/

// Typedef //
#ifndef ERROR_T
    #define ERROR_T

    #include "error_include.h"

    #ifndef ERROR_T_TYPE
        #define ERROR_T_TYPE

typedef char const *title_t;
typedef char const *message_t;
typedef char const *file_t;
typedef char const *function_t;
typedef int const line_t;
typedef bool fatal_t;

// add type typedefs here //

    #endif

    #ifndef ERROR_T_STRUCT
        #define ERROR_T_STRUCT

typedef struct {
    title_t title;
    message_t msg;
    file_t file;
    function_t func;
    line_t line;
    fatal_t fatal;
} err_t;

// add struct typedefs here //

    #endif

#endif
