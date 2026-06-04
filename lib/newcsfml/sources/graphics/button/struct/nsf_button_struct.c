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

#include <SFML/Graphics/RectangleShape.h>

#include "newcsfml/games/game.h"
#include "newcsfml/systems/other.h"
#include "newcsfml/systems/utils.h"
#include "newcsfml/systems/vector.h"
#include "newcsfml/graphics/button.h"
#include "newcsfml/graphics/texture.h"

nsf_button_t *nsf_button_create(const char name[], nsf_game_t *game)
{
    nsf_button_t *new_button = malloc_any(sizeof(nsf_button_t));
    sfRectangleShape *sf_button = sfRectangleShape_create();
    const nsf_cstr_t name_str = str_dup(name);

    if (NSF_UNLIKELY(!new_button || !sf_button || !name_str))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_BUTTON, __FUNCTION__,
            "alloc failed");
    new_button->button = sf_button;
    new_button->texture = NULL;
    nsf_button_set_size(new_button, (nsf_uvector_t[]){{0, 0}});
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
    if (NSF_UNLIKELY(!button || !*button))
        return nsf_utils_log_error(NSF_LOG_LVL_ERROR, NSF_BUTTON,
            __FUNCTION__, "pointer corrupted");
    if (NSF_LIKELY((*button)->texture))
        nsf_texture_destroy((nsf_texture_t **)&(*button)->texture, game);
    if (NSF_LIKELY((*button)->button))
        sfRectangleShape_destroy((*button)->button);
    if (NSF_LIKELY((*button)->name))
        free_any((nsf_str_t)(*button)->name);
    *button = free_any(*button);
    if (game)
        game->allocations -= 3;
    return E_SUCCESS;
}
