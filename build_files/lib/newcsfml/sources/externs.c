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
    nsf_game_add_sound,
    nsf_game_get_sprite,
    nsf_game_get_button,
    nsf_game_get_sound,
    nsf_game_play_sound,
    nsf_game_pause_sound,
    nsf_game_stop_sound,
    nsf_game_all_sound_volume,
    nsf_game_stop_all_sound,
    nsf_game_set_music,
    nsf_game_get_music,
    nsf_game_play_music,
    nsf_game_stop_music,
    nsf_game_set_music_volume,
    nsf_game_draw,
    nsf_game_update
};

const nsf_window_functions_t nsf_window = {
    nsf_window_create,
    nsf_window_destroy,
    nsf_window_display,
    nsf_window_isopen,
    nsf_window_close,
    nsf_window_get_event,
    nsf_window_fill,
    nsf_window_draw_lines,
    nsf_window_draw,
    nsf_window_add_sprite,
    nsf_window_add_button,
    nsf_window_add_sound,
    nsf_window_get_sprite,
    nsf_window_get_button,
    nsf_window_get_sound,
    nsf_window_play_sound,
    nsf_window_pause_sound,
    nsf_window_stop_sound,
    nsf_window_all_sound_volume,
    nsf_window_stop_all_sound,
    nsf_window_update_settings,
    nsf_window_get_mouse
};

const nsf_window_settings_functions_t nsf_window_settings = {
    nsf_window_settings_create,
    nsf_window_settings_destroy
};

const nsf_background_functions_t nsf_background = {
    nsf_background_create,
    nsf_background_destroy,
    nsf_background_draw
};

const nsf_sprite_functions_t nsf_sprite = {
    nsf_sprite_create,
    nsf_sprite_destroy,
    nsf_sprite_set_texture,
    nsf_sprite_set_scale,
    nsf_sprite_set_size,
    nsf_sprite_set_position,
    nsf_sprite_set_origin,
    nsf_sprite_get_texture,
    nsf_sprite_get_scale,
    nsf_sprite_get_size,
    nsf_sprite_get_position,
    nsf_sprite_get_origin,
    nsf_sprite_update,
    nsf_sprite_draw
};

const nsf_button_functions_t nsf_button = {
    nsf_button_create,
    nsf_button_destroy,
    nsf_button_set_texture,
    nsf_button_set_position,
    nsf_button_set_size,
    nsf_button_set_colors,
    nsf_button_get_state,
    nsf_button_draw
};

const nsf_texture_functions_t nsf_texture = {
    nsf_texture_create,
    nsf_texture_destroy
};

const nsf_music_functions_t nsf_music = {
    nsf_music_create,
    nsf_music_destroy,
    nsf_music_play,
    nsf_music_pause,
    nsf_music_stop,
    nsf_music_looping,
    nsf_music_volume,
    nsf_music_get_status,
};

const nsf_sound_functions_t nsf_sound = {
    nsf_sound_create,
    nsf_sound_destroy,
    nsf_sound_play,
    nsf_sound_pause,
    nsf_sound_stop,
    nsf_sound_looping,
    nsf_sound_volume,
    nsf_sound_get_status,
};

const nsf_colors_shortcut_t nsf_color = {
    {0, 0, 0, 255},
    {255, 255, 255, 255},
    {255, 0, 0, 255},
    {0, 255, 0, 255},
    {0, 0, 255, 255},
    {255, 255, 0, 255},
    {255, 0, 255, 255},
    {0, 255, 255, 255},
    {100, 100, 100, 255},
    {0, 0, 0, 0}
};

const nsf_vector_functions_t nsf_vector = {
    nsf_fvector_empty,
    nsf_fvector_from_i,
    nsf_fvector_from_u,
    nsf_fvector_copy,
    nsf_ivector_empty,
    nsf_ivector_from_f,
    nsf_ivector_from_u,
    nsf_ivector_copy,
    nsf_uvector_empty,
    nsf_uvector_from_f,
    nsf_uvector_from_i,
    nsf_uvector_copy,
    nsf_vector_add,
    nsf_vector_sub,
    nsf_vector_mul,
    nsf_vector_div,
    nsf_vector_neg,
    nsf_vector_len,
    nsf_vector_norm,
    nsf_vector_dist_to,
    nsf_vector_dir_to,
    nsf_vector_dot,
    nsf_vector_cross,
    nsf_vector_get_angle,
    nsf_vector_rotate,
    nsf_vector_print
};

const nsf_event_functions_t nsf_event = {
    nsf_event_cmp,
    nsf_event_cmp_key,
    nsf_event_get_mouse_move,
    nsf_event_get_mouse_wheel
};

const nsf_nsf_functions_t nsf = {
    nsf_game,
    nsf_window,
    nsf_window_settings,
    nsf_sprite,
    nsf_button,
    nsf_texture,
    nsf_music,
    nsf_sound,
    nsf_color,
    nsf_vector,
    nsf_event,
};
