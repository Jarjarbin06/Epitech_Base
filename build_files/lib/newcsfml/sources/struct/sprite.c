/*
** EPITECH PROJECT, 2025
** struct - sprite.c
** File description:
** <description>
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>

#include "../../includes/newcsfml.h"

nsf_sprite *nsf_sprite_create(const char name[])
{
    nsf_sprite *nsf_new_sprite = (nsf_sprite *)malloc_any(sizeof(nsf_sprite));
    sfSprite *sf_sprite = sfSprite_create();
    char *sprite_name = my_strdup(name);

    if (auto_free(2, (free_t[]){
        {!nsf_new_sprite, &(nsf_new_sprite), (void_func_t)free_any},
        {!sf_sprite, &(sf_sprite), (void_func_t)sfSprite_destroy}
    }))
        return NULL;
    nsf_new_sprite->sprite = sf_sprite;
    nsf_new_sprite->name = sprite_name;
    return nsf_new_sprite;
}

int nsf_sprite_destroy(nsf_sprite **nsf_sprite)
{
    if (!nsf_sprite || !*nsf_sprite)
        return EXIT_FAILURE;
    auto_free(4, (free_t[]){
        {(*nsf_sprite)->name, &((*nsf_sprite)->name),
            (void_func_t)sfSprite_destroy},
        {(*nsf_sprite)->sprite, &((*nsf_sprite)->sprite),
            (void_func_t)sfSprite_destroy},
        {(*nsf_sprite)->texture, &((*nsf_sprite)->texture),
            (void_func_t)sfTexture_destroy},
        {*nsf_sprite, nsf_sprite, (void_func_t)free_any}
    });
    *nsf_sprite = NULL;
    return EXIT_SUCCESS;
}
