/*
** EPITECH PROJECT, 2026
** EpitechBase - main_test.c
** File description:
** <description>
*/

//#include "llist/includes/llist.h"
#include <unistd.h>

#include "newcsfml/includes/newcsfml.h"
#include "print/includes/print.h"
//#include "str/includes/str.h"
//#include "twodlist/includes/twodlist.h"
//#include "utils/includes/utils.h"

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

int main(void)
{
    nsf_event_t event;
    nsf_window_t *window = nsf_window.create(
        (nsf_window_settings_t){500, 500, 64, 30},
        "my_window", nsf_wdw_default_style, NULL);
    nsf_sprite_t *sprite = nsf_sprite.create("my_sprite", NULL);
    nsf_sprite.set_texture(sprite,
        nsf_texture.create("/home/jarjarbin/Pictures/C.png",
            "my_texture", NULL));
    while (nsf_window.isopen(window)) {
        check_event(window, &event);
        nsf_window.fill(window, nsf_clr.white);
        nsf_sprite.draw(sprite, window);
        nsf_window.display(window);
    }
    nsf_sprite.destroy(&sprite, NULL);
    nsf_window.destroy(&window, NULL);
    return EXIT_SUCCESS;
}
