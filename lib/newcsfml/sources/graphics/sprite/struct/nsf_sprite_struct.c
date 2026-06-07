/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.8
** Author: Jarjarbin06
** Licence: GPL v3
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

#include <SFML/Graphics/Sprite.h>

#include "newcsfml/games/game.h"
#include "newcsfml/graphics/animation.h"
#include "newcsfml/graphics/sprite.h"
#include "newcsfml/graphics/animation.h"
#include "newcsfml/graphics/texture.h"
#include "newcsfml/systems/other.h"
#include "newcsfml/systems/utils.h"

nsf_sprite_t *nsf_sprite_create(const char name[], nsf_game_t *game)
{
    nsf_sprite_t *new_sprite = malloc_any(sizeof(nsf_sprite_t));
    sfSprite *sf_sprite = sfSprite_create();
    const nsf_cstr_t sprite_name = str_dup(name);

    if (NSF_UNLIKELY(!new_sprite || !sf_sprite || !sprite_name))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_SPRITE,
            __FUNCTION__, "alloc failed");
    new_sprite->sprite = sf_sprite;
    new_sprite->sprite = sf_sprite;
    new_sprite->name = sprite_name;
    new_sprite->origin = (nsf_fvector_t){0.0f, 0.0f};
    new_sprite->texture_type = NSF_TXR_NONE;
    new_sprite->texture.animation = NULL;
    new_sprite->texture.texture = NULL;
    new_sprite->data = NULL;
    if (game)
        game->allocations += 3;
    return new_sprite;
}

int nsf_sprite_destroy(nsf_sprite_t **sprite, nsf_game_t *game)
{
    if (NSF_UNLIKELY(!sprite || !*sprite))
        return nsf_utils_log_failure(NSF_LOG_LVL_ERROR, NSF_SPRITE,
            __FUNCTION__, "pointer corrupted");
    if ((*sprite)->texture_type == NSF_TXR_TEXTURE)
        nsf_texture_destroy(&(*sprite)->texture.texture, game);
    if ((*sprite)->texture_type == NSF_TXR_ANIMATION)
        nsf_animation_destroy(&(*sprite)->texture.animation, game);
    if (NSF_LIKELY((*sprite)->sprite))
        sfSprite_destroy((*sprite)->sprite);
    if (NSF_LIKELY((*sprite)->name))
        free_any((nsf_str_t)(*sprite)->name);
    *sprite = free_any(*sprite);
    if (game)
        game->allocations -= 3;
    return E_SUCCESS;
}
