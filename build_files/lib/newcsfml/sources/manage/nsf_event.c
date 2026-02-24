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
