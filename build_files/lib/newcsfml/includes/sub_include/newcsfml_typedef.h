/*
** EPITECH PROJECT, 2025
** sub_includes - newcsfml_typedef.h
** File description:
** <description>
*/

// Typedef //
#ifndef NEWCSFML_T
    #define NEWCSFML_T

    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Window/Event.h>

    #include "newcsfml_include.h"

    #ifndef NEWCSFML_T_TYPE
        #define NEWCSFML_T_TYPE

        #ifndef T_VOID_FUNC
            #define T_VOID_FUNC
typedef void (*void_func_t)(void *);
        #endif

        #ifndef T_NSF_UINT
            #define T_NSF_UINT
typedef unsigned int nsf_uint;
        #endif

        #ifndef T_NSF_EVENT
            #define T_NSF_EVENT
typedef sfEvent nsf_event;
        #endif

        #ifndef T_NSF_EVENT_TYPE
            #define T_NSF_EVENT_TYPE
typedef enum {
    nsf_evt_closed,
    nsf_evt_resized,
    nsf_evt_lost_focus,
    nsf_evt_gained_focus,
    nsf_evt_text_entered,
    nsf_evt_key_pressed,
    nsf_evt_key_released,
    nsf_evt_mouse_wheel_scrolled,
    nsf_evt_mouse_button_pressed,
    nsf_evt_mouse_button_released,
    nsf_evt_mouse_moved,
    nsf_evt_mouse_entered,
    nsf_evt_mouse_left,
    nsf_evt_joystick_button_pressed,
    nsf_evt_joystick_button_released,
    nsf_evt_joystick_moved,
    nsf_evt_joystick_connected,
    nsf_evt_joystick_disconnected,
    nsf_evt_touch_began,
    nsf_evt_touch_moved,
    nsf_evt_touch_ended,
    nsf_evt_sensor_changed,
    nsf_evt_count
} nsf_event_type;
        #endif

        #ifndef T_NSF_WINDOW_STYLE
            #define T_NSF_WINDOW_STYLE
typedef enum {
    nsf_wdw_none = 0,
    nsf_wdw_titlebar = 1,
    nsf_wdw_resize = 2,
    nsf_wdw_close = 4,
    nsf_wdw_fullscreen = 8,
    nsf_wdw_default_style = nsf_wdw_titlebar | nsf_wdw_resize | nsf_wdw_close
} nsf_window_style;
        #endif

// add type typedefs here //

    #endif

    #ifndef NEWCSFML_T_STRUCT
        #define NEWCSFML_T_STRUCT

        #ifndef T_NSF_SPRITE
            #define T_NSF_SPRITE
typedef struct nsf_sprite_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f size;
    sfVector2f origin;
    sfVector2f position;
    float rotation;
    char *name;
    void *data;
} nsf_sprite;
        #endif

        #ifndef T_NSF_BACKGROUND
            #define T_NSF_BACKGROUND
typedef struct nsf_background_s {
    sfSprite *sprite;
    sfTexture *texture;
} nsf_background;
        #endif

        #ifndef T_NSF_WINDOW_SETTINGS
            #define T_NSF_WINDOW_SETTINGS
typedef struct nsf_window_settings_s {
    nsf_uint width;
    nsf_uint height;
    nsf_uint bpp;
    nsf_uint fps;
} nsf_window_settings;
        #endif

        #ifndef T_NSF_WINDOW
            #define T_NSF_WINDOW
typedef struct nsf_window_s {
    nsf_window_settings *settings;
    sfRenderWindow *window;
    nsf_uint fps;
    nsf_background *background;
    nsf_sprite **sprites;
    char *title;
} nsf_window;
        #endif

        #ifndef T_NSF_GAME
            #define T_NSF_GAME
typedef struct nsf_game_s {
    nsf_window *window;
    nsf_uint allocations;
} nsf_game;
        #endif

        #ifndef T_FREE
            #define T_FREE
typedef struct free_s {
    bool condition;
    void *ptr;
    void_func_t free_func;
} free_t;
        #endif

// add struct typedefs here //

    #endif

#endif
