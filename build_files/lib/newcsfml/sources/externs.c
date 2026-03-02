/*
** EPITECH PROJECT, 2026
** EpitechBase - nsf_colors.c
** File description:
** <description>
*/

#include "../includes/newcsfml.h"

const nsf_game_functions_t nsf_game = {
    nsf_game_create,
    nsf_game_destroy,
    nsf_game_display,
    nsf_game_isopen,
    nsf_game_close,
    nsf_game_get_event,
    nsf_game_set_window,
    nsf_game_get_window,
    nsf_game_add_sprite,
    nsf_game_add_button,
    nsf_game_get_sprite,
    nsf_game_get_button,
    nsf_game_draw
};

const nsf_window_functions_t nsf_window = {
    nsf_window_create,
    nsf_window_destroy,
    nsf_window_display,
    nsf_window_isopen,
    nsf_window_close,
    nsf_window_get_event,
    nsf_window_fill,
    nsf_window_draw_line,
    nsf_window_draw,
    nsf_window_add_sprite,
    nsf_window_add_button,
    nsf_window_get_sprite,
    nsf_window_get_button
};

const nsf_sprite_functions_t nsf_sprite = {
    nsf_sprite_create,
    nsf_sprite_destroy,
    nsf_sprite_set_texture,
    nsf_sprite_draw
};

const nsf_button_functions_t nsf_button = {
    nsf_button_create,
    nsf_button_destroy,
    nsf_button_set_texture,
    nsf_button_set_position,
    nsf_button_set_size,
    nsf_button_set_colors,
    nsf_button_isclicked,
    nsf_button_draw
};

const nsf_texture_functions_t nsf_texture = {
    nsf_texture_create,
    nsf_texture_destroy
};

const nsf_colors_t nsf_clr = {
    {0, 0, 0, 255},
    {255, 255, 255, 255},
    {255, 0, 0, 255},
    {0, 255, 0, 255},
    {0, 0, 255, 255},
    {255, 255, 0, 255},
    {255, 0, 255, 255},
    {0, 255, 255, 255},
{0, 0, 0, 0}
};

const nsf_event_functions_t nsf_event = {
    nsf_cmp_event,
    nsf_cmp_key
};

const nsf_nsf_functions_t nsf = {
    nsf_game,
    nsf_window,
    nsf_sprite,
    nsf_button,
    nsf_texture,
    nsf_clr,
    nsf_event,
};