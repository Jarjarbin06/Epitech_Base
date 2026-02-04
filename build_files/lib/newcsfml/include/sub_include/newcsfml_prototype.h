/*
** EPITECH PROJECT, 2025
** sub_include - newcsfml_prototype.h
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

/* UTILS */
// alloc_any.c //
void *malloc_any(int size);
void free_any(void *ptr);
void auto_free(int len, free_t free_list[]);

#endif
