/*
** EPITECH PROJECT, 2025
** struct - nsf_sprite.c
** File description:
** <description>
*/

#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>

#include "../../includes/newcsfml.h"

static int check_ptr_1(nsf_sound_t **new_sound, sfSound **sf_sound,
    sfSoundBuffer **sf_sound_buffer, nsf_game_t *game)
{
    return nsf_auto_free(3, (nsf_free_t[]){
        {*new_sound && (!*sf_sound || !*sf_sound_buffer),
            new_sound, free_any},
        {*sf_sound && (!*new_sound || !*sf_sound_buffer),
            sf_sound, sfMusic_destroy},
        {*sf_sound_buffer && (!*new_sound || !*sf_sound),
            sf_sound_buffer, free_any}
    }, game);
}

static int check_ptr_2(str_t *name_str, nsf_game_t *game)
{
    return nsf_auto_free(1, (nsf_free_t[]){
        {*name_str, name_str, free_any}
    }, game);
}

nsf_sound_t *nsf_sound_create(const char path[], const char name[],
    nsf_game_t *game)
{
    nsf_sound_t *new_sound = nsf_malloc_any(sizeof(nsf_sound_t),
        game);
    sfSoundBuffer* sf_sound_buffer = sfSoundBuffer_createFromFile(path);
    sfSound *sf_sound = sfSound_create();
    str_t name_str = str_strdup(name);

    if (check_ptr_1(&new_sound, &sf_sound, &sf_sound_buffer, game) ||
        check_ptr_2(&name_str, game))
        return NULL;
    sfSound_setBuffer(sf_sound, sf_sound_buffer);
    new_sound->sound = sf_sound;
    new_sound->buffer = sf_sound_buffer;
    new_sound->name = name_str;
    return new_sound;
}

int nsf_sound_destroy(nsf_sound_t **sound, nsf_game_t *game)
{
    if (!sound || !*sound)
        return EXIT_ERROR;
    nsf_auto_free(4, (nsf_free_t[]){
        {(*sound)->buffer, &(*sound)->buffer, sfSoundBuffer_destroy},
        {(*sound)->sound, &(*sound)->sound, sfSound_destroy},
        {(*sound)->name, &(*sound)->name, free_any},
        {*sound, &sound, free_any}
    }, game);
    return EXIT_SUCCESS;
}
