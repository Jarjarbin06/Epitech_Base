/*
** EPITECH PROJECT, 2025
** struct - sprite.c
** File description:
** <description>
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>

#include "../../includes/newcsfml.h"

nsf_sprite *nsf_sprite_create(void)
{
    nsf_sprite *nsf_sprite = malloc_any(sizeof(nsf_sprite));
    sfSprite *sf_sprite = sfSprite_create();

    if (auto_free(2, (free_t[]){
        {!nsf_sprite, &(nsf_sprite), free_any},
        {!sf_sprite, &(sf_sprite), (void_func)sfSprite_destroy}
    }))
        return NULL;
    return nsf_sprite;
}

void *nsf_sprite_destroy(nsf_sprite *nsf_sprite)
{
    auto_free(3, (free_t[]){
        {(nsf_sprite && nsf_sprite->sprite), &(nsf_sprite->sprite),
            (void_func)sfSprite_destroy},
        {(nsf_sprite && nsf_sprite->texture), &(nsf_sprite->texture),
            (void_func)sfTexture_destroy},
        {nsf_sprite, nsf_sprite, free_any}
    });
    return NULL;
}
