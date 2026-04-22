/*
** EPITECH PROJECT, 2026
** EpitechBase - nsf_event.c
** File description:
** <description>
*/

#include "../../includes/newcsfml.h"

bool nsf_event_cmp(const nsf_event_t *event, const nsf_event_type_t event_type)
{
    return (event->type == (sfEventType)event_type);
}

bool nsf_event_cmp_key(const nsf_event_t *event, const nsf_key_code_t key_code)
{
    return (event->key.code == (sfKeyCode)key_code);
}

void nsf_event_get_mouse_move(const nsf_event_t *event,
    nsf_ivector_t vect[])
{
    if (!event || !vect)
        return;
    vect->x = event->mouseMove.x;
    vect->y = event->mouseMove.y;
}

float nsf_event_get_mouse_wheel(const nsf_event_t *event)
{
    if (!event)
        return 0.0f;
    return event->mouseWheelScroll.delta;
}
