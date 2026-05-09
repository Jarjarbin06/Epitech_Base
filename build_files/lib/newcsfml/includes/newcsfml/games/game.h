/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.3
** Author: Jarjarbin06
** License: GPL v3
** •
** This library is inspired by SFML/CSFML and is designed for
** educational and game-development purposes.
** •
** It provides higher-level abstractions over CSFML to reduce
** boilerplate code and enforce safer usage patterns.
** •
** WARNING:
** This is NOT the original SFML/CSFML library.
** It is a custom implementation layer built on top of CSFML.
*/

#ifndef NEWCSFML_GAME_H
    #define NEWCSFML_GAME_H

    #include <SFML/Window/Event.h>

    #include <stdbool.h>
    #include <stddef.h>

    #ifndef EXIT_D
        #define EXIT_D

        #ifndef EXIT_SUCCESS
            #define EXIT_SUCCESS 0
        #endif

        #ifndef EXIT_ERROR
            #define EXIT_ERROR 84
        #endif

    #endif

/// TMP ///
typedef struct nsf_sound_s nsf_sound_t;
typedef struct nsf_music_s nsf_music_t;
typedef unsigned int nsf_uint_t;
typedef struct nsf_background_s nsf_background_t;
typedef struct nsf_window_s nsf_window_t;
typedef struct nsf_sprite_s nsf_sprite_t;
typedef struct nsf_button_s nsf_button_t;
typedef struct nsf_clock_s nsf_clock_t;
typedef struct nsf_text_s nsf_text_t;
typedef sfEvent nsf_event_t;
typedef struct nsf_particle_s nsf_particle_t;

/// TYPEDEFS ///
typedef struct {
    nsf_uint_t fps;
    nsf_uint_t draw_count;
    nsf_clock_t *clock;
} nsf_game_fps_t;

typedef struct nsf_game_s {
    nsf_window_t *window;
    nsf_music_t *music;
    nsf_clock_t *clock;
    nsf_game_fps_t real_fps;
    int allocations;
    void *data;
} nsf_game_t;

/// PROTOTYPES ///
// STRUCT //
nsf_game_t *nsf_game_create(void);
int nsf_game_destroy(nsf_game_t **game);

// MANAGE //
int nsf_game_display(const nsf_game_t *game);
bool nsf_game_isopen(const nsf_game_t *game);
void nsf_game_close(const nsf_game_t *game);
bool nsf_game_get_event(const nsf_game_t *game, nsf_event_t *event);
void nsf_game_set_window(nsf_game_t *game, nsf_window_t *window);
nsf_window_t *nsf_game_get_window(const nsf_game_t *game);
void nsf_game_add_sprite(nsf_game_t *game, nsf_sprite_t *sprite);
void nsf_game_add_button(nsf_game_t *game, nsf_button_t *button);
void nsf_game_add_sound(nsf_game_t *game, nsf_sound_t *sound);
void nsf_game_add_text(nsf_game_t *game, nsf_text_t *text);
void nsf_game_add_particle(nsf_game_t *game, nsf_particle_t *particle);
nsf_sprite_t *nsf_game_get_sprite(const nsf_game_t *game,
    const char sprite_name[]);
nsf_button_t *nsf_game_get_button(const nsf_game_t *game,
    const char button_name[]);
nsf_sound_t *nsf_game_get_sound(const nsf_game_t *game,
    const char sound_name[]);
nsf_text_t *nsf_game_get_text(const nsf_game_t *game, const char text_name[]);
nsf_particle_t *nsf_game_get_particle(const nsf_game_t *game,
    const char particle_name[]);
void nsf_game_set_background(const nsf_game_t *game,
    nsf_background_t *background);
const nsf_background_t *nsf_game_get_background(const nsf_game_t *game);
void nsf_game_set_clock(nsf_game_t *game, nsf_clock_t *clock);
const nsf_clock_t *nsf_game_get_clock(const nsf_game_t *game);
bool nsf_game_update_clock(nsf_game_t *game);
void nsf_game_wait_new_loop(nsf_game_t *game);
void nsf_game_set_music(nsf_game_t *game, nsf_music_t *music);
nsf_music_t *nsf_game_get_music(const nsf_game_t *game);
void nsf_game_play_music(const nsf_game_t *game);
void nsf_game_stop_music(const nsf_game_t *game);
void nsf_game_set_music_volume(const nsf_game_t *game, float volume);
int nsf_game_play_sound(const nsf_game_t *game, const char sound_name[]);
int nsf_game_pause_sound(const nsf_game_t *game, const char sound_name[]);
int nsf_game_stop_sound(const nsf_game_t *game, const char sound_name[]);
int nsf_game_all_sound_volume(const nsf_game_t *game, float volume);
int nsf_game_stop_all_sound(const nsf_game_t *game);
int nsf_game_update(const nsf_game_t *game);

// DRAW //
void nsf_game_draw(nsf_game_t *game);

#endif
