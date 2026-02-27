/*
** EPITECH PROJECT, 2025
** struct - nsf_sprite.c
** File description:
** <description>
*/

#include <SFML/Graphics/Sprite.h>

#include "../../includes/newcsfml.h"

static int check_ptr(nsf_sprite_t **new_sprite, sfSprite **sf_sprite,
    str *sprite_name, nsf_game_t *game)
{
    return nsf_auto_free(3, (free_t[]){
        {*new_sprite && (!*sf_sprite || !*sprite_name),
            new_sprite, (void_func_t)free_any},
        {*sf_sprite && (!*new_sprite || !*sprite_name),
            sf_sprite, (void_func_t)sfSprite_destroy},
        {*sprite_name && (!*new_sprite || !*sf_sprite),
            sprite_name, (void_func_t)free_any}
    }, game);
}

nsf_sprite_t *nsf_sprite_create(const char name[], nsf_game_t *game)
{
    nsf_sprite_t *new_sprite = nsf_malloc_any(sizeof(nsf_sprite_t),
        game);
    sfSprite *sf_sprite = sfSprite_create();
    str sprite_name = my_strdup(name);

    if (check_ptr(&new_sprite, &sf_sprite, &sprite_name, game))
        return NULL;
    if (sprite_name && game)
        game->allocations++;
    new_sprite->sprite = sf_sprite;
    new_sprite->name = sprite_name;
    new_sprite->data = NULL;
    new_sprite->texture = NULL;
    return new_sprite;
}

void nsf_sprite_destroy(nsf_sprite_t **sprite, nsf_game_t *game)
{
    if (!sprite || !*sprite)
        return;
    if ((*sprite)->sprite)
        sfSprite_destroy((*sprite)->sprite);
    if ((*sprite)->texture)
        nsf_texture_destroy(&(*sprite)->texture, game);
    if ((*sprite)->name)
        nsf_free_any((*sprite)->name, game);
    *sprite = nsf_free_any(*sprite, game);
}
