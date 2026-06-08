/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.9
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

#ifndef NEWCSFML_JOYSTICK_H
    #define NEWCSFML_JOYSTICK_H

    #include <SFML/Window/Joystick.h>

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
    #define NSF_JOYSTICK "NSF_JOYSTICK"
    #define NSF_JOYSTICK_COUNT 8

/// TMP ///
typedef sfBool nsf_bool_t;
typedef unsigned int nsf_uint_t;

/// TYPEDEFS ///
typedef unsigned int nsf_joystick_id_t;

typedef enum {
    NSF_JOYSTICK_AXIS_UNKNOWN = -1,
    NSF_JOYSTICK_AXIS_X,
    NSF_JOYSTICK_AXIS_Y,
    NSF_JOYSTICK_AXIS_Z,
    NSF_JOYSTICK_AXIS_R,
    NSF_JOYSTICK_AXIS_U,
    NSF_JOYSTICK_AXIS_V,
    NSF_JOYSTICK_AXIS_POV_X,
    NSF_JOYSTICK_AXIS_POV_Y,
    NSF_JOYSTICK_AXIS_COUNT = 8
} nsf_joystick_axis_t;

typedef enum {
    NSF_JOYSTICK_XBOX_LSTICK_X = NSF_JOYSTICK_AXIS_X,
    NSF_JOYSTICK_XBOX_LSTICK_Y = NSF_JOYSTICK_AXIS_Y,
    NSF_JOYSTICK_XBOX_RSTICK_X = NSF_JOYSTICK_AXIS_Z,
    NSF_JOYSTICK_XBOX_RSTICK_Y = NSF_JOYSTICK_AXIS_R,
    NSF_JOYSTICK_XBOX_LTRIGGER = NSF_JOYSTICK_AXIS_U,
    NSF_JOYSTICK_XBOX_RTRIGGER = NSF_JOYSTICK_AXIS_V,
    NSF_JOYSTICK_XBOX_DPAD_X = NSF_JOYSTICK_AXIS_POV_X,
    NSF_JOYSTICK_XBOX_DPAD_Y = NSF_JOYSTICK_AXIS_POV_Y,
    NSF_JOYSTICK_AXIS_XBOX_COUNT = 8
} nsf_joystick_axis_xbox_t;

typedef enum {
    NSF_JOYSTICK_BUTTON_UNKNOWN = -1,
    NSF_JOYSTICK_BUTTON_1,
    NSF_JOYSTICK_BUTTON_2,
    NSF_JOYSTICK_BUTTON_3,
    NSF_JOYSTICK_BUTTON_4,
    NSF_JOYSTICK_BUTTON_5,
    NSF_JOYSTICK_BUTTON_6,
    NSF_JOYSTICK_BUTTON_7,
    NSF_JOYSTICK_BUTTON_8,
    NSF_JOYSTICK_BUTTON_9,
    NSF_JOYSTICK_BUTTON_10,
    NSF_JOYSTICK_BUTTON_11,
    NSF_JOYSTICK_BUTTON_12,
    NSF_JOYSTICK_BUTTON_13,
    NSF_JOYSTICK_BUTTON_14,
    NSF_JOYSTICK_BUTTON_15,
    NSF_JOYSTICK_BUTTON_16,
    NSF_JOYSTICK_BUTTON_17,
    NSF_JOYSTICK_BUTTON_18,
    NSF_JOYSTICK_BUTTON_19,
    NSF_JOYSTICK_BUTTON_20,
    NSF_JOYSTICK_BUTTON_21,
    NSF_JOYSTICK_BUTTON_22,
    NSF_JOYSTICK_BUTTON_23,
    NSF_JOYSTICK_BUTTON_24,
    NSF_JOYSTICK_BUTTON_25,
    NSF_JOYSTICK_BUTTON_26,
    NSF_JOYSTICK_BUTTON_27,
    NSF_JOYSTICK_BUTTON_28,
    NSF_JOYSTICK_BUTTON_29,
    NSF_JOYSTICK_BUTTON_30,
    NSF_JOYSTICK_BUTTON_31,
    NSF_JOYSTICK_BUTTON_32,
    NSF_JOYSTICK_BUTTON_COUNT
} nsf_joystick_button_t;

typedef enum {
    NSF_JOYSTICK_BUTTON_XBOX_A = NSF_JOYSTICK_BUTTON_1,
    NSF_JOYSTICK_BUTTON_XBOX_B = NSF_JOYSTICK_BUTTON_2,
    NSF_JOYSTICK_BUTTON_XBOX_X = NSF_JOYSTICK_BUTTON_3,
    NSF_JOYSTICK_BUTTON_XBOX_Y = NSF_JOYSTICK_BUTTON_4,
    NSF_JOYSTICK_BUTTON_XBOX_LB = NSF_JOYSTICK_BUTTON_5,
    NSF_JOYSTICK_BUTTON_XBOX_RB = NSF_JOYSTICK_BUTTON_6,
    NSF_JOYSTICK_BUTTON_XBOX_BACK = NSF_JOYSTICK_BUTTON_7,
    NSF_JOYSTICK_BUTTON_XBOX_START = NSF_JOYSTICK_BUTTON_8,
    NSF_JOYSTICK_BUTTON_XBOX_LS = NSF_JOYSTICK_BUTTON_9,
    NSF_JOYSTICK_BUTTON_XBOX_RS = NSF_JOYSTICK_BUTTON_10,
    NSF_JOYSTICK_BUTTON_XBOX_COUNT
} nsf_joystick_button_xbox_t;

typedef struct nsf_joystick_s {
    sfBool connected;
    nsf_joystick_id_t id;
    float axes[NSF_JOYSTICK_AXIS_XBOX_COUNT];
    sfBool buttons[NSF_JOYSTICK_BUTTON_XBOX_COUNT];
} nsf_joystick_xbox_t;

/// PROTOTYPES ///
// MANAGE //
nsf_bool_t nsf_joystick_is_connected(nsf_joystick_id_t joystick_id);
void nsf_joystick_xbox_update(nsf_joystick_xbox_t *xbox);
float nsf_joystick_get_axis_position(nsf_joystick_id_t joystick_id,
    nsf_joystick_axis_xbox_t axis);
nsf_bool_t nsf_joystick_is_button_pressed(nsf_joystick_id_t joystick_id,
    nsf_joystick_button_xbox_t button);

#endif
