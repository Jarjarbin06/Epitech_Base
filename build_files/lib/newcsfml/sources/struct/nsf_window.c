/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include <SFML/Graphics/RenderWindow.h>

#include "../../includes/newcsfml.h"

static sfRenderWindow *get_new_window(const nsf_window_settings_t settings,
    const str *title_str, const nsf_window_style_t window_style)
{
    return sfRenderWindow_create(
        (sfVideoMode){settings.width, settings.height, settings.bpp},
        *title_str, (sfWindowStyle)window_style, NULL);
}

static int check_ptr(nsf_window_t **new_window, sfRenderWindow **sf_window,
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

nsf_window_t *nsf_window_create(const nsf_window_settings_t settings,
    char title[], const nsf_window_style_t window_style, nsf_game_t *game)
{
    nsf_window_t *new_window = nsf_malloc_any(sizeof(nsf_window_t),
        game);
    str title_str = my_strdup(title);
    sfRenderWindow *sf_window = get_new_window(settings, &title_str,
        window_style);

    if (check_ptr(&new_window, &sf_window, &title_str, game))
        return NULL;
    new_window->window = sf_window;
    new_window->fps = settings.fps;
    new_window->title = title_str;
    new_window->sprites = NULL;
    new_window->background = NULL;
    new_window->settings = NULL;
    return new_window;
}

int nsf_window_destroy(nsf_window_t **window, nsf_game_t *game)
{
    if (!window || !*window)
        return EXIT_ERROR;
    if ((*window)->window)
        sfRenderWindow_destroy((*window)->window);
    if ((*window)->title)
        nsf_free_any((*window)->title, NULL);
    *window = nsf_free_any(*window, game);
    return EXIT_SUCCESS;
}
