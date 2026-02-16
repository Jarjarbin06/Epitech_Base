/*
** EPITECH PROJECT, 2025
** sub_includes - utils_prototype.h
** File description:
** <description>
*/

// Prototype //
#ifndef UTILS_P
    #define UTILS_P

    #include "utils_define.h"
    #include "utils_include.h"
    #include "utils_typedef.h"

#ifndef UTILS_P_BASE
    #define UTILS_P_BASE
void utils_show_macro(void);
void utils_exist(void);
#endif

#ifndef _P_MALLOC_ANY
    #define _P_MALLOC_ANY
void *malloc_any(unsigned size);
#endif

#ifndef _P_FREE_ANY
    #define _P_FREE_ANY
void *free_any(void *ptr);
#endif

#ifndef _P_AUTO_FREE
    #define _P_AUTO_FREE
bool auto_free(unsigned len, free_t free_list[]);
#endif

#endif
