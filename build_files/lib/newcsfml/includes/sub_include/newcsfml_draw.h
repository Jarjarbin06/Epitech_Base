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

void nsf_game_draw(nsf_game_t *game);
int nsf_window_draw_lines(const nsf_window_t *window, size_t len,
    const nsf_fvector_t points[], const nsf_color_t color[]);
void nsf_window_fill(const nsf_window_t *window, const nsf_color_t color[]);
void nsf_window_draw(nsf_window_t *window);
void nsf_background_draw(nsf_background_t *background, nsf_window_t *window);
void nsf_sprite_draw(nsf_sprite_t *sprite, nsf_window_t *window);
void nsf_button_draw(nsf_button_t *button, nsf_window_t *window);

#endif
