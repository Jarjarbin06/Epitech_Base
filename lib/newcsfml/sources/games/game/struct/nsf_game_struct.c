/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.8
** Author: Jarjarbin06
** Licence: GPL v3
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

#include "newcsfml/audios/music.h"
#include "newcsfml/games/window.h"
#include "newcsfml/systems/other.h"
#include "newcsfml/games/game.h"
#include "newcsfml/systems/clock.h"
#include "newcsfml/systems/utils.h"

nsf_game_t *nsf_game_create(void)
{
    nsf_game_t *new_game = malloc_any(sizeof(nsf_game_t));

    if (NSF_UNLIKELY(!new_game))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_GAME, __FUNCTION__,
            "alloc failed");
    new_game->allocations = 1;
    new_game->window = NULL;
    new_game->music = NULL;
    new_game->data = NULL;
    new_game->clock = NULL;
    new_game->real_fps.fps = 0;
    new_game->real_fps.draw_count = 0;
    new_game->real_fps.clock = nsf_clock_create("fps_clock", new_game);
    return new_game;
}

int nsf_game_destroy(nsf_game_t **game)
{
    int allocations = 0;

    if (NSF_UNLIKELY(!game || !*game)) {
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_GAME, __FUNCTION__,
            "pointer corrupted");
        return -1;
    }
    allocations = (*game)->allocations;
    if (NSF_LIKELY((*game)->window))
        nsf_window_destroy(&(*game)->window, *game);
    if (NSF_LIKELY((*game)->music))
        nsf_music_destroy(&(*game)->music, *game);
    if (NSF_LIKELY((*game)->clock))
        nsf_clock_destroy(&(*game)->clock, *game);
    if (NSF_LIKELY((*game)->real_fps.clock))
        nsf_clock_destroy(&(*game)->real_fps.clock, *game);
    *game = free_any(*game);
    allocations--;
    return allocations;
}
