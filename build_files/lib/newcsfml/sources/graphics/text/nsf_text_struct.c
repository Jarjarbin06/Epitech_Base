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

#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Font.h>

#include "newcsfml/games/game.h"
#include "newcsfml/graphics/text.h"
#include "newcsfml/systems/other.h"
#include "newcsfml/systems/utils.h"

nsf_text_t *nsf_text_create(const char name[], const char font_path[],
    nsf_game_t *game)
{
    nsf_text_t *new_text = malloc_any(sizeof(nsf_text_t));
    sfText *sf_text = sfText_create();
    const nsf_cstr_t name_str = str_dup(name);

    if (NSF_UNLIKELY(!new_text || !sf_text || !name_str))
        return NULL;
    new_text->text = sf_text;
    new_text->font = sfFont_createFromFile(font_path);
    sfText_setFont(new_text->text, new_text->font);
    new_text->size = 0.0f;
    new_text->rotation = 0.0f;
    new_text->string = str_dup("a text");
    new_text->name = name_str;
    if (game)
        game->allocations += 5;
    return new_text;
}

int nsf_text_destroy(nsf_text_t **texture, nsf_game_t *game)
{
    if (NSF_UNLIKELY(!texture || !*texture))
        return EXIT_ERROR;
    if (NSF_LIKELY((*texture)->text))
        sfText_destroy((*texture)->text);
    if (NSF_LIKELY((*texture)->font))
        sfFont_destroy((sfFont *)(*texture)->font);
    if (NSF_LIKELY((*texture)->string))
        free_any((nsf_str_t)(*texture)->string);
    if (NSF_LIKELY((*texture)->name))
        free_any((nsf_str_t)(*texture)->name);
    *texture = free_any(*texture);
    if (game)
        game->allocations -= 5;
    return EXIT_SUCCESS;
}
