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

static void check_key(nsf_window *window, nsf_event *event)
{
    if (nsf_cmp_event(event, nsf_evt_key_pressed)) {
        // print massege when space is pressed
        if (nsf_cmp_key(event, nsf_key_space))
            print("space pressed\n");
        // close window if escape pressed
        if (nsf_cmp_key(event, nsf_key_escape))
            nsf_window_close(window);
    }
}

static void check_event(nsf_window *window, nsf_event *event)
{
    while (nsf_window_get_event(window, event)) {
        // close window when close button pressed
        if (nsf_cmp_event(event, nsf_evt_closed))
            nsf_window_close(window);
        // print massege when window lost focus
        if (nsf_cmp_event(event, nsf_evt_lost_focus))
            print("unfocused\n");
        // print massege when window gain focus
        if (nsf_cmp_event(event, nsf_evt_gained_focus))
            print("focused\n");
        check_key(window, event);
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

    while (nsf_window_isopen(window)) {
        check_event(window, &event);
        nsf_window_fill(window, nsf_clr_white);
        nsf_window_draw_line(window, (nsf_vector){0, 0},
            (nsf_vector){x, y}, nsf_clr_black);
        nsf_window_display(window);
        x -= 0.01f;
        y += 0.01f;
    }
    nsf_window_destroy(&window, NULL);
    return EXIT_SUCCESS;
}
