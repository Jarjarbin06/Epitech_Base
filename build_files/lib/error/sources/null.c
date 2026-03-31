/*
** EPITECH PROJECT, 2026
** EpitechBase - null.c
** File description:
** <description>
*/

#include "../includes/error.h"

static void set_error(err_t error[])
{
    if (error && !error->title)
        error->title = "(NULL)Error";
}

void *err_null(const err_t error[])
{
    set_error((err_t *)error);
    if (error)
        err_print(error);
    return NL;
}

void *err_null_simple(const title_t title, const message_t msg)
{
    if (title)
        str_putstr(title);
    else
        str_putstr("(NULL)Error");
    if (msg) {
        str_putstr(": ");
        str_putstr(msg);
    }
    str_putchar('\n');
    return NL;
}
