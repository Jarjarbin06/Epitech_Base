/*
** EPITECH PROJECT, 2025
** struct - nsf_sprite.c
** File description:
** <description>
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>

#include "../../includes/newcsfml.h"

static int check_ptr(nsf_texture_t **nsf_new_texture, sfTexture **sf_texture,
    str *name_str, nsf_game_t *game)
{
    return nsf_auto_free(3, (free_t[]){
        {*nsf_new_texture && (!*sf_texture || !*name_str),
            nsf_new_texture, (void_func_t)free_any},
        {*sf_texture && (!*nsf_new_texture || !*name_str),
            sf_texture, (void_func_t)sfTexture_destroy},
        {*name_str && (!*nsf_new_texture || !*sf_texture),
            name_str, (void_func_t)free_any}
    }, game);
}

nsf_texture_t *nsf_texture_create(const char path[], const char name[], nsf_game_t
    *game)
{
    nsf_texture_t *nsf_new_texture = nsf_malloc_any(sizeof(nsf_texture_t), game);
    sfTexture *sf_texture = sfTexture_createFromFile(path, NULL);
    str name_str = my_strdup(name);

    if (check_ptr(&nsf_new_texture, &sf_texture, &name_str, game))
        return NULL;
    nsf_new_texture->texture = sf_texture;
    nsf_new_texture->name = name_str;
    return nsf_new_texture;
}

int nsf_texture_destroy(nsf_texture_t **nsf_texture, nsf_game_t *game)
{
    if (!nsf_texture || !*nsf_texture)
        return EXIT_ERROR;
    if ((*nsf_texture)->texture)
        sfTexture_destroy((*nsf_texture)->texture);
    if ((*nsf_texture)->name)
        nsf_free_any((*nsf_texture)->name, game);
    *nsf_texture = nsf_free_any(*nsf_texture, game);
    return EXIT_SUCCESS;
}
