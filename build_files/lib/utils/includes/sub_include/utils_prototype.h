/*
** EPITECH PROJECT, 2025
** sub_includes - utils_prototype.h
** File description:
** <description>
*/

// Prototype //
#ifndef UTILS_P
    #define UTILS_P

    #include "utils_include.h"
    #include "utils_typedef.h"

    #ifndef UTILS_P_BASE
        #define UTILS_P_BASE
void utils_show_macro(void);
void utils_exist(void);
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
void free_array(void **array);
    #endif

#endif
