/*
** EPITECH PROJECT, 2025
** sub_includes - newcsfml_typedef.h
** File description:
** <description>
*/

// Typedef //
#ifndef NEWCSFML_EXTERN_T
    #define NEWCSFML_EXTERN_T

    #include "newcsfml_typedef.h"

    #include <stdbool.h>

    #ifndef T_NSF_GAMES
        #define T_NSF_GAMES
typedef struct nsf_game_functions_s {
    nsf_game_t *(*create)(void);
    int (*destroy)(nsf_game_t **);
    int (*display)(nsf_game_t *);
    bool (*isopen)(nsf_game_t *);
    void (*close)(nsf_game_t *);
    bool (*get_event)(nsf_game_t *, nsf_event_t *);
    void (*set_window)(nsf_game_t *, nsf_window_t *);
    nsf_window_t *(*get_window)(nsf_game_t *);
    void (*add_sprite)(nsf_game_t *, nsf_sprite_t *);
    void (*add_button)(nsf_game_t *, nsf_button_t *);
} nsf_game_functions_t;
    #endif

    #ifndef T_NSF_WINDOWS
        #define T_NSF_WINDOWS
typedef struct nsf_window_functions_s {
    nsf_window_t *(*create)(nsf_window_settings_t, char[],
        nsf_window_style_t, nsf_game_t *);
    int (*destroy)(nsf_window_t **, nsf_game_t *);
    int (*display)(nsf_window_t *);
    bool (*isopen)(nsf_window_t *);
    void (*close)(nsf_window_t *);
    bool (*get_event)(nsf_window_t *, nsf_event_t *);
    void (*fill)(const nsf_window_t *, nsf_color_t);
    void (*draw_line)(const nsf_window_t *window,
        nsf_vector, nsf_vector, nsf_color_t);
    void (*draw)(nsf_window_t *);
    void (*add_sprite)(nsf_window_t *, nsf_sprite_t *, nsf_game_t *);
    void (*add_button)(nsf_window_t *, nsf_button_t *, nsf_game_t *);
} nsf_window_functions_t;
    #endif

    #ifndef T_NSF_SPRITES
        #define T_NSF_SPRITES
typedef struct nsf_sprite_functions_s {
    nsf_sprite_t *(*create)(const char[], nsf_game_t *);
    void (*destroy)(nsf_sprite_t **, nsf_game_t *);
    void (*set_texture)(nsf_sprite_t *, nsf_texture_t *);
    void (*draw)(nsf_sprite_t *, nsf_window_t *);
} nsf_sprite_functions_t;
    #endif

    #ifndef T_NSF_TEXTURES
        #define T_NSF_TEXTURES
typedef struct nsf_texture_functions_s {
    nsf_texture_t *(*create)(const char[], const char[],
        nsf_game_t *);
    int (*destroy)(nsf_texture_t **, nsf_game_t *);
} nsf_texture_functions_t;
    #endif

    #ifndef T_NSF_EVENTS
        #define T_NSF_EVENTS
typedef struct nsf_event_functions_s {
    bool (*cmp)(const nsf_event_t *, nsf_event_type_t);
    bool (*cmp_key)(const nsf_event_t *, nsf_key_code);
} nsf_event_functions_t;
    #endif

    #ifndef T_NSF_BUTTONS
        #define T_NSF_BUTTONS
typedef struct nsf_button_functions_s {
    nsf_button_t *(*create)(const char[], nsf_game_t *);
    int (*destroy)(nsf_button_t **, nsf_game_t *);
    void (*set_texture)(nsf_button_t *, nsf_texture_t *);
    void (*set_position)(nsf_button_t *, nsf_vector);
    void (*set_size)(nsf_button_t *, nsf_vector);
    void (*set_colors)(nsf_button_t *, nsf_color_t, nsf_color_t, nsf_uint);
    bool (*check_click)(nsf_button_t *, nsf_window_t *, nsf_mouse);
    void (*draw)(nsf_button_t *, nsf_window_t *);
} nsf_button_functions_t;
    #endif

#endif
