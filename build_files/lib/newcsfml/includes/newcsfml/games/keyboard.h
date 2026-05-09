/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.4
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

#ifndef NEWCSFML_KEYBOARD_H
    #define NEWCSFML_KEYBOARD_H

    #include <SFML/Window/Keyboard.h>

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

/// TYPEDEFS ///
typedef enum nsf_key_code_e {
    NSF_KEY_UNKNOWN = -1,
    NSF_KEY_A,
    NSF_KEY_B,
    NSF_KEY_C,
    NSF_KEY_D,
    NSF_KEY_E,
    NSF_KEY_F,
    NSF_KEY_G,
    NSF_KEY_H,
    NSF_KEY_I,
    NSF_KEY_J,
    NSF_KEY_K,
    NSF_KEY_L,
    NSF_KEY_M,
    NSF_KEY_N,
    NSF_KEY_O,
    NSF_KEY_P,
    NSF_KEY_Q,
    NSF_KEY_R,
    NSF_KEY_S,
    NSF_KEY_T,
    NSF_KEY_U,
    NSF_KEY_V,
    NSF_KEY_W,
    NSF_KEY_X,
    NSF_KEY_Y,
    NSF_KEY_Z,
    NSF_KEY_0,
    NSF_KEY_1,
    NSF_KEY_2,
    NSF_KEY_3,
    NSF_KEY_4,
    NSF_KEY_5,
    NSF_KEY_6,
    NSF_KEY_7,
    NSF_KEY_8,
    NSF_KEY_9,
    NSF_KEY_ESCAPE,
    NSF_KEY_L_CONTROL,
    NSF_KEY_L_SHIFT,
    NSF_KEY_L_ALT,
    NSF_KEY_L_SYSTEM,
    NSF_KEY_R_CONTROL,
    NSF_KEY_R_SHIFT,
    NSF_KEY_R_ALT,
    NSF_KEY_R_SYSTEM,
    NSF_KEY_MENU,
    NSF_KEY_L_BRACKET,
    NSF_KEY_R_BRACKET,
    NSF_KEY_SEMICOLON,
    NSF_KEY_COMMA,
    NSF_KEY_PERIOD,
    NSF_KEY_APOSTROPHE,
    NSF_KEY_SLASH,
    NSF_KEY_BACKSLASH,
    NSF_KEY_GRAVE,
    NSF_KEY_EQUAL,
    NSF_KEY_HYPHEN,
    NSF_KEY_SPACE,
    NSF_KEY_ENTER,
    NSF_KEY_BACKSPACE,
    NSF_KEY_TAB,
    NSF_KEY_PAGE_UP,
    NSF_KEY_PAGE_BOWN,
    NSF_KEY_END,
    NSF_KEY_HOME,
    NSF_KEY_INSERT,
    NSF_KEY_DELETE,
    NSF_KEY_ADD,
    NSF_KEY_SUBTRACT,
    NSF_KEY_MULTIPLY,
    NSF_KEY_DIVIDE,
    NSF_KEY_LEFT,
    NSF_KEY_RIGHT,
    NSF_KEY_UP,
    NSF_KEY_DOWN,
    NSF_KEY_NP_0,
    NSF_KEY_NP_1,
    NSF_KEY_NP_2,
    NSF_KEY_NP_3,
    NSF_KEY_NP_4,
    NSF_KEY_NP_5,
    NSF_KEY_NP_6,
    NSF_KEY_NP_7,
    NSF_KEY_NP_8,
    NSF_KEY_NP_9,
    NSF_KEY_F_1,
    NSF_KEY_F_2,
    NSF_KEY_F_3,
    NSF_KEY_F_4,
    NSF_KEY_F_5,
    NSF_KEY_F_6,
    NSF_KEY_F_7,
    NSF_KEY_F_8,
    NSF_KEY_F_9,
    NSF_KEY_F_10,
    NSF_KEY_F_11,
    NSF_KEY_F_12,
    NSF_KEY_F_13,
    NSF_KEY_F_14,
    NSF_KEY_F_15,
    NSF_KEY_PAUSE,
    NSF_KEY_COUNT
} nsf_key_code_t;

/// PROTOTYPES ///
// MANAGE //
bool nsf_keyboard_is_pressed(nsf_key_code_t key);

#endif
