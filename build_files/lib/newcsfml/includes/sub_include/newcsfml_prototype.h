/*
** EPITECH PROJECT, 2025
** sub_includes - newcsfml_prototype.h
** File description:
** <description>
*/

// Prototype //
#ifndef NEWCSFML_P
    #define NEWCSFML_P

    #include "newcsfml_define.h"
    #include "newcsfml_include.h"
    #include "newcsfml_typedef.h"

#ifndef NEWCSFML_P_BASE
    #define NEWCSFML_P_BASE
void newcsfml_show_macro(void);
void newcsfml_exist(void);
#endif

#ifndef _P_NSF_SPRITE_CREATE
    #define _P_NSF_SPRITE_CREATE
nsf_sprite *nsf_sprite_create(void);
#endif

#ifndef _P_NSF_SPRITE_DESTROY
    #define _P_NSF_SPRITE_DESTROY
void *nsf_sprite_destroy(nsf_sprite *nsf_sprite);
#endif

/* UTILS */
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
