/*
** EPITECH PROJECT, 2026
** EpitechBase - null.c
** File description:
** <description>
*/

#include "../../includes/newerror.h"

static void set_bool_error(err_t error[])
{
    if (error && !error->title)
        error->title = "(BOOL)Error";
}

static void set_bool_err_error(err_t error[])
{
    if (error && !error->title)
        error->title = "(BOOL/FALSE)Error";
}

bool err_bool(const err_t error[], const bool b)
{
    set_bool_error((err_t *)error);
    if (error)
        err_print(error);
    return b;
}

bool err_bool_false(const err_t error[])
{
    set_bool_err_error((err_t *)error);
    if (error)
        err_print(error);
    return false;
}

bool err_bool_simple(const title_t title, const message_t msg, const bool b)
{
    if (title)
        str_putstr(title);
    else
        str_putstr("(BOOL)Error");
    if (msg) {
        str_putstr(": ");
        str_putstr(msg);
    }
    str_put_char('\n');
    return b;
}

bool err_bool_false_simple(const title_t title, const message_t msg)
{
    if (title)
        str_putstr(title);
    else
        str_putstr("(BOOL/FALSE)Error");
    if (msg) {
        str_putstr(": ");
        str_putstr(msg);
    }
    str_put_char('\n');
    return false;
}
