/*
** EPITECH PROJECT, 2025
** struct - nsf_sprite.c
** File description:
** <description>
*/

#include <SFML/Audio/Music.h>

#include "../../includes/newcsfml.h"

static int check_ptr(nsf_music_t **new_music, sfMusic **sf_music,
    str_t *name_str, nsf_game_t *game)
{
    return nsf_auto_free(3, (nsf_free_t[]){
        {*new_music && (!*sf_music || !*name_str),
            new_music, free_any},
        {*sf_music && (!*new_music || !*name_str),
            sf_music, sfMusic_destroy},
        {*name_str && (!*new_music || !*sf_music),
            name_str, free_any}
    }, game);
}

nsf_music_t *nsf_music_create(const char path[], const char name[],
    nsf_game_t *game)
{
    nsf_music_t *new_music = nsf_malloc_any(sizeof(nsf_music_t),
        game);
    sfMusic *sf_music = sfMusic_createFromFile(path);
    str_t name_str = str_strdup(name);

    if (check_ptr(&new_music, &sf_music, &name_str, game))
        return NULL;
    new_music->music = sf_music;
    new_music->name = name_str;
    return new_music;
}

int nsf_music_destroy(nsf_music_t **music, nsf_game_t *game)
{
    if (!music || !*music)
        return EXIT_ERROR;
    nsf_auto_free(3, (nsf_free_t[]){
        {(*music)->music, &(*music)->music, sfMusic_destroy},
        {(*music)->name, &(*music)->name, free_any}
    }, game);
    *music = nsf_free_any(music, game);
    return EXIT_SUCCESS;
}
