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

void newcsfml_exist(void);
void *nsf_malloc_any(nsf_uint_t size, nsf_game_t *game);
void *nsf_free_any(void *ptr, nsf_game_t *game);
int nsf_auto_free(nsf_uint_t len, const nsf_free_t free_list[],
    nsf_game_t *game);

#endif
