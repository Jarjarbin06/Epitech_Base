/*
** EPITECH PROJECT, 2025
** sub_includes - newcsfml_prototype.h
** File description:
** <description>
*/

// Prototype //
#ifndef NEWCSFML_DRAW
    #define NEWCSFML_DRAW

    #include "newcsfml_typedef.h"

    #ifndef P_NSF_GAME_DRAW
        #define  P_NSF_GAME_DRAW
void nsf_game_draw(nsf_game_t *game);
    #endif

    #ifndef P_NSF_WINDOW_DRAW_LINE
        #define P_NSF_WINDOW_DRAW_LINE
void nsf_window_draw_line(const nsf_window_t *window,
    const nsf_vector a[], const nsf_vector b[], const nsf_color_t color[]);
    #endif

    #ifndef P_NSF_WINDOW_FILL
        #define P_NSF_WINDOW_FILL
void nsf_window_fill(const nsf_window_t *window, const nsf_color_t color[]);
    #endif

    #ifndef P_NSF_WINDOW_DRAW
        #define P_NSF_WINDOW_DRAW
void nsf_window_draw(nsf_window_t *window);
    #endif

    #ifndef P_NSF_SPRITE_DRAW
        #define P_NSF_SPRITE_DRAW
void nsf_sprite_draw(nsf_sprite_t *sprite, nsf_window_t *window);
    #endif

    #ifndef P_NSF_BUTTON_DRAW
        #define P_NSF_BUTTON_DRAW
void nsf_button_draw(nsf_button_t *button, nsf_window_t *window);
    #endif

#endif
