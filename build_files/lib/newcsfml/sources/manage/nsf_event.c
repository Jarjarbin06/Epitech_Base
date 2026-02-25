/*
** EPITECH PROJECT, 2026
** EpitechBase - nsf_event.c
** File description:
** <description>
*/

#include "../../includes/newcsfml.h"

bool nsf_cmp_event(const nsf_event *event, const nsf_event_type event_type)
{
    return (event->type == (sfEventType)event_type);
}

bool nsf_cmp_key(const nsf_event *event, const nsf_key_code key_code)
{
    return (event->key.code == (sfKeyCode)key_code);
}
