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
        error->title = "(INT-ERR)Error";
}

int err_int_error(const err_t error[])
{
    set_error((err_t *)error);
    if (error)
        err_print(error);
    return INT_ERR;
}

int err_int(const err_t error[], const int i)
{
    set_error((err_t *)error);
    if (error)
        err_print(error);
    return i;
}

int err_int_error_simple(const title_t title, const message_t msg)
{
    if (title)
        str_putstr(title);
    else
        str_putstr("(INT)Error");
    if (msg) {
        str_putstr(": ");
        str_putstr(msg);
    }
    str_putchar('\n');
    return INT_ERR;
}

int err_int_simple(const title_t title, const message_t msg, const int i)
{
    if (title)
        str_putstr(title);
    else
        str_putstr("(INT)Error");
    if (msg) {
        str_putstr(": ");
        str_putstr(msg);
    }
    str_putchar('\n');
    return i;
}
