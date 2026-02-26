/*
** EPITECH PROJECT, 2025
** includes - newcsfml.h
** File description:
** <description>
*/

// ALL INCLUDE //
#ifndef NEWCSFML
    #define NEWCSFML

    #include "sub_include/newcsfml_define.h"
    #include "sub_include/newcsfml_typedef.h"
    #include "sub_include/newcsfml_prototype.h"
    #include "sub_include/newcsfml_draw.h"
    #include "sub_include/newcsfml_manage.h"
    #include "sub_include/newcsfml_other.h"
    #include "sub_include/newcsfml_struct.h"

    #ifndef T_NSF_COLORS_STRUCT
        #define T_NSF_COLORS_STRUCT
extern const nsf_colors_t nsf_clr;
    #endif

    #ifndef T_NSF_GAMES_STRUCT
        #define T_NSF_GAMES_STRUCT
extern const nsf_game_functions_t nsf_game;
    #endif

    #ifndef T_NSF_WINDOWS_STRUCT
        #define T_NSF_WINDOWS_STRUCT
extern const nsf_window_functions_t nsf_window;
    #endif

    #ifndef T_NSF_SPRITES_STRUCT
        #define T_NSF_SPRITES_STRUCT
extern const nsf_sprite_functions_t nsf_sprite;
    #endif

    #ifndef T_NSF_TEXTURES_STRUCT
        #define T_NSF_TEXTURES_STRUCT
extern const nsf_texture_functions_t nsf_texture;
    #endif

    #ifndef T_NSF_EVENTS_STRUCT
        #define T_NSF_EVENTS_STRUCT
extern const nsf_event_functions_t nsf_event;
    #endif

#endif
