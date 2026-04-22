/*
** EPITECH PROJECT, 2025
** struct - nsf_sprite.c
** File description:
** <description>
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>

#include "../../includes/newcsfml.h"

nsf_texture_t *nsf_texture_create(const char path[], const char name[],
                                  nsf_game_t *game)
{
    nsf_texture_t *new_texture = malloc_any(sizeof(nsf_texture_t));
    sfTexture *sf_texture = sfTexture_createFromFile(path, NULL);
    str_t name_str = str_strdup(name);

    if (!new_texture || !sf_texture || !name_str)
        return NULL;
    new_texture->texture = sf_texture;
    new_texture->name = name_str;
    if (game)
        game->allocations += 3;
    return new_texture;
}

int nsf_texture_destroy(nsf_texture_t **texture, nsf_game_t *game)
{
    if (!texture || !*texture)
        return EXIT_ERROR;
    if ((*texture)->texture)
        sfTexture_destroy((*texture)->texture);
    if ((*texture)->name)
        free_any((*texture)->name);
    *texture = free_any(*texture);
    game->allocations -= 3;
    return EXIT_SUCCESS;
}
