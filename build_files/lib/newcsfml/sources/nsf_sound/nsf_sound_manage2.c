/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include <SFML/Audio/Sound.h>

#include "../../includes/newcsfml.h"

void nsf_sound_looping(nsf_sound_t *sound, const bool looping)
{
    if (!sound)
        return;
    sfSound_setLoop(sound->sound, looping);
}

void nsf_sound_volume(nsf_sound_t *sound, const float volume)
{
    if (!sound)
        return;
    sfSound_setVolume(sound->sound, volume);
}

nsf_sound_status_t nsf_sound_get_status(nsf_sound_t *sound)
{
    if (!sound)
        return NSF_STT_SND_UNKNOWN;
    return (nsf_sound_status_t)sfSound_getStatus(sound->sound);
}
