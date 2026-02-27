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
    while (nsf_window.get_event(window, event)) {
        if (nsf_event.cmp(event, nsf_evt_closed))
            nsf_window.close(window);
        if (nsf_event.cmp(event, nsf_evt_key_pressed) &&
            nsf_event.cmp_key(event, nsf_key_escape))
            nsf_window.close(window);
    }
}

static void check_button(nsf_button_t *button, nsf_window_t *window)
{
    if (nsf_button.check_click(button, window, nsf_mouse_left))
        nsf_window.close(window);
}

static nsf_window_t *create_window(nsf_game_t *game)
{
    nsf_window_t *window = nsf_window.create(
        (nsf_window_settings_t){500, 500, 32, 30},
        "my_window", nsf_wdw_default_style, game);

    return window;
}

static nsf_button_t *create_elements(nsf_game_t *game)
{
    nsf_sprite_t *sprite = nsf_sprite.create("a sprite", game);
    nsf_button_t *button = nsf_button.create("a button", game);

    nsf_sprite.set_texture(sprite,
        nsf_texture.create("/home/jarjarbin/Pictures/C.png",
            "sprite texture", game));
    nsf_button.set_size(button, (nsf_vector){100, 100});
    nsf_button.set_position(button, (nsf_vector){300, 300});
    nsf_button.set_colors(button, nsf_clr.transparent, nsf_clr.blue, 2);
    nsf_button.set_texture(button,
        nsf_texture.create("/home/jarjarbin/Pictures/Python.png",
            "button texture", game));
    nsf_game.add_sprite(game, sprite);
    nsf_game.add_button(game, button);
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
