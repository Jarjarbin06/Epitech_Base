/*
** EPITECH PROJECT, 2026
** EpitechBase - nsf_colors.c
** File description:
** <description>
*/

#include "../../includes/newcsfml.h"

const nsf_window_functions_t nsf_window = {
    nsf_window_create,
    nsf_window_destroy,
    nsf_window_display,
    nsf_window_isopen,
    nsf_window_close,
    nsf_window_get_event,
    nsf_window_fill,
    nsf_window_draw_line
};
