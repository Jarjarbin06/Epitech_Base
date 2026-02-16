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

/* STRUCT */
#ifndef P_NSF_SPRITE_CREATE
    #define P_NSF_SPRITE_CREATE
nsf_sprite *nsf_sprite_create(const char name[]);
#endif

#ifndef P_NSF_SPRITE_DESTROY
    #define P_NSF_SPRITE_DESTROY
int nsf_sprite_destroy(nsf_sprite **nsf_sprite);
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
void free_array(void **array);
#endif

#ifndef P_MY_STRDUP
    #define P_MY_STRDUP
char *my_strdup(const char *src);
#endif

#ifndef P_MY_STRLEN
    #define P_MY_STRLEN
int my_strlen(const char *str);
#endif

#endif
