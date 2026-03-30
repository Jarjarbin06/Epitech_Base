/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include <SFML/Graphics/RenderWindow.h>

#include "newcsfml.h"

static sfRenderWindow *get_new_window(const nsf_window_settings_t settings[],
    const str *title_str, const nsf_window_style_t window_style)
{
    return sfRenderWindow_create(
        (sfVideoMode){settings->width, settings->height, settings->bpp},
        *title_str, (sfWindowStyle)window_style, NULL);
}

static int check_ptr_1(nsf_window_t **new_window, sfRenderWindow **sf_window,
    str *title_str, nsf_game_t *game)
{
    return nsf_auto_free(3, (free_t[]){
        {*new_window && (!*sf_window || !*title_str),
            new_window, (void_func_t)free_any},
        {*sf_window && (!*new_window || !*title_str),
            sf_window, (void_func_t)sfRenderWindow_destroy},
        {*title_str && (!*new_window || !*sf_window),
            title_str, (void_func_t)free_any}
    }, game);
}

static nsf_window_element_t **create_elements(nsf_game_t *game)
{
    nsf_window_element_t **elements = nsf_malloc_any(
        sizeof(nsf_window_element_t *), game);

    if (!elements)
        return NULL;
    elements[0] = NULL;
    return elements;
}

nsf_window_t *nsf_window_create(const nsf_window_settings_t settings[],
    char title[], const nsf_window_style_t window_style, nsf_game_t *game)
{
    nsf_window_t *new_window = nsf_malloc_any(sizeof(nsf_window_t),
        game);
    str title_str = str_strdup(title);
    sfRenderWindow *sf_window = get_new_window(settings, &title_str,
        window_style);

    if (check_ptr_1(&new_window, &sf_window, &title_str, game))
        return NULL;
    new_window->window = sf_window;
    new_window->fps = settings->fps;
    new_window->title = title_str;
    new_window->elements = create_elements(game);
    new_window->background = NULL;
    new_window->settings = NULL;
    return new_window;
}

static void destroy_elements(const nsf_window_t *window, nsf_game_t *game)
{
    for (int idx = 0; window->elements[idx]; idx++) {
        switch (window->elements[idx]->element_type) {
            case SPRITE_ELEMENT:
                nsf_sprite_destroy(
                    (nsf_sprite_t **)&(window->elements[idx]->ptr), game);
                break;
            case BUTTON_ELEMENT:
                nsf_button_destroy(
                    (nsf_button_t **)&(window->elements[idx]->ptr), game);
                break;
            default:
                return;
        }
        nsf_free_any(window->elements[idx], game);
    }
    nsf_free_any(window->elements, game);
}

int nsf_window_destroy(nsf_window_t **window, nsf_game_t *game)
{
    if (!window || !*window)
        return EXIT_ERROR;
    if ((*window)->window)
        sfRenderWindow_destroy((*window)->window);
    if ((*window)->title)
        nsf_free_any((*window)->title, NULL);
    if ((*window)->elements)
        destroy_elements(*window, game);
    *window = nsf_free_any(*window, game);
    return EXIT_SUCCESS;
}
