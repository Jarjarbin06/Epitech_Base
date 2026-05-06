/*
** EPITECH PROJECT, 2025
** sub_includes - file_typedef.h
** File description:
** <description>
*/

// Typedef //
#ifndef FILE_T
    #define FILE_T

    #include <stdio.h>

    #include "file_include.h"

    #ifndef FILE_T_TYPE
        #define FILE_T_TYPE

        #ifndef T_VOID_FUNC
            #define T_VOID_FUNC
typedef void *(*void_func_t)(void *);
        #endif

        #ifndef T_CC
            #define T_CC
typedef const char cc_t;
        #endif

        #ifndef T_STR
            #define T_STR
typedef char *str_t;
        #endif

        #ifndef T_CSTR
            #define T_CSTR
typedef const char *cstr_t;
        #endif

// add type typedefs here //

    #endif

    #ifndef FILE_T_STRUCT
        #define FILE_T_STRUCT

        #ifndef T_RIGHTS
            #define T_RIGHTS
typedef struct rights_s {
    bool read;
    bool write;
    bool execute;
} rights_t;
        #endif

        #ifndef T_FILE
            #define T_FILE
typedef struct file_s {
    FILE *fd;
    char *full_path;
    char *path;
    char *name;
    size_t size;
    bool is_open;
    rights_t rights;
    char *raw;
} file_t;
        #endif

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
