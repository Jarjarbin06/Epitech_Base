/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.10
** Author: Jarjarbin06
** Licence: GPL v3
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

#ifndef NEWCSFML_BUTTON_H
    #define NEWCSFML_BUTTON_H

    #include <SFML/Graphics/RectangleShape.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/System/Vector2.h>

    #include <stdbool.h>
    #include <stddef.h>

    #ifndef EXIT_D
        #define EXIT_D

        #ifndef E_SUCCESS
            #define E_SUCCESS (0)
        #endif

        #ifndef E_ERROR
            #define E_ERROR (84)
        #endif

        #ifndef E_FAILURE
            #define E_FAILURE (-1)
        #endif

    #endif

/// MACRO ///
    #define NSF_BUTTON "NSF_BUTTON"

/// TMP ///
typedef const char *cstr_t;
typedef sfColor nsf_color_t;
typedef struct nsf_game_s nsf_game_t;
typedef struct nsf_window_s nsf_window_t;
typedef sfVector2f nsf_fvector_t;
typedef sfVector2u nsf_uvector_t;
typedef struct nsf_texture_s nsf_texture_t;
typedef unsigned int nsf_uint_t;
typedef const char *nsf_cstr_t;
typedef enum nsf_mouse_button_e nsf_mouse_button_t;

/// TYPEDEFS ///
typedef struct nsf_button_s {
    sfRectangleShape *button;
    const nsf_texture_t *texture;
    nsf_uvector_t size;
    nsf_fvector_t position;
    nsf_color_t fill_color;
    nsf_color_t outline_color;
    nsf_cstr_t name;
} nsf_button_t;

typedef enum {
    NSF_STT_BTN_UNKNOWN = -1,
    NSF_STT_BTN_NONE,
    NSF_STT_BTN_HOVERED,
    NSF_STT_BTN_PRESSED
} nsf_button_status_t;

/// PROTOTYPES ///
// STRUCT //
nsf_button_t *nsf_button_create(const char name[], nsf_game_t *game);
int nsf_button_destroy(nsf_button_t **button, nsf_game_t *game);

// MANAGE //
void nsf_button_set_texture(nsf_button_t *button, const nsf_texture_t *texture);
void nsf_button_set_position(nsf_button_t *button,
    const nsf_fvector_t position[]);
void nsf_button_set_size(nsf_button_t *button, const nsf_uvector_t size[]);
void nsf_button_set_colors(nsf_button_t *button,
    const nsf_color_t fill_color[], const nsf_color_t outline_color[],
    int outline_thickness);
nsf_button_status_t nsf_button_get_state(const nsf_button_t *button,
    const nsf_window_t *window, nsf_mouse_button_t mouse_button);

// DRAW //
void nsf_button_draw(const nsf_button_t *button, const nsf_window_t *window);

#endif
