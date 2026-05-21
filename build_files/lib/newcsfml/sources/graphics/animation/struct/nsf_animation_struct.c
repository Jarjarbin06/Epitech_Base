/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.7
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

#include "newcsfml/games/game.h"
#include "newcsfml/graphics/animation.h"
#include "newcsfml/systems/other.h"
#include "newcsfml/systems/utils.h"
#include "newcsfml/systems/vector.h"

static void init_values(nsf_animation_t *new_animation) {

    if (NSF_UNLIKELY(!new_animation))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_ANIMATION,
            __FUNCTION__, "pointer corrupted");
    new_animation->rect = (sfIntRect){0, 0, 0, 0};
    new_animation->offset = (nsf_uvector_t){0, 0};
    new_animation->step = 0;
    new_animation->current_line = -1;
}

nsf_animation_t *nsf_animation_create(const char path[], const char name[],
    nsf_uvector_t size[], nsf_game_t *game)
{
    nsf_animation_t *new_animation = malloc_any(sizeof(nsf_animation_t));
    sfTexture *sf_texture = sfTexture_createFromFile(path, NULL);
    const nsf_cstr_t name_str = str_dup(name);

    if (NSF_UNLIKELY(!new_animation || !sf_texture || !name_str))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_ANIMATION,
            __FUNCTION__, "alloc failed");
    new_animation->texture = sf_texture;
    new_animation->name = name_str;
    new_animation->sheet_size = sfTexture_getSize(sf_texture);
    new_animation->sprite_size = (nsf_uvector_t){
        .x = new_animation->sheet_size.x / size->x,
        .y = new_animation->sheet_size.y / size->y};
    new_animation->columns = size->x;
    new_animation->rows = size->y;
    init_values(new_animation);
    if (game)
        game->allocations += 3;
    return new_animation;
}

int nsf_animation_destroy(nsf_animation_t **animation, nsf_game_t *game)
{
    if (NSF_UNLIKELY(!animation || !*animation))
        return nsf_utils_log_error(NSF_LOG_LVL_ERROR, NSF_ANIMATION,
            __FUNCTION__, "pointer corrupted");
    if (NSF_LIKELY((*animation)->texture))
        sfTexture_destroy((*animation)->texture);
    if (NSF_LIKELY((*animation)->name))
        free_any((nsf_str_t)(*animation)->name);
    *animation = free_any(*animation);
    if (game)
        game->allocations -= 3;
    return E_SUCCESS;
}
