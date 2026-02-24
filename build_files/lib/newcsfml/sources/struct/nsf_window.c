/*
** EPITECH PROJECT, 2025
** struct - nsf_window.c
** File description:
** <description>
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Cursor.h>

#include "../../includes/newcsfml.h"

nsf_window *nsf_window_create(const nsf_window_settings settings,
    char title[], const nsf_window_style window_style, nsf_game *game)
{
    nsf_window *nsf_new_window = nsf_malloc_any(sizeof(nsf_window), game);
    sfRenderWindow *sf_window = NULL;
    char *title_str = my_strdup(title);

    sf_window = sfRenderWindow_create(
        (sfVideoMode){settings.width, settings.height, settings.bpp},
        title_str, (sfWindowStyle)window_style, NULL);
    if (nsf_auto_free(2, (free_t[]){
        {!nsf_new_window, &(nsf_new_window), (void_func_t)nsf_free_any},
        {!sf_window, &(sf_window), (void_func_t)sfRenderWindow_destroy}
    }, game))
        return NULL;
    nsf_new_window->window = sf_window;
    nsf_new_window->fps = settings.fps;
    nsf_new_window->title = title_str;
    return nsf_new_window;
}

int nsf_window_destroy(nsf_window **nsf_window, nsf_game *game)
{
    if (!nsf_window || !*nsf_window)
        return EXIT_ERROR;
    nsf_auto_free(3, (free_t[]){
        {(*nsf_window)->window, &((*nsf_window)->window),
            (void_func_t)sfRenderWindow_destroy},
        {(*nsf_window)->title, &((*nsf_window)->title),
            (void_func_t)free_any},
        {*nsf_window, nsf_window, (void_func_t)free_any}
    }, game);
    return EXIT_SUCCESS;
}
