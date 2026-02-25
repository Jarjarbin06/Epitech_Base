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

static void check_event(nsf_window *window, nsf_event *event)
{
    while (nsf_window_get_event(window, event)) {
        if (nsf_cmp_event(event, nsf_evt_closed))
            nsf_window_close(window);
        if (nsf_cmp_event(event, nsf_evt_key_pressed) &&
            nsf_cmp_key(event, nsf_key_escape))
            nsf_window_close(window);
    }
}

int main(void)
{
    float x = 500;
    float y = 0;
    nsf_event event;
    nsf_window *window = nsf_window_create(
        (nsf_window_settings){500, 500, 64, 30},
        "my_window", nsf_wdw_default_style, NULL);
    nsf_sprite *sprite = nsf_sprite_create("my_sprite", NULL);
    nsf_sprite_set_texture(sprite,
        nsf_texture_create("/home/jarjarbin/Pictures/C.png",
            "my_texture", NULL));
    while (nsf_window_isopen(window)) {
        check_event(window, &event);
        nsf_window_fill(window, nsf_clr_white);
        nsf_window_draw_line(window, (nsf_vector){250, 250},
            (nsf_vector){x, y}, nsf_clr_black);
        nsf_sprite_draw(sprite, window);
        nsf_window_display(window);
        x -= 0.05f;
        y += 0.05f;
        if (x < 0)
            x = 500;
        if (y > 500)
            y = 0;
    }
    nsf_sprite_destroy(&sprite, NULL);
    nsf_window_destroy(&window, NULL);
    return EXIT_SUCCESS;
}
