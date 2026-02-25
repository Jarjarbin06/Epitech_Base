/*
** EPITECH PROJECT, 2025
** struct - nsf_sprite.c
** File description:
** <description>
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>

#include "../../includes/newcsfml.h"

nsf_texture *nsf_texture_create(const char path[], nsf_game *game)
{
    nsf_texture *nsf_new_texture = nsf_malloc_any(sizeof(nsf_texture), game);
    sfTexture *sf_texture = sfTexture_createFromFile(path, NULL);

    if (nsf_auto_free(2, (free_t[]){
        {!nsf_new_texture || !sf_texture,
            &(nsf_new_texture), (void_func_t)free_any},
        {!nsf_new_texture || !sf_texture,
            &(sf_texture), (void_func_t)sfTexture_destroy}
    }, game))
        return NULL;
    if (game)
        game->allocations++;
    nsf_new_texture->texture = sf_texture;
    return nsf_new_texture;
}

int nsf_texture_destroy(nsf_texture **nsf_texture, nsf_game *game)
{
    if (!nsf_texture || !*nsf_texture)
        return EXIT_ERROR;
    nsf_auto_free(2, (free_t[]){
        {(*nsf_texture)->texture, &(*nsf_texture)->texture,
            (void_func_t)sfTexture_destroy},
        {*nsf_texture, nsf_texture, (void_func_t)free_any}
    }, game);
    *nsf_texture = NULL;
    return EXIT_SUCCESS;
}
