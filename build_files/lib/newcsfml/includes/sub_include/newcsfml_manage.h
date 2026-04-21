/*
** EPITECH PROJECT, 2025
** sub_includes - newcsfml_prototype.h
** File description:
** <description>
*/

// Prototype //
#ifndef NEWCSFML_MANAGE
    #define NEWCSFML_MANAGE

    #include "newcsfml_typedef.h"

bool nsf_event_cmp(const nsf_event_t *event, nsf_event_type_t event_type);
bool nsf_event_cmp_key(const nsf_event_t *event, nsf_key_code_t key_code);
void nsf_event_get_mouse_move(const nsf_event_t *event,
    nsf_ivector_t vect[]);
float nsf_event_get_mouse_wheel(const nsf_event_t *event);

int nsf_game_display(nsf_game_t *game);
bool nsf_game_isopen(nsf_game_t *game);
void nsf_game_close(nsf_game_t *game);
bool nsf_game_get_event(nsf_game_t *game, nsf_event_t *event);
void nsf_game_set_window(nsf_game_t *game, nsf_window_t *window);
nsf_window_t *nsf_game_get_window(nsf_game_t *game);
void nsf_game_add_sprite(nsf_game_t *game, nsf_sprite_t *sprite);
void nsf_game_add_button(nsf_game_t *game, nsf_button_t *button);
void nsf_game_add_sound(nsf_game_t *game, nsf_sound_t *sound);
nsf_sprite_t *nsf_game_get_sprite(nsf_game_t *game, const char sprite_name[]);
nsf_button_t *nsf_game_get_button(nsf_game_t *game, const char button_name[]);
nsf_sound_t *nsf_game_get_sound(nsf_game_t *game, const char sound_name[]);
void nsf_game_set_music(nsf_game_t *game, nsf_music_t *music);
nsf_music_t *nsf_game_get_music(nsf_game_t *game);
void nsf_game_play_music(nsf_game_t *game);
void nsf_game_stop_music(nsf_game_t *game);
void nsf_game_set_music_volume(nsf_game_t *game, float volume);
int nsf_game_play_sound(nsf_game_t *game, const char sound_name[]);
int nsf_game_pause_sound(nsf_game_t *game, const char sound_name[]);
int nsf_game_stop_sound(nsf_game_t *game, const char sound_name[]);
int nsf_game_all_sound_volume(nsf_game_t *game, float volume);
int nsf_game_stop_all_sound(nsf_game_t *game);
int nsf_game_update(nsf_game_t *game);

int nsf_window_display(nsf_window_t *window);
bool nsf_window_isopen(nsf_window_t *window);
void nsf_window_close(nsf_window_t *window);
bool nsf_window_get_event(nsf_window_t *window, nsf_event_t *event);
void nsf_window_add_sprite(nsf_window_t *window, nsf_sprite_t *sprite,
    nsf_game_t *game);
void nsf_window_add_button(nsf_window_t *window, nsf_button_t *button,
    nsf_game_t *game);
void nsf_window_add_sound(nsf_window_t *window, nsf_sound_t *sound,
    nsf_game_t *game);
nsf_sprite_t *nsf_window_get_sprite(nsf_window_t *window,
    const char sprite_name[]);
nsf_button_t *nsf_window_get_button(nsf_window_t *window,
    const char button_name[]);
nsf_sound_t *nsf_window_get_sound(nsf_window_t *window,
    const char sound_name[]);
int nsf_window_play_sound(nsf_window_t *window, const char sound_name[]);
int nsf_window_pause_sound(nsf_window_t *window, const char sound_name[]);
int nsf_window_stop_sound(nsf_window_t *window, const char sound_name[]);
int nsf_window_all_sound_volume(nsf_window_t *window, float volume);
int nsf_window_stop_all_sound(nsf_window_t *window);
int nsf_window_update_settings(nsf_window_t *window);
void nsf_window_get_mouse(nsf_window_t *window, nsf_ivector_t vect[]);

void nsf_sprite_set_texture(nsf_sprite_t *sprite, nsf_texture_t *texture);
void nsf_sprite_set_scale(nsf_sprite_t *sprite, nsf_fvector_t scale[]);
void nsf_sprite_set_size(nsf_sprite_t *sprite, nsf_uvector_t size[]);
void nsf_sprite_set_position(nsf_sprite_t *sprite, nsf_fvector_t position[]);
void nsf_sprite_set_origin(nsf_sprite_t *sprite, nsf_fvector_t origin[]);
nsf_texture_t *nsf_sprite_get_texture(nsf_sprite_t *sprite);
void nsf_sprite_get_scale(nsf_sprite_t *sprite, nsf_fvector_t *out);
void nsf_sprite_get_size(nsf_sprite_t *sprite, nsf_uvector_t *out);
void nsf_sprite_get_position(nsf_sprite_t *sprite, nsf_fvector_t *out);
void nsf_sprite_get_origin(nsf_sprite_t *sprite, nsf_fvector_t *out);
void nsf_sprite_update(nsf_sprite_t *sprite);

void nsf_button_set_texture(nsf_button_t *button, nsf_texture_t *texture);
void nsf_button_set_position(nsf_button_t *button,
    const nsf_fvector_t position[]);
void nsf_button_set_size(nsf_button_t *button, const nsf_fvector_t size[]);
void nsf_button_set_colors(nsf_button_t *button,
    const nsf_color_t fill_color[], const nsf_color_t outline_color[],
    nsf_uint_t outline_thickness);
nsf_button_status_t nsf_button_get_state(nsf_button_t *button,
    nsf_window_t *window, nsf_mouse_t mouse_button);

void nsf_music_play(nsf_music_t *music);
void nsf_music_pause(nsf_music_t *music);
void nsf_music_stop(nsf_music_t *music);
void nsf_music_looping(nsf_music_t *music, bool looping);
void nsf_music_volume(nsf_music_t *music, float volume);
nsf_sound_status_t nsf_music_get_status(nsf_music_t *music);

void nsf_sound_play(nsf_sound_t *sound);
void nsf_sound_pause(nsf_sound_t *sound);
void nsf_sound_stop(nsf_sound_t *sound);
void nsf_sound_looping(nsf_sound_t *sound, bool looping);
void nsf_sound_volume(nsf_sound_t *sound, float volume);
nsf_sound_status_t nsf_sound_get_status(nsf_sound_t *sound);

void nsf_fvector_empty(nsf_fvector_t *out);
void nsf_fvector_from_i(const nsf_ivector_t v[],
    nsf_fvector_t *out);
void nsf_fvector_from_u(const nsf_uvector_t v[],
    nsf_fvector_t *out);
void nsf_fvector_copy(const nsf_fvector_t v[],
    nsf_fvector_t *out);
void nsf_ivector_empty(nsf_ivector_t *out);
void nsf_ivector_from_f(const nsf_fvector_t v[],
    nsf_ivector_t *out);
void nsf_ivector_from_u(const nsf_uvector_t v[],
    nsf_ivector_t *out);
void nsf_ivector_copy(const nsf_ivector_t v[],
    nsf_ivector_t *out);
void nsf_uvector_empty(nsf_uvector_t *out);
void nsf_uvector_from_f(const nsf_fvector_t v[],
    nsf_uvector_t *out);
void nsf_uvector_from_i(const nsf_ivector_t v[],
    nsf_uvector_t *out);
void nsf_uvector_copy(const nsf_uvector_t v[],
    nsf_uvector_t *out);
void nsf_vector_add(const nsf_fvector_t a[],
    const nsf_fvector_t b[], nsf_fvector_t *out);
void nsf_vector_sub(const nsf_fvector_t a[],
    const nsf_fvector_t b[], nsf_fvector_t *out);
void nsf_vector_mul(const nsf_fvector_t v[], float scalar,
    nsf_fvector_t *out);
void nsf_vector_div(const nsf_fvector_t v[], float scalar,
    nsf_fvector_t *out);
void nsf_vector_neg(const nsf_fvector_t v[], nsf_fvector_t *out);
float nsf_vector_len(const nsf_fvector_t v[]);
void nsf_vector_norm(const nsf_fvector_t v[], nsf_fvector_t *out);
float nsf_vector_dist_to(const nsf_fvector_t a[],
    const nsf_fvector_t b[]);
void nsf_vector_dir_to(const nsf_fvector_t a[],
    const nsf_fvector_t b[], nsf_fvector_t *out);
float nsf_vector_dot(const nsf_fvector_t a[],
    const nsf_fvector_t b[]);
float nsf_vector_cross(const nsf_fvector_t a[],
    const nsf_fvector_t b[]);
float nsf_vector_get_angle(const nsf_fvector_t v[]);
void nsf_vector_rotate(const nsf_fvector_t v[], float angle,
    nsf_fvector_t *out);
void nsf_vector_print(const nsf_fvector_t v[]);

#endif
