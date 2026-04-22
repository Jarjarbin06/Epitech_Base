/*
** EPITECH PROJECT, 2025
** struct - nsf_sprite.c
** File description:
** <description>
*/

#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>

#include "../../includes/newcsfml.h"

nsf_sound_t *nsf_sound_create(const char path[], const char name[],
                              nsf_game_t *game)
{
    nsf_sound_t *new_sound = malloc_any(sizeof(nsf_sound_t));
    sfSoundBuffer *sf_sound_buffer = sfSoundBuffer_createFromFile(path);
    sfSound *sf_sound = sfSound_create();
    str_t name_str = str_strdup(name);

    if (!new_sound || !sf_sound || !sf_sound_buffer || !name_str)
        return NULL;
    sfSound_setBuffer(sf_sound, sf_sound_buffer);
    new_sound->sound = sf_sound;
    new_sound->buffer = sf_sound_buffer;
    new_sound->name = name_str;
    if (game)
        game->allocations += 4;
    return new_sound;
}

int nsf_sound_destroy(nsf_sound_t **sound, nsf_game_t *game)
{
    if (!sound || !*sound)
        return EXIT_ERROR;
    if ((*sound)->sound)
        sfSound_destroy((*sound)->sound);
    if ((*sound)->buffer)
        sfSoundBuffer_destroy((*sound)->buffer);
    if ((*sound)->name)
        free_any((*sound)->name);
    *sound = free_any(*sound);
    game->allocations -= 4;
    return EXIT_SUCCESS;
}
