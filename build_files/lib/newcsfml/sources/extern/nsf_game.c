/*
** EPITECH PROJECT, 2026
** EpitechBase - nsf_colors.c
** File description:
** <description>
*/

#include "../../includes/newcsfml.h"

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
    nsf_game_draw
};
