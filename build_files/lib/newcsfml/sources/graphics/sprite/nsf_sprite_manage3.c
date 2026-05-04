/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.2
** Author: Jarjarbin06
** License: GPL v3
** •
** This library is inspired by SFML/CSFML and is designed for
** educational and game-development purposes.
** •
** It provides higher-level abstractions over CSFML to reduce
** boilerplate code and enforce safer usage patterns.
** •
** WARNING:
** This is NOT the original SFML/CSFML library.
** It is a custom implementation layer built on top of CSFML.
*/

#include "newcsfml/graphics/sprite.h"
#include "newcsfml/systems/utils.h"

void nsf_sprite_update(nsf_sprite_t *sprite)
{
    if (NSF_UNLIKELY(!sprite))
        return;
    nsf_sprite_set_texture(sprite, sprite->texture);
    nsf_sprite_set_scale(sprite, &sprite->scale);
    nsf_sprite_set_position(sprite, &sprite->position);
    nsf_sprite_set_origin(sprite, &sprite->origin);
}
