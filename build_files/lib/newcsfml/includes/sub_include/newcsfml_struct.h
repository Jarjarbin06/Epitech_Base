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
nsf_game_t *nsf_game_create(void);
    #endif

    #ifndef P_NSF_GAME_DESTROY
        #define P_NSF_GAME_DESTROY
int nsf_game_destroy(nsf_game_t **nsf_game);
    #endif

    #ifndef P_NSF_WINDOW_CREATE
        #define P_NSF_WINDOW_CREATE
nsf_window_t *nsf_window_create(nsf_window_settings_t settings,
    char title[], nsf_window_style_t window_style, nsf_game_t *game);
    #endif

    #ifndef P_NSF_WINDOW_DESTROY
        #define P_NSF_WINDOW_DESTROY
int nsf_window_destroy(nsf_window_t **nsf_window, nsf_game_t *game);
    #endif

    #ifndef P_NSF_SPRITE_CREATE
        #define P_NSF_SPRITE_CREATE
nsf_sprite_t *nsf_sprite_create(const char name[], nsf_game_t *game);
    #endif

    #ifndef P_NSF_SPRITE_DESTROY
        #define P_NSF_SPRITE_DESTROY
int nsf_sprite_destroy(nsf_sprite_t **sprite, nsf_game_t *game);
    #endif

#endif
