/*
** EPITECH PROJECT, 2025
** sub_includes - newcsfml_prototype.h
** File description:
** <description>
*/

// Prototype //
#ifndef NEWCSFML_P
    #define NEWCSFML_P

    #include "newcsfml_typedef.h"

    #ifndef NEWCSFML_P_BASE
        #define NEWCSFML_P_BASE
void newcsfml_show_macro(void);
void newcsfml_exist(void);
    #endif

    #ifndef P_NSF_MALLOC_ANY
        #define P_NSF_MALLOC_ANY
void *nsf_malloc_any(nsf_uint size, nsf_game *game);
    #endif

    #ifndef P_NSF_FREE_ANY
        #define P_NSF_FREE_ANY
void *nsf_free_any(void *ptr, nsf_game *game);
    #endif

    #ifndef P_NSF_AUTO_FREE
        #define P_NSF_AUTO_FREE
int nsf_auto_free(nsf_uint len, free_t free_list[], nsf_game *game);
    #endif

#endif
