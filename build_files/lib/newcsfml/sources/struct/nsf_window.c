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

static int check_ptr_1(nsf_window_t **new_window, sfRenderWindow **sf_window,
    str_t *title_str, nsf_game_t *game)
{
    return nsf_auto_free(3, (nsf_free_t[]){
        {*new_window && (!*sf_window || !*title_str),
            new_window, free_any},
        {*sf_window && (!*new_window || !*title_str),
            sf_window, sfRenderWindow_destroy},
        {*title_str && (!*new_window || !*sf_window),
            title_str, free_any}
    }, game);
}

static int check_ptr_2(nsf_window_settings_t **settings, nsf_game_t *game)
{
    if (!settings || !*settings) {
        nsf_window_setting_destroy(settings, game);
        return 1;
    }
    return 0;
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
    str_t title_str = str_strdup(title);
    nsf_window_settings_t *new_settings = nsf_window_setting_create(settings,
        game);
    sfRenderWindow *sf_window = get_new_window(settings, &title_str,
        window_style);

    if (check_ptr_1(&new_window, &sf_window, &title_str, game) ||
        check_ptr_2(&new_settings, game))
        return NULL;
    new_window->window = sf_window;
    new_window->fps = settings->fps;
    new_window->title = title_str;
    new_window->elements = create_elements(game);
    new_window->background = NULL;
    new_window->settings = new_settings;
    return new_window;
}

static void destroy_element(nsf_window_element_t *element, nsf_game_t *game)
{
    switch (element->element_type) {
        case NSF_SPRITE_ELEMENT:
            nsf_sprite_destroy(
                (nsf_sprite_t **)&(element->ptr), game);
            return;
        case NSF_BUTTON_ELEMENT:
            nsf_button_destroy(
                (nsf_button_t **)&(element->ptr), game);
            return;
        case NSF_SOUND_ELEMENT:
            nsf_sound_destroy(
                (nsf_sound_t **)&(element->ptr), game);
            return;
        default:
            return;
    }
}

static void destroy_elements(const nsf_window_t *window, nsf_game_t *game)
{
    for (int idx = 0; window->elements[idx]; idx++) {
        destroy_element(window->elements[idx], game);
        nsf_free_any(window->elements[idx], game);
    }
    nsf_free_any(window->elements, game);
}

int nsf_window_destroy(nsf_window_t **window, nsf_game_t *game)
{
    if (!window || !*window)
        return EXIT_ERROR;
    if ((*window)->elements)
        destroy_elements(*window, game);
    if ((*window)->settings)
        nsf_window_setting_destroy(&(*window)->settings, game);
    nsf_auto_free(3, (nsf_free_t[]){
        {(*window)->window, &(*window)->window, sfRenderWindow_destroy},
        {(*window)->title, &(*window)->title, free_any},
        {*window, &window, free_any}
    }, game);
    *window = NULL;
    return EXIT_SUCCESS;
}
