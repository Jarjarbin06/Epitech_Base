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

void nsf_sprite_get_scale(nsf_sprite_t *sprite, nsf_fvector_t *out)
{
    if (!sprite)
        return nsf_fvector_empty(out);
    nsf_fvector_copy(&sprite->scale, out);
}

void nsf_sprite_get_size(nsf_sprite_t *sprite, nsf_uvector_t *out)
{
    if (!sprite || !sprite->texture)
        return nsf_uvector_empty(out);
    nsf_uvector_copy((nsf_uvector_t[]){sfTexture_getSize
            (sprite->texture->texture)}, out);
}

void nsf_sprite_get_position(nsf_sprite_t *sprite, nsf_fvector_t *out)
{
    if (!sprite)
        return nsf_fvector_empty(out);
    nsf_fvector_copy(&sprite->position, out);
}

void nsf_sprite_get_origin(nsf_sprite_t *sprite, nsf_fvector_t *out)
{
    if (!sprite)
        return nsf_fvector_empty(out);
    nsf_fvector_copy(&sprite->origin, out);
}
