/*
** EPITECH PROJECT, 2026
** EpitechBase - main_test.c
** File description:
** <description>
*/

#include <unistd.h>

#include "newcsfml/includes/newcsfml.h"
#include "llist/includes/llist.h"
#include "print/includes/print.h"
#include "str/includes/str.h"
#include "twodlist/includes/twodlist.h"
#include "utils/includes/utils.h"

static void check_event(nsf_window_t *window, nsf_event_t *event)
{
    while (nsf.window.get_event(window, event)) {
        if (nsf.event.cmp(event, nsf_evt_closed))
            nsf.window.close(window);
        if (nsf.event.cmp(event, nsf_evt_key_pressed) &&
            nsf.event.cmp_key(event, nsf_key_escape))
            nsf.window.close(window);
    }
}

static void check_button(nsf_button_t *button, nsf_window_t *window)
{
    if (nsf.button.check_click(button, window, nsf_mouse_left))
        nsf.window.close(window);
}

static nsf_window_t *create_window(nsf_game_t *game)
{
    nsf_window_t *window = nsf.window.create(
        (nsf_window_settings_t){500, 500, 32, 30},
        "my_window", nsf_wdw_default_style, game);

    return window;
}

static nsf_button_t *create_elements(nsf_game_t *game)
{
    nsf_sprite_t *sprite = nsf.sprite.create("a sprite", game);
    nsf_button_t *button = nsf.button.create("a button", game);

    nsf.sprite.set_texture(sprite,
        nsf.texture.create("/home/jarjarbin/Pictures/C.png",
            "sprite texture", game));
    nsf.button.set_size(button, (nsf_vector){100, 100});
    nsf.button.set_position(button, (nsf_vector){300, 300});
    nsf.button.set_colors(button, nsf.clr.transparent, nsf.clr.blue, 2);
    nsf.button.set_texture(button,
        nsf.texture.create("/home/jarjarbin/Pictures/Python.png",
            "button texture", game));
    nsf.game.add_sprite(game, sprite);
    nsf.game.add_button(game, button);
    return button;
}

int main(void)
{
    nsf_event_t event;
    nsf_game_t *game = nsf_game.create();
    nsf_game.set_window(game, create_window(game));
    nsf_button_t *button = create_elements(game);

    while (nsf_game.isopen(game)) {
        check_button(button, nsf_game.get_window(game));
        check_event(nsf_game.get_window(game), &event);
        nsf_window.fill(nsf_game.get_window(game), nsf_clr.white);
        nsf_game.draw(game);
        nsf_game.display(game);
    }
    nsf_game.destroy(&game);
    return EXIT_SUCCESS;
}
