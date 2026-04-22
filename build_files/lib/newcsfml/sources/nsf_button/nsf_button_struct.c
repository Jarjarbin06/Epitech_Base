/*
** EPITECH PROJECT, 2025
** struct - nsf_sprite.c
** File description:
** <description>
*/

#include <SFML/Graphics/RectangleShape.h>

#include "../../includes/newcsfml.h"

nsf_button_t *nsf_button_create(const char name[], nsf_game_t *game)
{
    nsf_button_t *new_button = malloc_any(sizeof(nsf_button_t));
    sfRectangleShape *sf_button = sfRectangleShape_create();
    str_t name_str = str_strdup(name);

    if (!new_button || !sf_button || !name_str)
        return NULL;
    new_button->button = sf_button;
    new_button->texture = NULL;
    nsf_button_set_size(new_button, (nsf_fvector_t[]){{0, 0}});
    nsf_button_set_position(new_button, (nsf_fvector_t[]){{0, 0}});
    nsf_button_set_colors(new_button,
        (nsf_color_t[]){{0, 0, 0, 100}},
        (nsf_color_t[]){{0, 0, 0, 100}}, 5);
    new_button->name = name_str;
    if (game)
        game->allocations += 3;
    return new_button;
}

int nsf_button_destroy(nsf_button_t **button, nsf_game_t *game)
{
    if (!button || !*button)
        return EXIT_ERROR;
    if ((*button)->texture)
        nsf_texture_destroy(&(*button)->texture, game);
    if ((*button)->button)
        sfRectangleShape_destroy((*button)->button);
    if ((*button)->name)
        free_any((*button)->name);
    *button = free_any(*button);
    game->allocations -= 3;
    return EXIT_SUCCESS;
}
