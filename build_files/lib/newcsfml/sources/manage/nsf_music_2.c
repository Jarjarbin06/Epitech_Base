/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include <SFML/Audio/Music.h>

#include "../../includes/newcsfml.h"

void nsf_music_looping(nsf_music_t *music, const bool looping)
{
    if (!music)
        return;
    sfMusic_setLoop(music->music, looping);
}

void nsf_music_volume(nsf_music_t *music, const float volume)
{
    if (!music)
        return;
    sfMusic_setVolume(music->music, volume);
}

nsf_sound_status_t nsf_music_get_status(nsf_music_t *music)
{
    if (!music)
        return NSF_STT_SND_UNKNOWN;
    return (nsf_sound_status_t)sfMusic_getStatus(music->music);
}
