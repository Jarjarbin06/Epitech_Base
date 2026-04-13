/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include "../../includes/newcsfml.h"

void nsf_game_set_music(nsf_game_t *game, nsf_music_t *music)
{
    if (!game || !music)
        return;
    game->music = music;
}

void nsf_game_play_music(nsf_game_t *game)
{
    if (!game || !game->music)
        return;
    nsf_music_play(game->music);
}

void nsf_game_stop_music(nsf_game_t *game)
{
    if (!game || !game->music)
        return;
    nsf_music_stop(game->music);
}

void nsf_game_set_music_volume(nsf_game_t *game, const float volume)
{
    if (!game || !game->music)
        return;
    nsf_music_volume(game->music, volume);
}
