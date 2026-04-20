/*
** EPITECH PROJECT, 2025
** struct - nsf_sprite.c
** File description:
** <description>
*/

#include <SFML/Audio/Music.h>

#include "../../includes/newcsfml.h"

nsf_music_t *nsf_music_create(const char path[], const char name[],
    nsf_game_t *game)
{
    nsf_music_t *new_music = malloc_any(sizeof(nsf_music_t));
    sfMusic *sf_music = sfMusic_createFromFile(path);
    str_t name_str = str_strdup(name);

    if (!new_music || !sf_music || !name_str)
        return NULL;
    new_music->music = sf_music;
    new_music->name = name_str;
    if (game)
        game->allocations += 3;
    return new_music;
}

int nsf_music_destroy(nsf_music_t **music, nsf_game_t *game)
{
    if (!music || !*music)
        return EXIT_ERROR;
    if ((*music)->music)
        sfMusic_destroy((*music)->music);
    if ((*music)->name)
        free_any((*music)->name);
    *music = free_any(*music);
    game->allocations -= 3;
    return EXIT_SUCCESS;
}
