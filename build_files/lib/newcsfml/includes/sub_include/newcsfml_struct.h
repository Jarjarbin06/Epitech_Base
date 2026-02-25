/*
** EPITECH PROJECT, 2025
** sub_includes - newcsfml_prototype.h
** File description:
** <description>
*/

// Prototype //
#ifndef NEWCSFML_STRUCT
    #define NEWCSFML_STRUCT

    #include "newcsfml_typedef.h"

    #ifndef P_NSF_GAME_CREATE
        #define P_NSF_GAME_CREATE
nsf_game *nsf_game_create(void);
    #endif

    #ifndef P_NSF_GAME_DESTROY
        #define P_NSF_GAME_DESTROY
int nsf_game_destroy(nsf_game **nsf_game);
    #endif

    #ifndef P_NSF_WINDOW_CREATE
        #define P_NSF_WINDOW_CREATE
nsf_window *nsf_window_create(nsf_window_settings settings,
    char title[], nsf_window_style window_style, nsf_game *game);
    #endif

    #ifndef P_NSF_WINDOW_DESTROY
        #define P_NSF_WINDOW_DESTROY
int nsf_window_destroy(nsf_window **nsf_window, nsf_game *game);
    #endif

    #ifndef P_NSF_SPRITE_CREATE
        #define P_NSF_SPRITE_CREATE
nsf_sprite *nsf_sprite_create(const char name[], nsf_game *game);
    #endif

    #ifndef P_NSF_SPRITE_DESTROY
        #define P_NSF_SPRITE_DESTROY
int nsf_sprite_destroy(nsf_sprite **nsf_sprite, nsf_game *game);
    #endif

#endif
