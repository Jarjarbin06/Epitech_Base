/*
** EPITECH PROJECT, 2025
** struct - nsf_sprite.c
** File description:
** <description>
*/

#include <SFML/Graphics/Sprite.h>

#include "../../includes/newcsfml.h"

nsf_sprite_t *nsf_sprite_create(const char name[], nsf_game_t *game)
{
    nsf_sprite_t *new_sprite = malloc_any(sizeof(nsf_sprite_t));
    sfSprite *sf_sprite = sfSprite_create();
    str_t sprite_name = str_strdup(name);

    if (!new_sprite || !sf_sprite || !sprite_name)
        return NULL;
    new_sprite->sprite = sf_sprite;
    new_sprite->name = sprite_name;
    new_sprite->data = NULL;
    new_sprite->texture = NULL;
    if (game)
        game->allocations += 3;
    return new_sprite;
}

int nsf_sprite_destroy(nsf_sprite_t **sprite, nsf_game_t *game)
{
    if (!sprite || !*sprite)
        return EXIT_ERROR;
    if ((*sprite)->texture)
        nsf_texture_destroy(&(*sprite)->texture, game);
    if ((*sprite)->sprite)
        sfSprite_destroy((*sprite)->sprite);
    if ((*sprite)->name)
        free_any((*sprite)->name);
    *sprite = free_any(*sprite);
    game->allocations -= 3;
    return EXIT_SUCCESS;
}
