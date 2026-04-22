/*
** EPITECH PROJECT, 2025
** struct - nsf_sprite.c
** File description:
** <description>
*/

#include "../../includes/newcsfml.h"

nsf_background_t *nsf_background_create(const char path[],
                                        nsf_window_t *window, nsf_game_t *game)
{
    nsf_background_t *new_background = malloc_any(sizeof(nsf_background_t));
    nsf_sprite_t *new_sprite = nsf_sprite_create("background", game);
    nsf_texture_t *new_texture = nsf_texture_create(path, "background", game);
    nsf_uvector_t window_size = {0, 0};

    if (!new_background || !new_sprite || !new_texture)
        return NULL;
    window_size.x = window->settings->width;
    window_size.y = window->settings->height;
    nsf_sprite_set_texture(new_sprite, new_texture);
    nsf_sprite_set_size(new_sprite, &window_size);
    nsf_sprite_set_position(new_sprite, (nsf_fvector_t[]){{0.0f, 0.0f}});
    new_background->sprite = new_sprite;
    new_background->texture = new_texture;
    if (game)
        game->allocations++;
    return new_background;
}

int nsf_background_destroy(nsf_background_t **background, nsf_game_t *game)
{
    if (!background || !*background)
        return EXIT_ERROR;
    if ((*background)->texture)
        nsf_texture_destroy(&(*background)->texture, game);
    if ((*background)->sprite)
        nsf_sprite_destroy(&(*background)->sprite, game);
    *background = free_any(*background);
    game->allocations--;
    return EXIT_SUCCESS;
}
