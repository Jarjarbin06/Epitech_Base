/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>

#include "../../includes/newcsfml.h"

nsf_texture_t *nsf_sprite_get_texture(nsf_sprite_t *sprite)
{
    if (!sprite)
        return NULL;
    return sprite->texture;
}

nsf_fvector_t *nsf_sprite_get_scale(nsf_sprite_t *sprite)
{
    if (!sprite)
        return NULL;
    return (nsf_fvector_t[]){sprite->scale};
}

nsf_uvector_t *nsf_sprite_get_size(nsf_sprite_t *sprite)
{
    if (!sprite || !sprite->texture)
        return NULL;
    return (nsf_uvector_t[]){sfTexture_getSize(sprite->texture->texture)};
}

nsf_fvector_t *nsf_sprite_get_position(nsf_sprite_t *sprite)
{
    if (!sprite)
        return NULL;
    return (nsf_fvector_t[]){sprite->position};
}

nsf_fvector_t *nsf_sprite_get_origin(nsf_sprite_t *sprite)
{
    if (!sprite)
        return NULL;
    return (nsf_fvector_t[]){sprite->origin};
}
