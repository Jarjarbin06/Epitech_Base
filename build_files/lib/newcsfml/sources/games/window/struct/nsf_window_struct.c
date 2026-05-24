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

#include <SFML/Graphics/RenderWindow.h>

#include "newcsfml/graphics/background.h"
#include "newcsfml/graphics/button.h"
#include "newcsfml/audios/sound.h"
#include "newcsfml/graphics/sprite.h"
#include "newcsfml/games/game.h"
#include "newcsfml/games/window_settings.h"
#include "newcsfml/systems/other.h"
#include "newcsfml/systems/utils.h"
#include "newcsfml/systems/vector.h"
#include "newcsfml/games/window.h"
#include "newcsfml/graphics/text.h"
#include "newcsfml/graphics/view.h"

static sfRenderWindow *get_new_window(const nsf_window_settings_t settings[],
    const cstr_t *title_str, const nsf_window_style_t window_style)
{
    return sfRenderWindow_create(
        (sfVideoMode){settings->width, settings->height, settings->bpp},
        *title_str, (sfWindowStyle)window_style, NULL);
}

static nsf_elements_t **create_elements(nsf_game_t *game)
{
    nsf_elements_t **elements = malloc_any(
        sizeof(nsf_elements_t *));

    if (NSF_UNLIKELY(!elements))
        return nsf_utils_log_null(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
            "alloc failed");
    elements[0] = NULL;
    if (game)
        game->allocations++;
    return elements;
}

static void init_views(nsf_window_t *new_window, nsf_game_t *game)
{
    nsf_uvector_t tmp1 = {0, 0};
    nsf_fvector_t tmp2 = {0, 0};
    nsf_fvector_t tmp3 = {0, 0};

    if (NSF_UNLIKELY(!new_window))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
            "pointer corrupted");
    tmp1 = (nsf_uvector_t){new_window->settings->width,
        new_window->settings->height};
    nsf_fvector_from_u(&tmp1, &tmp2);
    nsf_vector_div(&tmp2, 2.0f, &tmp3);
    new_window->element_view = nsf_view_create(game);
    nsf_view_set_center(new_window->element_view, &tmp3);
    nsf_view_set_size(new_window->element_view, &tmp1);
    new_window->ui_view = nsf_view_create(game);
    nsf_view_set_center(new_window->ui_view, &tmp3);
    nsf_view_set_size(new_window->ui_view, &tmp1);
    if (NSF_UNLIKELY(!new_window->element_view || !new_window->ui_view))
        nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
            "pointer corrupted");
}

static void init_values(nsf_window_t *new_window, nsf_game_t *game)
{
    new_window->elements.amount = 0;
    new_window->elements.size = 1;
    new_window->background = NULL;
    new_window->screen_len = 0;
    new_window->current_screen = -1;
    for (size_t idx = 0; idx < MAX_SCREENS; idx++)
        new_window->screens[idx] = NULL;
    init_views(new_window, game);
}

nsf_window_t *nsf_window_create(const nsf_window_settings_t settings[],
    const char title[], const nsf_window_style_t window_style,
    nsf_game_t *game)
{
    nsf_window_t *new_window = malloc_any(sizeof(nsf_window_t));
    const nsf_cstr_t title_str = str_dup(title);
    nsf_window_settings_t *new_settings = nsf_window_settings_create(settings,
        game);
    sfRenderWindow *sf_window = get_new_window(settings, &title_str,
        window_style);
    nsf_elements_t **elements = create_elements(game);

    if (NSF_UNLIKELY(!new_window || !new_settings || !sf_window || !title_str ||
            !elements))
        return NULL;
    new_window->window = sf_window;
    new_window->title = title_str;
    new_window->elements.elements = elements;
    new_window->settings = new_settings;
    init_values(new_window, game);
    if (game)
        game->allocations += 2;
    return new_window;
}

static void destroy_element(nsf_elements_t *element, nsf_game_t *game)
{
    if (NSF_UNLIKELY(!element))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
            "pointer corrupted");
    if (element->element_type == NSF_SPRITE_ELEMENT)
        nsf_sprite_destroy((nsf_sprite_t **)&(element->ptr), game);
    if (element->element_type == NSF_BUTTON_ELEMENT)
        nsf_button_destroy((nsf_button_t **)&(element->ptr), game);
    if (element->element_type == NSF_SOUND_ELEMENT)
        nsf_sound_destroy((nsf_sound_t **)&(element->ptr), game);
    if (element->element_type == NSF_TEXT_ELEMENT)
        nsf_text_destroy((nsf_text_t **)&(element->ptr), game);
    if (element->name)
        free_any((void *)element->name);
    free_any(element);
    if (game)
        game->allocations--;
}

static void destroy_elements(const nsf_element_list_t *elements,
    nsf_game_t *game)
{
    if (NSF_UNLIKELY(!elements))
        return nsf_utils_log(NSF_LOG_LVL_ERROR, NSF_WINDOW, __FUNCTION__,
            "pointer corrupted");
    for (size_t idx = 0; idx < elements->amount; idx++)
        destroy_element(elements->elements[idx], game);
    free_any(elements->elements);
    game->allocations--;
}

int nsf_window_destroy(nsf_window_t **window, nsf_game_t *game)
{
    if (NSF_UNLIKELY(!window || !*window))
        return nsf_utils_log_error(NSF_LOG_LVL_ERROR, NSF_WINDOW,
            __FUNCTION__, "pointer corrupted");
    if (NSF_LIKELY((*window)->background))
        nsf_background_destroy(&(*window)->background, game);
    if (NSF_LIKELY((*window)->settings))
        nsf_window_settings_destroy(&(*window)->settings, game);
    if (NSF_LIKELY((*window)->elements.elements))
        destroy_elements(&(*window)->elements, game);
    if (NSF_LIKELY((*window)->window))
        sfRenderWindow_destroy((*window)->window);
    if (NSF_LIKELY((*window)->title))
        free_any((str_t)(*window)->title);
    for (size_t idx = 0; idx < (*window)->screen_len; idx++)
        free_any((str_t)(*window)->screens[idx]);
    *window = free_any(*window);
    if (game)
        game->allocations -= 3;
    return E_SUCCESS;
}
