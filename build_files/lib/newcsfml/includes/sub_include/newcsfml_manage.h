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

    #ifndef P_NSF_GAME_GET_WINDOW
        #define  P_NSF_GAME_GET_WINDOW
nsf_window_t *nsf_game_get_window(nsf_game_t *game);
    #endif

    #ifndef P_NSF_GAME_ADD_SPRITE
        #define  P_NSF_GAME_ADD_SPRITE
void nsf_game_add_sprite(nsf_game_t *game, nsf_sprite_t *sprite);
    #endif

    #ifndef P_NSF_GAME_ADD_BUTTON
        #define  P_NSF_GAME_ADD_BUTTON
void nsf_game_add_button(nsf_game_t *game, nsf_button_t *button);
    #endif

    #ifndef P_NSF_GAME_GET_SPRITE
        #define  P_NSF_GAME_GET_SPRITE
nsf_sprite_t *nsf_game_get_sprite(nsf_game_t *game, const char sprite_name[]);
    #endif

    #ifndef P_NSF_GAME_GET_BUTTON
        #define  P_NSF_GAME_GET_BUTTON
nsf_button_t *nsf_game_get_button(nsf_game_t *game, const char sprite_name[]);
    #endif

    #ifndef P_NSF_WINDOW_DISPLAY
        #define P_NSF_WINDOW_DISPLAY
int nsf_window_display(nsf_window_t *window);
    #endif

    #ifndef P_NSF_WINDOW_ISOPEN
        #define P_NSF_WINDOW_ISOPEN
bool nsf_window_isopen(nsf_window_t *window);
    #endif

    #ifndef P_NSF_WINDOW_CLOSE
        #define P_NSF_WINDOW_CLOSE
void nsf_window_close(nsf_window_t *window);
    #endif

    #ifndef P_NSF_WINDOW_GET_EVENT
        #define P_NSF_WINDOW_GET_EVENT
bool nsf_window_get_event(nsf_window_t *window, nsf_event_t *event);
    #endif

    #ifndef P_NSF_WINDOW_ADD_SPRITE
        #define P_NSF_WINDOW_ADD_SPRITE
void nsf_window_add_sprite(nsf_window_t *window, nsf_sprite_t *sprite,
    nsf_game_t *game);
    #endif

    #ifndef P_NSF_WINDOW_ADD_BUTTON
        #define P_NSF_WINDOW_ADD_BUTTON
void nsf_window_add_button(nsf_window_t *window, nsf_button_t *button,
    nsf_game_t *game);
    #endif

    #ifndef P_NSF_WINDOW_GET_SPRITE
        #define P_NSF_WINDOW_GET_SPRITE
nsf_sprite_t *nsf_window_get_sprite(nsf_window_t *window,
    const char sprite_name[]);
    #endif

    #ifndef P_NSF_WINDOW_GET_BUTTON
        #define P_NSF_WINDOW_GET_BUTTON
nsf_button_t *nsf_window_get_button(nsf_window_t *window,
    const char button_name[]);
    #endif

    #ifndef P_NSF_SPRITE_SET_TEXTURE
        #define P_NSF_SPRITE_SET_TEXTURE
void nsf_sprite_set_texture(nsf_sprite_t *sprite, nsf_texture_t *texture);
    #endif

    #ifndef P_NSF_BUTTON_SET_TEXTURE
        #define P_NSF_BUTTON_SET_TEXTURE
void nsf_button_set_texture(nsf_button_t *button, nsf_texture_t *texture);
    #endif

    #ifndef P_NSF_BUTTON_SET_POSITION
        #define P_NSF_BUTTON_SET_POSITION
void nsf_button_set_position(nsf_button_t *button, nsf_vector position);
    #endif

    #ifndef P_NSF_BUTTON_SET_SIZE
        #define P_NSF_BUTTON_SET_SIZE
void nsf_button_set_size(nsf_button_t *button, nsf_vector size);
    #endif

    #ifndef P_NSF_BUTTON_SET_COLORS
        #define P_NSF_BUTTON_SET_COLORS
void nsf_button_set_colors(nsf_button_t *button,
    nsf_color_t fill_color, nsf_color_t outline_color,
    nsf_uint outline_thickness);
    #endif

    #ifndef P_NSF_BUTTON_CHECK_CLICK
        #define P_NSF_BUTTON_CHECK_CLICK
bool nsf_button_isclicked(nsf_button_t *button, nsf_window_t *window,
    nsf_mouse mouse_button);
    #endif

#endif
