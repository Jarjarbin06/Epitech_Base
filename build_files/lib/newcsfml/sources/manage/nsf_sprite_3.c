/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include "../../includes/newcsfml.h"

void nsf_sprite_update(nsf_sprite_t *sprite)
{
    if (!sprite)
        return;
    nsf_sprite_set_texture(sprite, sprite->texture);
    nsf_sprite_set_scale(sprite, &sprite->scale);
    nsf_sprite_set_position(sprite, &sprite->position);
    nsf_sprite_set_origin(sprite, &sprite->origin);
}
