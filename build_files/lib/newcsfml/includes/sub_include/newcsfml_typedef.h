/*
** EPITECH PROJECT, 2025
** sub_includes - newcsfml_typedef.h
** File description:
** <description>
*/

// Typedef //
#ifndef NEWCSFML_T
    #define NEWCSFML_T

    #include <SFML/Audio/Sound.h>
    #include <SFML/Audio/SoundBuffer.h>
    #include <SFML/Audio/Music.h>
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Window/Event.h>
    #include <SFML/Window/WindowBase.h>

    #include <stdbool.h>

    #ifndef T_VOID_FUNC
        #define T_VOID_FUNC
typedef void *(*void_func_t)(void *);
    #endif

    #ifndef T_STR
        #define T_STR
typedef char *str_t;
    #endif

    #ifndef T_NSF_UINT
        #define T_NSF_UINT
typedef unsigned int nsf_uint_t;
    #endif

    #ifndef T_NSF_VECTOR
        #define T_NSF_VECTOR
typedef sfVector2f nsf_vector_t;
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
    #endif

    #ifndef T_NSF_WINDOW_STYLE
        #define T_NSF_WINDOW_STYLE
typedef enum {
    NSF_WDW_UNKNOWN = -1,
    NSF_WDW_NONE = (sfWindowStyle)sfNone,
    NSF_WDW_TITLEBAR = (sfWindowStyle)sfFullscreen,
    NSF_WDW_RESIZE = (sfWindowStyle)sfFullscreen,
    NSF_WDW_CLOSE = (sfWindowStyle)sfFullscreen,
    NSF_WDW_FULLSCREEN = (sfWindowStyle)sfFullscreen,
    NSF_WDW_DEFAULT_STYLE = (sfWindowStyle)sfDefaultStyle
} nsf_window_style_t;
    #endif

    #ifndef T_NSF_KEY
        #define T_NSF_KEY
typedef enum
{
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
    #endif

    #ifndef T_NSF_MOUSE
        #define T_NSF_MOUSE
typedef enum
{
    NSF_MSE_UNKNOWN = -1,
    NSF_MSE_LEFT,
    NSF_MSE_RIGHT,
    NSF_MSE_MIDDLE,
    NSF_MSE_X_BTTN_1,
    NSF_MSE_X_BTTN_2,
    NSF_MSE_COUNT
} nsf_mouse_t;
    #endif

    #ifndef T_NSF_MUSIC_STATUS
        #define T_NSF_MUSIC_STATUS
typedef enum {
    NSF_STT_SND_UNKNOWN = -1,
    NSF_STT_SND_STOPPED = (sfSoundStatus)sfStopped,
    NSF_STT_SND_PAUSED = (sfSoundStatus)sfPaused,
    NSF_STT_SND_PLAYING = (sfSoundStatus)sfPlaying
} nsf_sound_status_t;
    #endif

    #ifndef T_NSF_BUTTON_STATUS
        #define T_NSF_MUSIC_STATUS
typedef enum {
    NSF_STT_BTN_UNKNOWN = -1,
    NSF_STT_BTN_NONE,
    NSF_STT_BTN_HOVERED,
    NSF_STT_BTN_PRESSED
} nsf_button_status_t;
    #endif

    #ifndef T_NSF_WINDOW_ELEMENTS
        #define T_NSF_WINDOW_ELEMENTS
typedef enum
{
    NSF_UNKNOWN_ELEMENT = -1,
    NSF_SPRITE_ELEMENT,
    NSF_BUTTON_ELEMENT,
    NSF_SOUND_ELEMENT
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
    str_t name;
} nsf_texture_t;
    #endif

    #ifndef T_NSF_MUSIC
        #define T_NSF_MUSIC
typedef struct {
    sfMusic *music;
    str_t name;
} nsf_music_t;
    #endif

    #ifndef T_NSF_SOUND
        #define T_NSF_SOUND
typedef struct {
    sfSound *sound;
    sfSoundBuffer *buffer;
    str_t name;
} nsf_sound_t;
    #endif

    #ifndef T_NSF_BUTTON
        #define  T_NSF_BUTTON
typedef struct {
    sfRectangleShape *button;
    nsf_texture_t *texture;
    nsf_vector_t size;
    nsf_vector_t position;
    nsf_color_t fill_color;
    nsf_color_t outline_color;
    str_t name;
} nsf_button_t;
    #endif

    #ifndef T_NSF_SPRITE
        #define T_NSF_SPRITE
typedef struct {
    sfSprite *sprite;
    nsf_texture_t *texture;
    nsf_vector_t size;
    nsf_vector_t origin;
    nsf_vector_t position;
    float rotation;
    str_t name;
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
    nsf_uint_t width;
    nsf_uint_t height;
    nsf_uint_t bpp;
    nsf_uint_t fps;
} nsf_window_settings_t;
    #endif

    #ifndef T_NSF_WINDOW
        #define T_NSF_WINDOW
typedef struct {
    nsf_window_settings_t *settings;
    sfRenderWindow *window;
    nsf_uint_t fps;
    nsf_background_t *background;
    nsf_window_element_t **elements;
    str_t title;
} nsf_window_t;
    #endif

    #ifndef T_NSF_GAME
        #define T_NSF_GAME
typedef struct {
    nsf_window_t *window;
    nsf_music_t *music;
    nsf_uint_t allocations;
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
