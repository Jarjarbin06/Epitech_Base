/*
** EPITECH PROJECT, 2026
** EpitechBase - main_test.c
** File description:
** <description>
*/

#include <unistd.h>

#include "newcsfml/includes/newcsfml.h"
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

static nsf_window_t *create_window(void)
{
    nsf_window_t *window = nsf_window.create(
        (nsf_window_settings_t){500, 500, 32, 30},
        "my_window", nsf_wdw_default_style, NULL);

    return window;
}

static nsf_sprite_t *create_sprite(void)
{
    nsf_sprite_t *sprite = nsf_sprite.create("my_sprite", NULL);

    nsf_sprite.set_texture(sprite,
        nsf_texture.create("/home/jarjarbin/Pictures/C.png",
            "my_texture", NULL));
    return sprite;
}

static nsf_button_t *create_button(void)
{
    nsf_button_t *button = nsf_button.create("my_button", NULL);

    nsf_button.set_size(button, (nsf_vector){100, 50});
    nsf_button.set_position(button, (nsf_vector){300, 300});
    nsf_button.set_colors(button, nsf_clr.blue, nsf_clr.red);
    return button;
}

int main(void)
{
    nsf_event_t event;
    nsf_window_t *window = create_window();
    nsf_sprite_t *sprite = create_sprite();
    nsf_button_t *button = create_button();

    while (nsf_window.isopen(window)) {
        check_button(button, window);
        check_event(window, &event);
        nsf_window.fill(window, nsf_clr.white);
        nsf_button.draw(button, window);
        nsf_sprite.draw(sprite, window);
        nsf_window.display(window);
    }
    nsf_button.destroy(&button, NULL);
    nsf_sprite.destroy(&sprite, NULL);
    nsf_window.destroy(&window, NULL);
    return EXIT_SUCCESS;
}
