/*
** EPITECH PROJECT, 2026
** EpitechBase - main_test.c
** File description:
** <description>
*/

//#include "llist/includes/llist.h"
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
        if (nsf_cmp_event(event, nsf_evt_lost_focus))
            nsf_window_close(window);
    }
}

int main(void)
{
    nsf_event event;
    nsf_window *window = nsf_window_create(
        (nsf_window_settings){500, 500, 64, 30},
        "my_window", nsf_wdw_default_style, NULL);
    while (nsf_window_isopen(window)) {
        check_event(window, &event);
        nsf_window_display(window);
    }
    return nsf_window_destroy(&window, NULL);
}
