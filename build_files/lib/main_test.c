/*
** EPITECH PROJECT, 2026
** EpitechBase - main_test.c
** File description:
** <description>
*/

#include "error/includes/error.h"
#include "llist/includes/llist.h"
#include "newcsfml/includes/newcsfml.h"
#include "print/includes/print.h"
#include "str/includes/str.h"
#include "twodlist/includes/twodlist.h"
#include "utils/includes/utils.h"

static void check_button(nsf_window_t *window, nsf_button_t *btn)
{
    if (nsf.button.get_state(btn, window, nsf_mouse_left))
        nsf.window.close(window);
}

static void check_event(nsf_window_t *window, nsf_event_t *event)
{
    while (nsf.window.get_event(window, event)) {
        if (nsf.event.cmp(event, nsf_evt_closed))
            nsf.window.close(window);
        if (nsf.event.cmp(event, nsf_evt_key_pressed) &&
            nsf.event.cmp_key(event, nsf_key_escape))
            nsf.window.close(window);
        if (nsf.event.cmp(event, nsf_evt_mouse_button_pressed))
            check_button(window, nsf.window.get_button(window, "a button"));
    }
}

static nsf_window_t *create_window(nsf_game_t *game)
{
    nsf_window_t *window = nsf.window.create(
        (nsf_window_settings_t[]){{500, 500, 32, 30}},
        "my_window", nsf_wdw_default_style, game);

    return window;
}

static void create_elements(nsf_game_t *game)
{
    nsf_sprite_t *sprite = nsf.sprite.create("a sprite", game);
    nsf_button_t *button = nsf.button.create("a button", game);

    nsf.sprite.set_texture(sprite,
        nsf.texture.create("/home/jarjarbin/Pictures/C.png",
        "sprite texture", game));
    nsf.button.set_texture(button,
        nsf.texture.create("/home/jarjarbin/Pictures/Python.png",
            "button texture", game));
    nsf.button.set_size(button, (nsf_vector[]){{100.0f, 100.0f}});
    nsf.button.set_position(button, (nsf_vector[]){{300.0f, 300.0f}});
    nsf.button.set_colors(button, &nsf.color.transparent, &nsf.color.blue, 2);
    nsf.game.add_button(game, button);
    nsf.game.add_sprite(game, sprite);
}

int main(void)
{
    nsf_event_t event;
    nsf_game_t *game = nsf.game.create();
    nsf.game.set_window(game, create_window(game));

    create_elements(game);
    while (nsf.game.is_open(game)) {
        check_event(nsf.game.get_window(game), &event);
        nsf.window.fill(nsf.game.get_window(game), &nsf.color.white);
        nsf.game.draw(game);
        nsf.game.display(game);
    }
    nsf.game.destroy(&game);
    return EXIT_SUCCESS;
}
