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

// newcsfml.c //
void newcsfml_show_macro(void);
void newcsfml_exist(void);

/* STRUCT */
// sprite.c //
nsf_sprite *nsf_sprite_create(void);
void *nsf_sprite_destroy(nsf_sprite *nsf_sprite);

/* UTILS */
// alloc_any.c //
void *malloc_any(unsigned size);
void *free_any(void *ptr);
bool auto_free(unsigned len, free_t free_list[]);

#endif
