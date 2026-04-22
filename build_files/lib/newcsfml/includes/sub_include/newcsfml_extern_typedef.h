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

typedef struct {
    // BASE //
    nsf_window_settings_t *(*setting_create)(const nsf_window_settings_t[],
        nsf_game_t *);
    int (*setting_destroy)(nsf_window_settings_t **, nsf_game_t *);
} nsf_window_settings_functions_t;

typedef struct {
    nsf_background_t *(*create)(const char[], nsf_window_t *, nsf_game_t *);
    int (*destroy)(nsf_background_t **, nsf_game_t *);
    void (*draw)(nsf_background_t *, nsf_window_t *);
} nsf_background_functions_t;

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
    void (*get_scale)(nsf_sprite_t *, nsf_fvector_t *out);
    void (*get_size)(nsf_sprite_t *, nsf_uvector_t *out);
    void (*get_position)(nsf_sprite_t *, nsf_fvector_t *out);
    void (*get_origin)(nsf_sprite_t *, nsf_fvector_t *out);
    // SPECIAL //
    void (*update)(nsf_sprite_t *);
    // DRAW //
    void (*draw)(nsf_sprite_t *, nsf_window_t *);
} nsf_sprite_functions_t;

typedef struct {
    // BASE //
    nsf_texture_t *(*create)(const char[], const char[],
        nsf_game_t *);
    int (*destroy)(nsf_texture_t **, nsf_game_t *);
} nsf_texture_functions_t;

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

typedef struct {
    // MANAGE //
    bool (*cmp)(const nsf_event_t *, nsf_event_type_t);
    bool (*cmp_key)(const nsf_event_t *, nsf_key_code_t);
    void (*get_mouse)(const nsf_event_t *, nsf_ivector_t[]);
    float (*get_mouse_wheel)(const nsf_event_t *);
} nsf_event_functions_t;

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

typedef struct {
    // MANAGE //
    void (*fempty)(nsf_fvector_t *);
    void (*i2f)(const nsf_ivector_t vector[], nsf_fvector_t *);
    void (*u2f)(const nsf_uvector_t vector[], nsf_fvector_t *);
    void (*fcopy)(const nsf_fvector_t vector[], nsf_fvector_t *);
    void (*iempty)(nsf_ivector_t *);
    void (*f2i)(const nsf_fvector_t vector[], nsf_ivector_t *);
    void (*u2i)(const nsf_uvector_t vector[], nsf_ivector_t *);
    void (*icopy)(const nsf_ivector_t vector[], nsf_ivector_t *);
    void (*uempty)(nsf_uvector_t *);
    void (*f2u)(const nsf_fvector_t vector[], nsf_uvector_t *);
    void (*i2u)(const nsf_ivector_t vector[], nsf_uvector_t *);
    void (*ucopy)(const nsf_uvector_t vector[], nsf_uvector_t *);
    void (*add)(const nsf_fvector_t[], const nsf_fvector_t[], nsf_fvector_t *);
    void (*sub)(const nsf_fvector_t[], const nsf_fvector_t[], nsf_fvector_t *);
    void (*mul)(const nsf_fvector_t[], float, nsf_fvector_t *);
    void (*div)(const nsf_fvector_t[], float, nsf_fvector_t *);
    void (*neg)(const nsf_fvector_t[], nsf_fvector_t *);
    float (*len)(const nsf_fvector_t[]);
    void (*norm)(const nsf_fvector_t[], nsf_fvector_t *);
    float (*dist_to)(const nsf_fvector_t[], const nsf_fvector_t[]);
    void (*dir_to)(const nsf_fvector_t[], const nsf_fvector_t[],
        nsf_fvector_t *);
    float (*dot)(const nsf_fvector_t[], const nsf_fvector_t[]);
    float (*cross)(const nsf_fvector_t[], const nsf_fvector_t[]);
    float (*get_angle)(const nsf_fvector_t[]);
    void (*rotate)(const nsf_fvector_t[], float, nsf_fvector_t *);
    void (*print)(const nsf_fvector_t[]);
} nsf_vector_functions_t;

typedef struct {
    nsf_color_t black;
    nsf_color_t white;
    nsf_color_t red;
    nsf_color_t green;
    nsf_color_t blue;
    nsf_color_t yellow;
    nsf_color_t magenta;
    nsf_color_t cyan;
    nsf_color_t grey;
    nsf_color_t transparent;
} nsf_colors_shortcut_t;

typedef struct {
    nsf_game_functions_t game;
    nsf_window_functions_t window;
    nsf_window_settings_functions_t window_settings;
    nsf_sprite_functions_t sprite;
    nsf_button_functions_t button;
    nsf_texture_functions_t texture;
    nsf_music_functions_t music;
    nsf_sound_functions_t sound;
    nsf_colors_shortcut_t color;
    nsf_vector_functions_t vector;
    nsf_event_functions_t event;
} nsf_nsf_functions_t;

#endif
