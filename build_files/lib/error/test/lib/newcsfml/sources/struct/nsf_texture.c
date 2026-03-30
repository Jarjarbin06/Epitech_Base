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
    str *name_str, nsf_game_t *game)
{
    return nsf_auto_free(3, (free_t[]){
        {*new_texture && (!*sf_texture || !*name_str),
            new_texture, (void_func_t)free_any},
        {*sf_texture && (!*new_texture || !*name_str),
            sf_texture, (void_func_t)sfTexture_destroy},
        {*name_str && (!*new_texture || !*sf_texture),
            name_str, (void_func_t)free_any}
    }, game);
}

nsf_texture_t *nsf_texture_create(const char path[], const char name[],
    nsf_game_t *game)
{
    nsf_texture_t *new_texture = nsf_malloc_any(sizeof(nsf_texture_t),
        game);
    sfTexture *sf_texture = sfTexture_createFromFile(path, NULL);
    str name_str = my_strdup(name);

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
    if ((*texture)->texture)
        sfTexture_destroy((*texture)->texture);
    if ((*texture)->name)
        nsf_free_any((*texture)->name, game);
    *texture = nsf_free_any(*texture, game);
    return EXIT_SUCCESS;
}
