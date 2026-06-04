/*
** EPITECH PROJECT, 2025
** sub_includes - file_typedef.h
** File description:
** <description>
*/

// Typedef //
#ifndef FLAG_T
    #define FLAG_T

    #include "flag_include.h"

    #ifndef FLAG_T_TYPE
        #define FLAG_T_TYPE

        #ifndef T_VOID_FUNC
            #define T_VOID_FUNC
typedef void *(*void_func_t)(void *);
        #endif

// add type typedefs here //

    #endif

    #ifndef FLAG_T_STRUCT
        #define FLAG_T_STRUCT

        #ifndef T_FLAG_SET
            #define T_FLAG_SET
typedef struct {
    char *name;
    char simple;
    char *advanced;
    bool need_value;
    const char *base_value;
    const bool batch_end;
} flag_set_t;
        #endif

        #ifndef T_FLAG
            #define T_FLAG
typedef struct {
    char *name;
    char simple;
    char *advanced;
    bool active;
    bool need_value;
    char *value;
    bool is_loaded;
} flag_t;
        #endif

        #ifndef T_FLAGS
            #define T_FLAGS
typedef struct {
    flag_t *flags;
    size_t loaded;
    size_t size;
    size_t max_size;
} flags_t;
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
