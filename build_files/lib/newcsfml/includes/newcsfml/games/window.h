/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.2
** Author: Jarjarbin06
** License: GPL v3
** •
** This library is inspired by SFML/CSFML and is designed for
** educational and game-development purposes.
** •
** It provides higher-level abstractions over CSFML to reduce
** boilerplate code and enforce safer usage patterns.
** •
** WARNING:
** This is NOT the original SFML/CSFML library.
** It is a custom implementation layer built on top of CSFML.
*/

#ifndef NEWCSFML_WINDOW_H
    #define NEWCSFML_WINDOW_H

    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Window/Event.h>
    #include <SFML/Graphics/Color.h>
    #include <stdbool.h>
    #include <stddef.h>

    #ifndef EXIT_D
        #define EXIT_D

        #ifndef EXIT_SUCCESS
            #define EXIT_SUCCESS 0
        #endif

        #ifndef EXIT_ERROR
            #define EXIT_ERROR 84
        #endif

    #endif

/// TMP ///
typedef const char *nsf_cstr_t;
typedef const char *cstr_t;
typedef sfVector2i nsf_ivector_t;
typedef sfEvent nsf_event_t;
typedef sfVector2f nsf_fvector_t;
typedef struct nsf_background_s nsf_background_t;
typedef sfColor nsf_color_t;
typedef struct nsf_window_settings_s nsf_window_settings_t;
typedef struct nsf_game_s nsf_game_t;
typedef struct nsf_sprite_s nsf_sprite_t;
typedef struct nsf_button_s nsf_button_t;
typedef struct nsf_sound_s nsf_sound_t;
typedef struct nsf_text_s nsf_text_t;

/// TYPEDEFS ///
typedef enum
{
    NSF_UNKNOWN_ELEMENT = -1,
    NSF_SPRITE_ELEMENT,
    NSF_BUTTON_ELEMENT,
    NSF_SOUND_ELEMENT,
    NSF_TEXT_ELEMENT
} nsf_window_element_t;

typedef struct {
    nsf_window_element_t element_type;
    const void *ptr;
} nsf_window_elements_t;

typedef struct nsf_window_s {
    nsf_window_settings_t *settings;
    sfRenderWindow *window;
    nsf_background_t *background;
    nsf_window_elements_t **elements;
    nsf_cstr_t title;
} nsf_window_t;

typedef enum {
    NSF_WDW_UNKNOWN = -1,
    NSF_WDW_NONE = 0,
    NSF_WDW_TITLEBAR = 1 << 0,
    NSF_WDW_RESIZE = 1 << 1,
    NSF_WDW_CLOSE = 1 << 2,
    NSF_WDW_FULLSCREEN = 1 << 3,
    NSF_WDW_DEFAULT_STYLE = NSF_WDW_TITLEBAR | NSF_WDW_RESIZE | NSF_WDW_CLOSE
} nsf_window_style_t;

/// PROTOTYPES ///
// STRUCT //
nsf_window_t *nsf_window_create(const nsf_window_settings_t *settings,
    const char title[], nsf_window_style_t window_style, nsf_game_t *game);
int nsf_window_destroy(nsf_window_t **window, nsf_game_t *game);

// MANAGE //
int nsf_window_display(const nsf_window_t *window);
bool nsf_window_isopen(const nsf_window_t *window);
void nsf_window_close(const nsf_window_t *window);
bool nsf_window_get_event(const nsf_window_t *window, nsf_event_t *event);
void nsf_window_add_sprite(nsf_window_t *window, const nsf_sprite_t *sprite,
    nsf_game_t *game);
void nsf_window_add_button(nsf_window_t *window, const nsf_button_t *button,
    nsf_game_t *game);
void nsf_window_add_sound(nsf_window_t *window, const nsf_sound_t *sound,
    nsf_game_t *game);
void nsf_window_add_text(nsf_window_t *window, const nsf_text_t *text,
    nsf_game_t *game);
nsf_sprite_t *nsf_window_get_sprite(const nsf_window_t *window,
    const char sprite_name[]);
nsf_button_t *nsf_window_get_button(const nsf_window_t *window,
    const char button_name[]);
nsf_sound_t *nsf_window_get_sound(const nsf_window_t *window,
    const char sound_name[]);
nsf_text_t *nsf_window_get_text(const nsf_window_t *window,
    const char text_name[]);
void nsf_window_set_background(nsf_window_t *window,
    nsf_background_t *background);
const nsf_background_t *nsf_window_get_background(const nsf_window_t *window);
int nsf_window_play_sound(const nsf_window_t *window, const char sound_name[]);
int nsf_window_pause_sound(const nsf_window_t *window, const char sound_name[]);
int nsf_window_stop_sound(const nsf_window_t *window, const char sound_name[]);
int nsf_window_all_sound_volume(const nsf_window_t *window, float volume);
int nsf_window_stop_all_sound(const nsf_window_t *window);
int nsf_window_update_settings(const nsf_window_t *window);
void nsf_window_get_mouse(const nsf_window_t *window, nsf_ivector_t out[]);

// DRAW //
int nsf_window_draw_lines(const nsf_window_t *window, size_t len,
    const nsf_fvector_t points[], const nsf_color_t color[]);
void nsf_window_fill(const nsf_window_t *window, const nsf_color_t color[]);
void nsf_window_draw(const nsf_window_t *window);

#endif
