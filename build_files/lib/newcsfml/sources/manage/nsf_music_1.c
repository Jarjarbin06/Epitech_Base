/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include <SFML/Audio/Music.h>

#include "../../includes/newcsfml.h"

void nsf_music_play(nsf_music_t *music)
{
    if (!music)
        return;
    sfMusic_play(music->music);
}

void nsf_music_pause(nsf_music_t *music)
{
    if (!music)
        return;
    sfMusic_pause(music->music);
}

void nsf_music_stop(nsf_music_t *music)
{
    if (!music)
        return;
    sfMusic_stop(music->music);
}
