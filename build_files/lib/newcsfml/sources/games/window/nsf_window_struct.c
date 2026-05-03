/*
** EPITECH PROJECT, 2025
** NCSFML - New C Simple Fast Multimedia Library
** File description:
** •
** NSFML is a lightweight wrapper over CSFML that simplifies usage
** while reducing low-level flexibility for easier game development.
** •
** Version: ncsfml-v0.2.1
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

#include <SFML/Graphics/RenderWindow.h>

#include "newcsfml/graphics/background.h"
#include "newcsfml/graphics/button.h"
#include "newcsfml/audios/sound.h"
#include "newcsfml/graphics/sprite.h"
#include "newcsfml/games/game.h"
#include "newcsfml/games/window_settings.h"
#include "newcsfml/systems/other.h"
#include "newcsfml/systems/utils.h"
#include "newcsfml/games/window.h"

static sfRenderWindow *get_new_window(const nsf_window_settings_t settings[],
    const cstr_t *title_str, const nsf_window_style_t window_style)
{
    return sfRenderWindow_create(
        (sfVideoMode){settings->width, settings->height, settings->bpp},
        *title_str, (sfWindowStyle)window_style, NULL);
}

static nsf_window_elements_t **create_elements(nsf_game_t *game)
{
    nsf_window_elements_t **elements = malloc_any(
        sizeof(nsf_window_elements_t *));

    if (NSF_UNLIKELY(!elements))
        return NULL;
    elements[0] = NULL;
    if (game)
        game->allocations++;
    return elements;
}

nsf_window_t *nsf_window_create(const nsf_window_settings_t settings[],
    const char title[], const nsf_window_style_t window_style,
    nsf_game_t *game)
{
    nsf_window_t *new_window = malloc_any(sizeof(nsf_window_t));
    const nsf_cstr_t title_str = str_dup((const char *const)title);
    nsf_window_settings_t *new_settings = nsf_window_settings_create(settings,
        game);
    sfRenderWindow *sf_window = get_new_window(settings, &title_str,
        window_style);
    nsf_window_elements_t **elements = create_elements(game);

    if (NSF_UNLIKELY(!new_window || !new_settings || !sf_window || !title_str ||
        !elements))
        return NULL;
    new_window->window = sf_window;
    new_window->title = title_str;
    new_window->elements = elements;
    new_window->background = NULL;
    new_window->settings = new_settings;
    if (game)
        game->allocations += 3;
    return new_window;
}

static void destroy_element(nsf_window_elements_t *element, nsf_game_t *game)
{
    if (NSF_UNLIKELY(!element))
        return;
    switch (element->element_type) {
        case NSF_SPRITE_ELEMENT:
            nsf_sprite_destroy(
                (nsf_sprite_t **)&(element->ptr), game);
            break;
        case NSF_BUTTON_ELEMENT:
            nsf_button_destroy(
                (nsf_button_t **)&(element->ptr), game);
            break;
        case NSF_SOUND_ELEMENT:
            nsf_sound_destroy(
                (nsf_sound_t **)&(element->ptr), game);
            break;
        default:
            break;
    }
}

static void destroy_elements(nsf_window_elements_t **elements, nsf_game_t *game)
{
    for (int idx = 0; elements[idx]; idx++) {
        destroy_element(elements[idx], game);
        free_any(elements[idx]);
        game->allocations--;
    }
    free_any(elements);
    game->allocations--;
}

int nsf_window_destroy(nsf_window_t **window, nsf_game_t *game)
{
    if (NSF_UNLIKELY(!window || !*window))
        return EXIT_ERROR;
    if (NSF_LIKELY((*window)->background))
        nsf_background_destroy(&(*window)->background, game);
    if (NSF_LIKELY((*window)->settings))
        nsf_window_settings_destroy(&(*window)->settings, game);
    if (NSF_LIKELY((*window)->elements))
        destroy_elements((*window)->elements, game);
    if (NSF_LIKELY((*window)->window))
        sfRenderWindow_destroy((*window)->window);
    if (NSF_LIKELY((*window)->title))
        free_any((str_t)(*window)->title);
    *window = free_any(*window);
    if (game)
        game->allocations -= 3;
    return EXIT_SUCCESS;
}
