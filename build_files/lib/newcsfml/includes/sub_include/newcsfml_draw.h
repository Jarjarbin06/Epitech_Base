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

    #ifndef P_NSF_WINDOW_DRAW_LINE
        #define P_NSF_WINDOW_DRAW_LINE
void nsf_window_draw_line(const nsf_window_t *window,
    nsf_vector a, nsf_vector b, nsf_color_t color);
    #endif

    #ifndef P_NSF_WINDOW_FILL
        #define P_NSF_WINDOW_FILL
void nsf_window_fill(const nsf_window_t *window, nsf_color_t color);
    #endif

    #ifndef P_NSF_SPRITE_DRAW
        #define P_NSF_SPRITE_DRAW
int nsf_sprite_draw(nsf_sprite_t *sprite, nsf_window_t *window);
    #endif

#endif
