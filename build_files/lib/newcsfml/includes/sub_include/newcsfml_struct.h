/*
** EPITECH PROJECT, 2025
** sub_includes - newcsfml_prototype.h
** File description:
** <description>
*/

// Prototype //
#ifndef NEWCSFML_STRUCT
    #define NEWCSFML_STRUCT

    #include "newcsfml_typedef.h"

nsf_game_t *nsf_game_create(void);
int nsf_game_destroy(nsf_game_t **game);

nsf_window_t *nsf_window_create(const nsf_window_settings_t settings[],
    char title[], nsf_window_style_t window_style, nsf_game_t *game);
int nsf_window_destroy(nsf_window_t **window, nsf_game_t *game);

nsf_window_settings_t *nsf_window_settings_create(
    const nsf_window_settings_t settings[], nsf_game_t *game);
int nsf_window_settings_destroy(nsf_window_settings_t **settings,
    nsf_game_t *game);

nsf_background_t *nsf_background_create(const char path[],
    nsf_window_t *window, nsf_game_t *game);
int nsf_background_destroy(nsf_background_t **background, nsf_game_t *game);

nsf_sprite_t *nsf_sprite_create(const char name[], nsf_game_t *game);
int nsf_sprite_destroy(nsf_sprite_t **sprite, nsf_game_t *game);

nsf_texture_t *nsf_texture_create(const char path[], const char name[],
    nsf_game_t *game);
int nsf_texture_destroy(nsf_texture_t **texture, nsf_game_t *game);

nsf_button_t *nsf_button_create(const char name[], nsf_game_t *game);
int nsf_button_destroy(nsf_button_t **button, nsf_game_t *game);

nsf_music_t *nsf_music_create(const char path[], const char name[],
    nsf_game_t *game);
int nsf_music_destroy(nsf_music_t **music, nsf_game_t *game);

nsf_sound_t *nsf_sound_create(const char path[], const char name[],
    nsf_game_t *game);
int nsf_sound_destroy(nsf_sound_t **sound, nsf_game_t *game);

#endif
