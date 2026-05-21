/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.7
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

#ifndef NEWCSFML_SOUND_H
    #define NEWCSFML_SOUND_H

    #include <SFML/Audio/Sound.h>

    #include <stdbool.h>
    #include <stddef.h>

/// MACRO ///
    #define NSF_SOUND "NSF_SOUND"

/// TMP ///
typedef const char *cstr_t;
typedef struct nsf_game_s nsf_game_t;
typedef const char *nsf_cstr_t;

/// TYPEDEFS ///
typedef struct nsf_sound_s {
    sfSound *sound;
    sfSoundBuffer *buffer;
    nsf_cstr_t name;
} nsf_sound_t;

typedef enum nsf_sound_status_e {
    NSF_STT_SND_UNKNOWN = -1,
    NSF_STT_SND_STOPPED,
    NSF_STT_SND_PAUSED,
    NSF_STT_SND_PLAYING
} nsf_sound_status_t;

/// PROTOTYPES ///
// STRUCT //
nsf_sound_t *nsf_sound_create(const char path[], const char name[],
    nsf_game_t *game);
int nsf_sound_destroy(nsf_sound_t **sound, nsf_game_t *game);

// MANAGE //
void nsf_sound_play(const nsf_sound_t *sound);
void nsf_sound_pause(const nsf_sound_t *sound);
void nsf_sound_stop(const nsf_sound_t *sound);
void nsf_sound_set_looping(const nsf_sound_t *sound, bool looping);
void nsf_sound_set_volume(const nsf_sound_t *sound, float volume);
nsf_sound_status_t nsf_sound_get_status(const nsf_sound_t *sound);

#endif
