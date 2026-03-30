/*
** EPITECH PROJECT, 2026
** EpitechBase - nsf_event.c
** File description:
** <description>
*/

#include "newcsfml.h"

bool nsf_cmp_event(const nsf_event_t *event, const nsf_event_type_t event_type)
{
    return (event->type == (sfEventType)event_type);
}

bool nsf_cmp_key(const nsf_event_t *event, const nsf_key_code key_code)
{
    return (event->key.code == (sfKeyCode)key_code);
}
