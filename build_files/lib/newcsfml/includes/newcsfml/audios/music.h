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

#ifndef NEWCSFML_MUSIC_H
    #define NEWCSFML_MUSIC_H

    #include <SFML/Audio/Music.h>

    #include <stdbool.h>

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
typedef struct nsf_game_s nsf_game_t;
typedef const char *cstr_t;
typedef const char *nsf_cstr_t;
typedef enum nsf_sound_status_e nsf_sound_status_t;

/// TYPEDEFS ///
typedef struct nsf_music_s {
    sfMusic *music;
    nsf_cstr_t name;
} nsf_music_t;

/// PROTOTYPES ///
// STRUCT //
nsf_music_t *nsf_music_create(const char path[], const char name[],
    nsf_game_t *game);
int nsf_music_destroy(nsf_music_t **music, nsf_game_t *game);

// MANAGE //
void nsf_music_play(const nsf_music_t *music);
void nsf_music_pause(const nsf_music_t *music);
void nsf_music_stop(const nsf_music_t *music);
void nsf_music_set_looping(const nsf_music_t *music, bool looping);
void nsf_music_set_volume(const nsf_music_t *music, float volume);
nsf_sound_status_t nsf_music_get_status(const nsf_music_t *music);

#endif
