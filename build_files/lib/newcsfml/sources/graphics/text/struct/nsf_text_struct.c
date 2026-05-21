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

#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Font.h>

#include "newcsfml/systems/color.h"
#include "newcsfml/games/game.h"
#include "newcsfml/graphics/text.h"
#include "newcsfml/systems/other.h"
#include "newcsfml/systems/utils.h"
#include "newcsfml/systems/watcher.h"

static void init_values(nsf_text_t **new_text, sfText *sf_text,
    const char font_path[], const nsf_cstr_t name_str)
{
    if (NSF_UNLIKELY(!new_text || !sf_text || !font_path || !name_str))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_TEXT, __FUNCTION__,
            "pointer corrupted");
    (*new_text)->text = sf_text;
    (*new_text)->font = sfFont_createFromFile(font_path);
    (*new_text)->postition = (nsf_fvector_t){0.0f, 0.0f};
    (*new_text)->origin = (nsf_fvector_t){0.0f, 0.0f};
    (*new_text)->size = 0;
    (*new_text)->rotation = 0.0f;
    (*new_text)->watcher = NULL;
    (*new_text)->color = nsf_color.black;
    (*new_text)->buffer[0] = '\0';
    (*new_text)->name = name_str;
}

nsf_text_t *nsf_text_create(const char name[], const char font_path[],
    nsf_game_t *game)
{
    nsf_text_t *new_text = malloc_any(sizeof(nsf_text_t));
    sfText *sf_text = sfText_create();
    const nsf_cstr_t name_str = str_dup(name);

    if (NSF_UNLIKELY(!new_text || !sf_text || !name_str))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_TEXT, __FUNCTION__,
            "alloc failed");
    init_values(&new_text, sf_text, font_path, name_str);
    sfText_setFont(new_text->text, new_text->font);
    nsf_text_set_string(new_text, "a text");
    if (game)
        game->allocations += 5;
    return new_text;
}

int nsf_text_destroy(nsf_text_t **text, nsf_game_t *game)
{
    if (NSF_UNLIKELY(!text || !*text))
        return nsf_utils_log_error(NSF_LOG_LVL_ERROR, NSF_TEXT, __FUNCTION__,
            "pointer corrupted");
    if ((*text)->watcher)
        nsf_watcher_destroy(&(*text)->watcher, game);
    if (NSF_LIKELY((*text)->text))
        sfText_destroy((*text)->text);
    if (NSF_LIKELY((*text)->font))
        sfFont_destroy((sfFont *)(*text)->font);
    if (NSF_LIKELY((*text)->name))
        free_any((nsf_str_t)(*text)->name);
    *text = free_any(*text);
    if (game)
        game->allocations -= 5;
    return E_SUCCESS;
}
