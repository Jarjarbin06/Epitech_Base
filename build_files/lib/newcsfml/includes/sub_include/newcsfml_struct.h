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
int nsf_game_destroy(nsf_game_t **game);
    #endif

    #ifndef P_NSF_WINDOW_CREATE
        #define P_NSF_WINDOW_CREATE
nsf_window_t *nsf_window_create(nsf_window_settings_t settings,
    char title[], nsf_window_style_t window_style, nsf_game_t *game);
    #endif

    #ifndef P_NSF_WINDOW_DESTROY
        #define P_NSF_WINDOW_DESTROY
int nsf_window_destroy(nsf_window_t **window, nsf_game_t *game);
    #endif

    #ifndef P_NSF_SPRITE_CREATE
        #define P_NSF_SPRITE_CREATE
nsf_sprite_t *nsf_sprite_create(const char name[], nsf_game_t *game);
    #endif

    #ifndef P_NSF_SPRITE_DESTROY
        #define P_NSF_SPRITE_DESTROY
void nsf_sprite_destroy(nsf_sprite_t **sprite, nsf_game_t *game);
    #endif

    #ifndef P_NSF_TEXTURE_CREATE
        #define P_NSF_TEXTURE_CREATE
nsf_texture_t *nsf_texture_create(const char path[], const char name[],
    nsf_game_t *game);
    #endif

    #ifndef P_NSF_TEXTURE_DESTROY
        #define P_NSF_TEXTURE_DESTROY
int nsf_texture_destroy(nsf_texture_t **texture, nsf_game_t *game);
    #endif

    #ifndef P_NSF_BUTTON_CREATE
        #define P_NSF_BUTTON_CREATE
nsf_button_t *nsf_button_create(const char name[], nsf_game_t *game);
    #endif

    #ifndef P_NSF_BUTTON_DESTROY
        #define P_NSF_BUTTON_DESTROY
int nsf_button_destroy(nsf_button_t **button, nsf_game_t *game);
    #endif

#endif
