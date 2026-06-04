/*
** EPITECH PROJECT, 2026
** EpitechBase - null.c
** File description:
** <description>
*/

#include "../../includes/newerror.h"

static void set_void_error(err_t error[])
{
    if (error && !error->title)
        error->title = "(VOID)Error";
}

void err_void(const err_t error[])
{
    set_void_error((err_t *)error);
    if (error)
        err_print(error);
}

void err_void_simple(const title_t title, const message_t msg)
{
    if (title)
        str_putstr(title);
    else
        str_putstr("(VOID)Error");
    if (msg) {
        str_putstr(": ");
        str_putstr(msg);
    }
    str_put_char('\n');
}
