/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include <SFML/Graphics/RenderWindow.h>

#include "../../includes/newcsfml.h"

static sfRenderWindow *get_new_window(const nsf_window_settings_t settings[],
    const str_t *title_str, const nsf_window_style_t window_style)
{
    return sfRenderWindow_create(
        (sfVideoMode){settings->width, settings->height, settings->bpp},
        *title_str, (sfWindowStyle)window_style, NULL);
}

static nsf_window_element_t **create_elements(nsf_game_t *game)
{
    nsf_window_element_t **elements = malloc_any(
        sizeof(nsf_window_element_t *));

    if (!elements)
        return NULL;
    elements[0] = NULL;
    if (game)
        game->allocations++;
    return elements;
}

nsf_window_t *nsf_window_create(const nsf_window_settings_t settings[],
    char title[], const nsf_window_style_t window_style, nsf_game_t *game)
{
    nsf_window_t *new_window = malloc_any(sizeof(nsf_window_t));
    str_t title_str = str_strdup(title);
    nsf_window_settings_t *new_settings = nsf_window_settings_create(settings,
        game);
    sfRenderWindow *sf_window = get_new_window(settings, &title_str,
        window_style);
    nsf_window_element_t **elements = create_elements(game);

    if (!new_window || !new_settings || !sf_window || !title_str || !elements)
        return NULL;
    new_window->window = sf_window;
    new_window->fps = settings->fps;
    new_window->title = title_str;
    new_window->elements = elements;
    new_window->background = NULL;
    new_window->settings = new_settings;
    if (game)
        game->allocations += 3;
    return new_window;
}

static void destroy_element(nsf_window_element_t *element, nsf_game_t *game)
{
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

static void destroy_elements(nsf_window_element_t **elements, nsf_game_t *game)
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
    if (!window || !*window)
        return EXIT_ERROR;
    if ((*window)->settings)
        nsf_window_settings_destroy(&(*window)->settings, game);
    if ((*window)->elements)
        destroy_elements((*window)->elements, game);
    if ((*window)->window)
        sfRenderWindow_destroy((*window)->window);
    if ((*window)->title)
        free_any((*window)->title);
    *window = free_any(*window);
    if (game)
        game->allocations -= 3;
    return EXIT_SUCCESS;
}
