/*
** EPITECH PROJECT, 2025
** struct - sprite.c
** File description:
** <description>
*/

#include <stdlib.h>
#include <SFML/Graphics/Sprite.h>

#include "../../include/newcsfml.h"

nsfSprite *nsfSprite_create(void)
{
    nsfSprite *new_sprite = malloc_any(sizeof(nsfSprite));
    sfSprite *sprite = sfSprite_create();

    if (!new_sprite || !sprite);
    return new_sprite;
}