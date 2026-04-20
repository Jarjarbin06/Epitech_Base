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

    #ifndef  T_NSF_EXT_GAMES
        #define  T_NSF_EXT_GAMES
typedef struct {
    // BASE //
    nsf_game_t *(*create)(void);
    int (*destroy)(nsf_game_t **);
    int (*display)(nsf_game_t *);
    bool (*is_open)(nsf_game_t *);
    void (*close)(nsf_game_t *);
    // EVENT //
    bool (*get_event)(nsf_game_t *, nsf_event_t *);
    // WINDOW //
    void (*set_window)(nsf_game_t *, nsf_window_t *);
    nsf_window_t *(*get_window)(nsf_game_t *);
    // ELEMENT //
    void (*add_sprite)(nsf_game_t *, nsf_sprite_t *);
    void (*add_button)(nsf_game_t *, nsf_button_t *);
    void (*add_sound)(nsf_game_t *, nsf_sound_t *);
    nsf_sprite_t *(*get_sprite)(nsf_game_t *, const char[]);
    nsf_button_t *(*get_button)(nsf_game_t *, const char[]);
    nsf_sound_t *(*get_sound)(nsf_game_t *, const char[]);
    // SOUND //
    int (*play_sound)(nsf_game_t *, const char[]);
    int (*pause_sound)(nsf_game_t *, const char[]);
    int (*stop_sound)(nsf_game_t *, const char[]);
    int (*volume_all_sound)(nsf_game_t *, float);
    int (*stop_all_sound)(nsf_game_t *);
    // MUSIC //
    void (*set_music)(nsf_game_t *, nsf_music_t *);
    nsf_music_t *(*get_music)(nsf_game_t *);
    void (*play_music)(nsf_game_t *);
    void (*stop_music)(nsf_game_t *);
    void (*volume_music)(nsf_game_t *, float);
    // DRAW //
    void (*draw)(nsf_game_t *);
    // SPECIAL //
    int (*update)(nsf_game_t *);
} nsf_game_functions_t;
    #endif

    #ifndef  T_NSF_EXT_WINDOWS
        #define  T_NSF_EXT_WINDOWS
typedef struct {
    // BASE //
    nsf_window_t *(*create)(const nsf_window_settings_t[], char[],
        nsf_window_style_t, nsf_game_t *);
    int (*destroy)(nsf_window_t **, nsf_game_t *);
    int (*display)(nsf_window_t *);
    bool (*is_open)(nsf_window_t *);
    void (*close)(nsf_window_t *);
    // EVENT //
    bool (*get_event)(nsf_window_t *, nsf_event_t *);
    // DRAW //
    void (*fill)(const nsf_window_t *, const nsf_color_t[]);
    int (*draw_lines)(const nsf_window_t *, const size_t,
        const nsf_fvector_t[], const nsf_color_t[]);
    void (*draw)(nsf_window_t *);
    // ELEMENT //
    void (*add_sprite)(nsf_window_t *, nsf_sprite_t *, nsf_game_t *);
    void (*add_button)(nsf_window_t *, nsf_button_t *, nsf_game_t *);
    void (*add_sound)(nsf_window_t *, nsf_sound_t *, nsf_game_t *);
    nsf_sprite_t *(*get_sprite)(nsf_window_t *, const char[]);
    nsf_button_t *(*get_button)(nsf_window_t *, const char[]);
    nsf_sound_t *(*get_sound)(nsf_window_t *, const char[]);
    // SOUND //
    int (*play_sound)(nsf_window_t *, const char[]);
    int (*pause_sound)(nsf_window_t *, const char[]);
    int (*stop_sound)(nsf_window_t *, const char[]);
    int (*volume_all_sound)(nsf_window_t *, float);
    int (*stop_all_sound)(nsf_window_t *);
    // SPECIAL //
    int (*update_settings)(nsf_window_t *);
    void (*get_mouse)(nsf_window_t *, nsf_ivector_t[]);
} nsf_window_functions_t;
    #endif

    #ifndef  T_NSF_EXT_WINDOWS_SETTINGS
        #define  T_NSF_EXT_WINDOWS_SETTINGS
typedef struct {
    // BASE //
    nsf_window_settings_t *(*setting_create)(const nsf_window_settings_t[],
        nsf_game_t *);
    int (*setting_destroy)(nsf_window_settings_t **, nsf_game_t *);
} nsf_window_settings_functions_t;
    #endif

    #ifndef  T_NSF_EXT_BACKGROUNDS
        #define  T_NSF_EXT_BACKGROUNDS
typedef struct {
    nsf_background_t *(*create)(const char[], nsf_window_t *, nsf_game_t *);
    int (*destroy)(nsf_background_t **, nsf_game_t *);
    void (*draw)(nsf_background_t *, nsf_window_t *);
} nsf_background_functions_t;
    #endif

    #ifndef  T_NSF_EXT_SPRITES
        #define  T_NSF_EXT_SPRITES
typedef struct {
    // BASE //
    nsf_sprite_t *(*create)(const char[], nsf_game_t *);
    int (*destroy)(nsf_sprite_t **, nsf_game_t *);
    // MANAGE //
    void (*set_texture)(nsf_sprite_t *, nsf_texture_t *);
    void (*set_scale)(nsf_sprite_t *, nsf_fvector_t []);
    void (*set_size)(nsf_sprite_t *, nsf_uvector_t[]);
    void (*set_position)(nsf_sprite_t *, nsf_fvector_t[]);
    void (*set_origin)(nsf_sprite_t *, nsf_fvector_t[]);
    nsf_texture_t *(*get_texture)(nsf_sprite_t *);
    nsf_fvector_t *(*get_scale)(nsf_sprite_t *);
    nsf_uvector_t *(*get_size)(nsf_sprite_t *);
    nsf_fvector_t *(*get_position)(nsf_sprite_t *);
    nsf_fvector_t *(*get_origin)(nsf_sprite_t *);
    // SPECIAL //
    void (*update)(nsf_sprite_t *);
    // DRAW //
    void (*draw)(nsf_sprite_t *, nsf_window_t *);
} nsf_sprite_functions_t;
    #endif

    #ifndef  T_NSF_EXT_TEXTURES
        #define  T_NSF_EXT_TEXTURES
typedef struct {
    // BASE //
    nsf_texture_t *(*create)(const char[], const char[],
        nsf_game_t *);
    int (*destroy)(nsf_texture_t **, nsf_game_t *);
} nsf_texture_functions_t;
    #endif

    #ifndef  T_NSF_EXT_MUSICS
        #define  T_NSF_EXT_MUSICS
typedef struct {
    // BASE //
    nsf_music_t *(*create)(const char[], const char[], nsf_game_t *);
    int (*destroy)(nsf_music_t **, nsf_game_t *);
    // MANAGE //
    void (*play)(nsf_music_t *);
    void (*pause)(nsf_music_t *);
    void (*stop)(nsf_music_t *);
    void (*looping)(nsf_music_t *, bool);
    void (*volume)(nsf_music_t *, float);
    nsf_sound_status_t (*get_status)(nsf_music_t *);
} nsf_music_functions_t;
    #endif

    #ifndef  T_NSF_EXT_SOUNDS
        #define  T_NSF_EXT_SOUNDS
typedef struct {
    // BASE //
    nsf_sound_t *(*create)(const char[], const char[], nsf_game_t *);
    int (*destroy)(nsf_sound_t **, nsf_game_t *);
    // MANAGE //
    void (*play)(nsf_sound_t *);
    void (*pause)(nsf_sound_t *);
    void (*stop)(nsf_sound_t *);
    void (*looping)(nsf_sound_t *, bool);
    void (*volume)(nsf_sound_t *, float);
    nsf_sound_status_t (*get_status)(nsf_sound_t *);
} nsf_sound_functions_t;
    #endif

    #ifndef  T_NSF_EXT_EVENTS
        #define  T_NSF_EXT_EVENTS
typedef struct {
    // MANAGE //
    bool (*cmp)(const nsf_event_t *, nsf_event_type_t);
    bool (*cmp_key)(const nsf_event_t *, nsf_key_code_t);
    void (*get_mouse)(const nsf_event_t *, nsf_ivector_t[]);
    float (*get_mouse_wheel)(const nsf_event_t *);
} nsf_event_functions_t;
    #endif

    #ifndef  T_NSF_EXT_BUTTONS
        #define  T_NSF_EXT_BUTTONS
typedef struct {
    // BASE //
    nsf_button_t *(*create)(const char[], nsf_game_t *);
    int (*destroy)(nsf_button_t **, nsf_game_t *);
    // MANAGE //
    void (*set_texture)(nsf_button_t *, nsf_texture_t *);
    void (*set_position)(nsf_button_t *, const nsf_fvector_t[]);
    void (*set_size)(nsf_button_t *, const nsf_fvector_t[]);
    void (*set_colors)(nsf_button_t *, const nsf_color_t[],
        const nsf_color_t[], nsf_uint_t);
    nsf_button_status_t (*get_state)(nsf_button_t *, nsf_window_t *,
        nsf_mouse_t);
    // DRAW //
    void (*draw)(nsf_button_t *, nsf_window_t *);
} nsf_button_functions_t;
    #endif

    #ifndef  T_NSF_EXT_NSF
        #define  T_NSF_EXT_NSF
typedef struct {
    nsf_game_functions_t game;
    nsf_window_functions_t window;
    nsf_window_settings_functions_t window_settings;
    nsf_sprite_functions_t sprite;
    nsf_button_functions_t button;
    nsf_texture_functions_t texture;
    nsf_music_functions_t music;
    nsf_colors_t color;
    nsf_event_functions_t event;
} nsf_nsf_functions_t;
    #endif

#endif
