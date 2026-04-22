/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include <SFML/Audio/Sound.h>

#include "../../includes/newcsfml.h"

void nsf_sound_play(nsf_sound_t *sound)
{
    if (!sound)
        return;
    sfSound_play(sound->sound);
}

void nsf_sound_pause(nsf_sound_t *sound)
{
    if (!sound)
        return;
    sfSound_pause(sound->sound);
}

void nsf_sound_stop(nsf_sound_t *sound)
{
    if (!sound)
        return;
    sfSound_stop(sound->sound);
}
