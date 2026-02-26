/*
** EPITECH PROJECT, 2025
** sub_includes - newcsfml_prototype.h
** File description:
** <description>
*/

// Prototype //
#ifndef NEWCSFML_MANAGE
    #define NEWCSFML_MANAGE

    #include "newcsfml_typedef.h"

    #ifndef P_NSF_CMP_EVENT
        #define P_NSF_CMP_EVENT
bool nsf_cmp_event(const nsf_event_t *event, nsf_event_type_t event_type);
    #endif

    #ifndef P_NSF_CMP_KEY
        #define P_NSF_CMP_KEY
bool nsf_cmp_key(const nsf_event_t *event, nsf_key_code key_code);
    #endif

    #ifndef P_NSF_GAME_DISPLAY
        #define P_NSF_GAME_DISPLAY
int nsf_game_display(nsf_game_t *game);
    #endif

    #ifndef P_NSF_GAME_ISOPEN
        #define P_NSF_GAME_ISOPEN
bool nsf_game_isopen(nsf_game_t *game);
    #endif

    #ifndef P_NSF_GAME_CLOSE
        #define P_NSF_GAME_CLOSE
void nsf_game_close(nsf_game_t *game);
    #endif

    #ifndef P_NSF_GAME_GET_EVENT
        #define P_NSF_GAME_GET_EVENT
bool nsf_game_get_event(nsf_game_t *game, nsf_event_t *event);
    #endif

    #ifndef P_NSF_GAME_SET_WINDOW
        #define  P_NSF_GAME_SET_WINDOW
void nsf_game_set_window(nsf_game_t *game, nsf_window_t *window);
    #endif

    #ifndef P_NSF_WINDOW_DISPLAY
        #define P_NSF_WINDOW_DISPLAY
int nsf_window_display(nsf_window_t *nsf_window);
    #endif

    #ifndef P_NSF_WINDOW_ISOPEN
        #define P_NSF_WINDOW_ISOPEN
bool nsf_window_isopen(nsf_window_t *nsf_window);
    #endif

    #ifndef P_NSF_WINDOW_CLOSE
        #define P_NSF_WINDOW_CLOSE
void nsf_window_close(nsf_window_t *nsf_window);
    #endif

    #ifndef P_NSF_WINDOW_GET_EVENT
        #define P_NSF_WINDOW_GET_EVENT
bool nsf_window_get_event(nsf_window_t *nsf_window, nsf_event_t *event);
    #endif

    #ifndef P_NSF_SPRITE_SET_TEXTURE
        #define P_NSF_SPRITE_SET_TEXTURE
int nsf_sprite_set_texture(nsf_sprite_t *sprite, nsf_texture_t *texture);
    #endif

    #ifndef P_NSF_TEXTURE_SET_TEXTURE
        #define P_NSF_TEXTURE_SET_TEXTURE
nsf_texture_t *nsf_texture_create(const char path[], const char name[],
    nsf_game_t *game);
    #endif

    #ifndef P_NSF_TEXTURE_DRAW
        #define P_NSF_TEXTURE_DRAW
int nsf_texture_destroy(nsf_texture_t **nsf_texture, nsf_game_t *game);
    #endif

#endif
