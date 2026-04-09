/*
** EPITECH PROJECT, 2025
** sub_includes - llist_prototype.h
** File description:
** <description>
*/

// Prototype //
#ifndef LLIST_P
    #define LLIST_P

    #include "llist_include.h"
    #include "llist_typedef.h"

    #ifndef LLIST_P_BASE
        #define LLIST_P_BASE
void llist_exist(void);
    #endif

/* OTHER LIB */
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
void *free_array(void **array);
    #endif

#endif
