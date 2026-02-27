/*
** EPITECH PROJECT, 2026
** EpitechBase - nsf_colors.c
** File description:
** <description>
*/

#include "../../includes/newcsfml.h"

const nsf_button_functions_t nsf_button = {
    nsf_button_create,
    nsf_button_destroy,
    nsf_button_set_texture,
    nsf_button_set_position,
    nsf_button_set_size,
    nsf_button_set_colors,
    nsf_button_check_click,
    nsf_button_draw
};
