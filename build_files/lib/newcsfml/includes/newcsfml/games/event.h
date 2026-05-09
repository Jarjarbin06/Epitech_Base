/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.5
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

#ifndef NEWCSFML_EVENT_H
    #define NEWCSFML_EVENT_H

    #include <SFML/System/Vector2.h>
    #include <SFML/Window/Event.h>

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
typedef sfVector2i nsf_ivector_t;
typedef enum nsf_key_code_e nsf_key_code_t;

/// TYPEDEFS ///
typedef sfEvent nsf_event_t;

typedef enum {
    NSF_EVT_UNKNOWN = -1,
    NSF_EVT_CLOSED,
    NSF_EVT_RESIZED,
    NSF_EVT_LOST_FOCUS,
    NSF_EVT_GAINED_FOCUS,
    NSF_EVT_TEXT_ENTERED,
    NSF_EVT_KEY_PRESSED,
    NSF_EVT_KEY_RELEASED,
    NSF_EVT_MOUSE_WHEEL_MOVED_DEPRECATED,
    NSF_EVT_MOUSE_WHEEL_SCROLLED,
    NSF_EVT_MOUSE_BUTTON_PRESSED,
    NSF_EVT_MOUSE_BUTTON_RELEASED,
    NSF_EVT_MOUSE_MOVED,
    NSF_EVT_MOUSE_ENTERED,
    NSF_EVT_MOUSE_LEFT,
    NSF_EVT_JOYSTICK_BUTTON_PRESSED,
    NSF_EVT_JOYSTICK_BUTTON_RELEASED,
    NSF_EVT_JOYSTICK_MOVED,
    NSF_EVT_JOYSTICK_CONNECTED,
    NSF_EVT_JOYSTICK_DISCONNECTED,
    NSF_EVT_TOUCH_BEGAN,
    NSF_EVT_TOUCH_MOVED,
    NSF_EVT_TOUCH_ENDED,
    NSF_EVT_SENSOR_CHANGED,
    NSF_EVT_COUNT
} nsf_event_type_t;

typedef enum nsf_mouse_button_e {
    NSF_MSE_UNKNOWN = -1,
    NSF_MSE_LEFT,
    NSF_MSE_RIGHT,
    NSF_MSE_MIDDLE,
    NSF_MSE_X_BTTN_1,
    NSF_MSE_X_BTTN_2,
    NSF_MSE_COUNT
} nsf_mouse_button_t;

/// PROTOTYPES ///
// MANAGE //
bool nsf_event_cmp(const nsf_event_t *event, nsf_event_type_t event_type);
bool nsf_event_cmp_key(const nsf_event_t *event, nsf_key_code_t key_code);
void nsf_event_get_mouse_move(const nsf_event_t *event,
    nsf_ivector_t out[]);
float nsf_event_get_mouse_wheel(const nsf_event_t *event);

#endif
