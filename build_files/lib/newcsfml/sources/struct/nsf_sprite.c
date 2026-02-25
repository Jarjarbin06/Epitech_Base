/*
** EPITECH PROJECT, 2025
** struct - nsf_sprite.c
** File description:
** <description>
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>

#include "../../includes/newcsfml.h"

static int check_ptr(nsf_sprite **nsf_new_sprite, sfSprite **sf_sprite,
    str *sprite_name, nsf_game *game)
{
    return nsf_auto_free(3, (free_t[]){
        {*nsf_new_sprite && (!*sf_sprite || !*sprite_name),
            nsf_new_sprite, (void_func_t)free_any},
        {*sf_sprite && (!*nsf_new_sprite || !*sprite_name),
            sf_sprite, (void_func_t)sfSprite_destroy},
        {*sprite_name && (!*nsf_new_sprite || !*sf_sprite),
            sprite_name, (void_func_t)free_any}
    }, game);
}

nsf_sprite *nsf_sprite_create(const char name[], nsf_game *game)
{
    nsf_sprite *nsf_new_sprite = nsf_malloc_any(sizeof(nsf_sprite), game);
    sfSprite *sf_sprite = sfSprite_create();
    str sprite_name = my_strdup(name);

    if (check_ptr(&nsf_new_sprite, &sf_sprite, &sprite_name, game))
        return NULL;
    if (sprite_name && game)
        game->allocations++;
    nsf_new_sprite->sprite = sf_sprite;
    nsf_new_sprite->name = sprite_name;
    nsf_new_sprite->data = NULL;
    nsf_new_sprite->texture = NULL;
    return nsf_new_sprite;
}

int nsf_sprite_destroy(nsf_sprite **nsf_sprite, nsf_game *game)
{
    if (!nsf_sprite || !*nsf_sprite)
        return EXIT_ERROR;
    if ((*nsf_sprite)->sprite)
        sfSprite_destroy((*nsf_sprite)->sprite);
    if ((*nsf_sprite)->texture)
        nsf_texture_destroy(&(*nsf_sprite)->texture, game);
    if ((*nsf_sprite)->name)
        nsf_free_any((*nsf_sprite)->name, game);
    *nsf_sprite = nsf_free_any(*nsf_sprite, game);
    return EXIT_SUCCESS;
}
