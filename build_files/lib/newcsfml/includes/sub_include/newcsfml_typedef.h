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
    #include <SFML/Window/WindowBase.h>

    #include <stdbool.h>

    #ifndef T_VOID_FUNC
        #define T_VOID_FUNC
typedef void *(*void_func_t)(void *);
    #endif

    #ifndef T_STR
        #define  T_STR
typedef char *str;
    #endif

    #ifndef T_NSF_UINT
        #define T_NSF_UINT
typedef unsigned int nsf_uint;
    #endif

    #ifndef T_NSF_VECTOR
        #define T_NSF_VECTOR
typedef sfVector2f nsf_vector;
    #endif

    #ifndef T_NSF_COLOR
        #define T_NSF_COLOR
typedef sfColor nsf_color_t;
    #endif

    #ifndef T_NSF_COLORS
        #define T_NSF_COLORS
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
} nsf_colors_t;
    #endif

    #ifndef T_NSF_EVENT
        #define T_NSF_EVENT
typedef sfEvent nsf_event_t;
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
    nsf_evt_mouse_wheel_moved_deprecated,
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
} nsf_event_type_t;
    #endif

    #ifndef T_NSF_WINDOW_STYLE
        #define T_NSF_WINDOW_STYLE
typedef enum {
    nsf_wdw_none = (sfWindowStyle)sfNone,
    nsf_wdw_titlebar = (sfWindowStyle)sfFullscreen,
    nsf_wdw_resize = (sfWindowStyle)sfFullscreen,
    nsf_wdw_close = (sfWindowStyle)sfFullscreen,
    nsf_wdw_fullscreen = (sfWindowStyle)sfFullscreen,
    nsf_wdw_default_style = (sfWindowStyle)sfDefaultStyle
} nsf_window_style_t;
    #endif

    #ifndef T_NSF_KEY
        #define T_NSF_KEY
typedef enum
{
    nsf_key_unknown = -1,
    nsf_key_a,
    nsf_key_b,
    nsf_key_c,
    nsf_key_d,
    nsf_key_e,
    nsf_key_f,
    nsf_key_g,
    nsf_key_h,
    nsf_key_i,
    nsf_key_j,
    nsf_key_k,
    nsf_key_l,
    nsf_key_m,
    nsf_key_n,
    nsf_key_o,
    nsf_key_p,
    nsf_key_q,
    nsf_key_r,
    nsf_key_s,
    nsf_key_t,
    nsf_key_u,
    nsf_key_v,
    nsf_key_w,
    nsf_key_x,
    nsf_key_y,
    nsf_key_z,
    nsf_key_0,
    nsf_key_1,
    nsf_key_2,
    nsf_key_3,
    nsf_key_4,
    nsf_key_5,
    nsf_key_6,
    nsf_key_7,
    nsf_key_8,
    nsf_key_9,
    nsf_key_escape,
    nsf_key_l_control,
    nsf_key_l_shift,
    nsf_key_l_alt,
    nsf_key_l_system,
    nsf_key_r_control,
    nsf_key_r_shift,
    nsf_key_r_alt,
    nsf_key_r_system,
    nsf_key_menu,
    nsf_key_l_bracket,
    nsf_key_r_bracket,
    nsf_key_semicolon,
    nsf_key_comma,
    nsf_key_period,
    nsf_key_apostrophe,
    nsf_key_slash,
    nsf_key_backslash,
    nsf_key_grave,
    nsf_key_equal,
    nsf_key_hyphen,
    nsf_key_space,
    nsf_key_enter,
    nsf_key_backspace,
    nsf_key_tab,
    nsf_key_page_up,
    nsf_key_page_bown,
    nsf_key_end,
    nsf_key_home,
    nsf_key_insert,
    nsf_key_delete,
    nsf_key_add,
    nsf_key_subtract,
    nsf_key_multiply,
    nsf_key_divide,
    nsf_key_left,
    nsf_key_right,
    nsf_key_up,
    nsf_key_down,
    nsf_key_np_0,
    nsf_key_np_1,
    nsf_key_np_2,
    nsf_key_np_3,
    nsf_key_np_4,
    nsf_key_np_5,
    nsf_key_np_6,
    nsf_key_np_7,
    nsf_key_np_8,
    nsf_key_np_9,
    nsf_key_f_1,
    nsf_key_f_2,
    nsf_key_f_3,
    nsf_key_f_4,
    nsf_key_f_5,
    nsf_key_f_6,
    nsf_key_f_7,
    nsf_key_f_8,
    nsf_key_f_9,
    nsf_key_f_10,
    nsf_key_f_11,
    nsf_key_f_12,
    nsf_key_f_13,
    nsf_key_f_14,
    nsf_key_f_15,
    nsf_key_pause,
    nsf_key_count,
} nsf_key_code;
    #endif

    #ifndef T_NSF_MOUSE
        #define T_NSF_MOUSE
typedef enum
{
    nsf_mouse_left,
    nsf_mouse_right,
    nsf_mouse_middle,
    nsf_mouse_x_bttn_1,
    nsf_mouse_x_bttn_2,
    nsf_mouse_count
} nsf_mouse;
    #endif

    #ifndef T_NSF_WINDOW_ELEMENTS
        #define T_NSF_WINDOW_ELEMENTS
typedef enum
{
    SPRITE_ELEMENT,
    BUTTON_ELEMENT
} nsf_window_elements_t;
    #endif

    #ifndef T_NSF_WINDOW_ELEMENT
        #define T_NSF_WINDOW_ELEMENT
typedef struct {
    nsf_window_elements_t element_type;
    void *ptr;
} nsf_window_element_t;
    #endif

    #ifndef T_NSF_TEXTURE
        #define T_NSF_TEXTURE
typedef struct {
    sfTexture *texture;
    str name;
} nsf_texture_t;
    #endif

    #ifndef T_NSF_BUTTON
        #define  T_NSF_BUTTON
typedef struct {
    sfRectangleShape *button;
    nsf_texture_t *texture;
    nsf_vector size;
    nsf_vector position;
    nsf_color_t fill_color;
    nsf_color_t outline_color;
    str name;
} nsf_button_t;
    #endif

    #ifndef T_NSF_SPRITE
        #define T_NSF_SPRITE
typedef struct {
    sfSprite *sprite;
    nsf_texture_t *texture;
    nsf_vector size;
    nsf_vector origin;
    nsf_vector position;
    float rotation;
    str name;
    void *data;
} nsf_sprite_t;
    #endif

    #ifndef T_NSF_BACKGROUND
        #define T_NSF_BACKGROUND
typedef struct {
    sfSprite *sprite;
    sfTexture *texture;
} nsf_background_t;
    #endif

    #ifndef T_NSF_WINDOW_SETTINGS
        #define T_NSF_WINDOW_SETTINGS
typedef struct {
    nsf_uint width;
    nsf_uint height;
    nsf_uint bpp;
    nsf_uint fps;
} nsf_window_settings_t;
    #endif

    #ifndef T_NSF_WINDOW
        #define T_NSF_WINDOW
typedef struct {
    nsf_window_settings_t *settings;
    sfRenderWindow *window;
    nsf_uint fps;
    nsf_background_t *background;
    nsf_window_element_t **elements;
    str title;
} nsf_window_t;
    #endif

    #ifndef T_NSF_GAME
        #define T_NSF_GAME
typedef struct {
    nsf_window_t *window;
    nsf_uint allocations;
} nsf_game_t;
    #endif

    #ifndef T_FREE
        #define T_FREE
typedef struct {
    bool condition;
    void *ptr;
    void_func_t free_func;
} free_t;
    #endif

#endif
