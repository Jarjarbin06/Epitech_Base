/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Cursor.h>

#include "../../includes/newcsfml.h"

static sfRenderWindow *get_new_window(const nsf_window_settings_t settings,
    const str *title_str, const nsf_window_style_t window_style)
{
    return sfRenderWindow_create(
        (sfVideoMode){settings.width, settings.height, settings.bpp},
        *title_str, (sfWindowStyle)window_style, NULL);
}

static int check_ptr(nsf_window_t **nsf_new_window, sfRenderWindow **sf_window,
    str *title_str, nsf_game_t *game)
{
    return nsf_auto_free(3, (free_t[]){
        {*nsf_new_window && (!*sf_window || !*title_str),
            nsf_new_window, (void_func_t)free_any},
        {*sf_window && (!*nsf_new_window || !*title_str),
            sf_window, (void_func_t)sfRenderWindow_destroy},
        {*title_str && (!*nsf_new_window || !*sf_window),
            title_str, (void_func_t)free_any}
    }, game);
}

nsf_window_t *nsf_window_create(const nsf_window_settings_t settings,
    char title[], const nsf_window_style_t window_style, nsf_game_t *game)
{
    nsf_window_t *nsf_new_window = nsf_malloc_any(sizeof(nsf_window_t), game);
    str title_str = my_strdup(title);
    sfRenderWindow *sf_window = get_new_window(settings, &title_str,
        window_style);

    if (check_ptr(&nsf_new_window, &sf_window, &title_str, game))
        return NULL;
    nsf_new_window->window = sf_window;
    nsf_new_window->fps = settings.fps;
    nsf_new_window->title = title_str;
    nsf_new_window->sprites = NULL;
    nsf_new_window->background = NULL;
    nsf_new_window->settings = NULL;
    return nsf_new_window;
}

int nsf_window_destroy(nsf_window_t **nsf_window, nsf_game_t *game)
{
    if (!nsf_window || !*nsf_window)
        return EXIT_ERROR;
    if ((*nsf_window)->window)
        sfRenderWindow_destroy((*nsf_window)->window);
    if ((*nsf_window)->title)
        nsf_free_any((*nsf_window)->title, NULL);
    *nsf_window = nsf_free_any(*nsf_window, game);
    return EXIT_SUCCESS;
}
