/*
** EPITECH PROJECT, 2025
** sub_includes - twodlist_prototype.h
** File description:
** <description>
*/

// Prototype //
#ifndef TWODLIST_P
    #define TWODLIST_P

    #include "twodlist_define.h"
    #include "twodlist_include.h"
    #include "twodlist_typedef.h"

#ifndef TWODLIST_P_BASE
    #define TWODLIST_P_BASE
void twodlist_show_macro(void);
void twodlist_exist(void);
#endif

/* UTILS */
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
bool auto_free(unsigned len, free_t free_list[]);
#endif

#ifndef P_FREE_ARRAY
    #define P_FREE_ARRAY
void free_array(void **array);
#endif

#endif
