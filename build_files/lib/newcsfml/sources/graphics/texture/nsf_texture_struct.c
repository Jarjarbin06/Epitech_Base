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

#include <SFML/Graphics/Texture.h>

#include "newcsfml/games/game.h"
#include "newcsfml/graphics/texture.h"
#include "newcsfml/systems/other.h"
#include "newcsfml/systems/utils.h"

nsf_texture_t *nsf_texture_create(const char path[], const char name[],
    nsf_game_t *game)
{
    nsf_texture_t *new_texture = malloc_any(sizeof(nsf_texture_t));
    sfTexture *sf_texture = sfTexture_createFromFile(path, NULL);
    const nsf_cstr_t name_str = str_dup(name);

    if (NSF_UNLIKELY(!new_texture || !sf_texture || !name_str))
        return NULL;
    new_texture->texture = sf_texture;
    new_texture->name = name_str;
    if (game)
        game->allocations += 3;
    return new_texture;
}

int nsf_texture_destroy(nsf_texture_t **texture, nsf_game_t *game)
{
    if (NSF_UNLIKELY(!texture || !*texture))
        return EXIT_ERROR;
    if (NSF_LIKELY((*texture)->texture))
        sfTexture_destroy((*texture)->texture);
    if (NSF_LIKELY((*texture)->name))
        free_any((nsf_str_t)(*texture)->name);
    *texture = free_any(*texture);
    if (game)
        game->allocations -= 3;
    return EXIT_SUCCESS;
}
