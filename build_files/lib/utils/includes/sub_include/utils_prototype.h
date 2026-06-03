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
void utils_exist(void);
    #endif

    #ifndef P_UTILS_MALLOC
        #define P_UTILS_MALLOC
void *utils_malloc(unsigned size);
    #endif

    #ifndef P_UTILS_FREE
        #define P_UTILS_FREE
void *utils_free(void *ptr);
    #endif

    #ifndef P_UTILS_FREE_BATCH
        #define P_UTILS_FREE_BATCH
int utils_free_batch(unsigned len, free_t free_list[]);
    #endif

    #ifndef P_UTILS_FREE_ARRAY
        #define P_UTILS_FREE_ARRAY
void *utils_free_array(void **array);
    #endif

#endif
