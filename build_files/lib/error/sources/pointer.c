/*
** EPITECH PROJECT, 2026
** EpitechBase - null.c
** File description:
** <description>
*/

#include "../includes/error.h"


static void set_pointer_error(err_t error[])
{
    if (error && !error->title)
        error->title = "(POINTER)Error";
}

static void set_pointer_null_error(err_t error[])
{
    if (error && !error->title)
        error->title = "(POINTER/NULL)Error";
}

void *err_pointer(const err_t error[], void *ptr)
{
    set_pointer_error((err_t *)error);
    if (error)
        err_print(error);
    return ptr;
}

void *err_pointer_null(const err_t error[])
{
    set_pointer_null_error((err_t *)error);
    if (error)
        err_print(error);
    return NL;
}

void *err_pointer_simple(const title_t title, const message_t msg, void *ptr)
{
    if (title)
        str_putstr(title);
    else
        str_putstr("(POINTER)Error");
    if (msg) {
        str_putstr(": ");
        str_putstr(msg);
    }
    str_putchar('\n');
    return ptr;
}

void *err_pointer_null_simple(const title_t title, const message_t msg)
{
    if (title)
        str_putstr(title);
    else
        str_putstr("(POINTER/NULL)Error");
    if (msg) {
        str_putstr(": ");
        str_putstr(msg);
    }
    str_putchar('\n');
    return NL;
}
