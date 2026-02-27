/*
** EPITECH PROJECT, 2025
** struct - nsf_sprite.c
** File description:
** <description>
*/

#include <SFML/Graphics/RectangleShape.h>

#include "../../includes/newcsfml.h"

static int check_ptr(nsf_button_t **new_button, sfRectangleShape **sf_button,
    str *name_str, nsf_game_t *game)
{
    return nsf_auto_free(3, (free_t[]){
        {*new_button && (!*name_str || !*sf_button),
            new_button, (void_func_t)free_any},
        {*sf_button && (!*new_button || !*name_str),
            sf_button, (void_func_t)sfRectangleShape_destroy},
        {*name_str && (!*new_button || !*sf_button),
            name_str, (void_func_t)free_any}
    }, game);
}

nsf_button_t *nsf_button_create(const char name[], nsf_game_t *game)
{
    nsf_button_t *new_button = nsf_malloc_any(sizeof(nsf_button_t), game);
    sfRectangleShape *sf_button = sfRectangleShape_create();
    str name_str = my_strdup(name);

    if (check_ptr(&new_button, &sf_button, &name_str, game))
        return NULL;
    new_button->button = sf_button;
    new_button->size = (nsf_vector){0, 0};
    new_button->position = (nsf_vector){0, 0};
    new_button->fill_color = (nsf_color_t){0, 0, 0, 0};
    new_button->outline_color = (nsf_color_t){0, 0, 0, 0};
    new_button->name = name_str;
    return new_button;
}

int nsf_button_destroy(nsf_button_t **button, nsf_game_t *game)
{
    if (!button || !*button)
        return EXIT_ERROR;
    if ((*button)->button)
        sfRectangleShape_destroy((*button)->button);
    if ((*button)->name)
        nsf_free_any((*button)->name, game);
    *button = nsf_free_any(*button, game);
    return EXIT_SUCCESS;
}
