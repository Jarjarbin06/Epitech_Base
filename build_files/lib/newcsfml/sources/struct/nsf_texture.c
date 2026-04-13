/*
** EPITECH PROJECT, 2025
** struct - nsf_sprite.c
** File description:
** <description>
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>

#include "../../includes/newcsfml.h"

static int check_ptr(nsf_texture_t **new_texture, sfTexture **sf_texture,
    str_t *name_str, nsf_game_t *game)
{
    return nsf_auto_free(3, (nsf_free_t[]){
        {*new_texture && (!*sf_texture || !*name_str),
            new_texture, free_any},
        {*sf_texture && (!*new_texture || !*name_str),
            sf_texture, sfTexture_destroy},
        {*name_str && (!*new_texture || !*sf_texture),
            name_str, free_any}
    }, game);
}

nsf_texture_t *nsf_texture_create(const char path[], const char name[],
    nsf_game_t *game)
{
    nsf_texture_t *new_texture = nsf_malloc_any(sizeof(nsf_texture_t),
        game);
    sfTexture *sf_texture = sfTexture_createFromFile(path, NULL);
    str_t name_str = str_strdup(name);

    if (check_ptr(&new_texture, &sf_texture, &name_str, game))
        return NULL;
    new_texture->texture = sf_texture;
    new_texture->name = name_str;
    return new_texture;
}

int nsf_texture_destroy(nsf_texture_t **texture, nsf_game_t *game)
{
    if (!texture || !*texture)
        return EXIT_ERROR;
    nsf_auto_free(3, (nsf_free_t[]){
        {(*texture)->texture, &(*texture)->texture, sfTexture_destroy},
        {(*texture)->name, &(*texture)->name, free_any},
        {*texture, &texture, free_any}
    }, game);
    return EXIT_SUCCESS;
}
