/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.1
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

#include <SFML/Audio/Music.h>

#include "newcsfml/games/game.h"
#include "newcsfml/systems/utils.h"
#include "newcsfml/systems/other.h"
#include "newcsfml/audios/music.h"

nsf_music_t *nsf_music_create(const char path[], const char name[],
    nsf_game_t *game)
{
    nsf_music_t *new_music = malloc_any(sizeof(nsf_music_t));
    sfMusic *sf_music = sfMusic_createFromFile(path);
    const nsf_cstr_t name_str = str_dup((const char *const)name);

    if (NSF_UNLIKELY(!new_music || !sf_music || !name_str))
        return NULL;
    new_music->music = sf_music;
    new_music->name = name_str;
    if (game)
        game->allocations += 3;
    return new_music;
}

int nsf_music_destroy(nsf_music_t **music, nsf_game_t *game)
{
    if (NSF_UNLIKELY(!music || !*music))
        return EXIT_ERROR;
    if (NSF_LIKELY((*music)->music))
        sfMusic_destroy((*music)->music);
    if (NSF_LIKELY((*music)->name))
        free_any((nsf_str_t)(*music)->name);
    *music = free_any(*music);
    if (game)
        game->allocations -= 3;
    return EXIT_SUCCESS;
}
