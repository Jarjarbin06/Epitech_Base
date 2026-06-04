/*
** EPITECH PROJECT, 2026
** EpitechBase - show.c
** File description:
** <description>
*/

#include "../../includes/newerror.h"

static void put_indent(void)
{
    str_putstr(C_ERROR_TITLE);
    str_put_char(' ');
    str_putstr(C_RESET);
    str_put_char(' ');
    str_putstr(C_ERROR);
}

static void new_line(void)
{
    str_putstr(C_RESET);
    str_put_char('\n');
}

static void put_separation(void)
{
    str_putstr(C_ERROR);
    str_putstr("----------");
    new_line();
}

static void put_error_fatal(const err_t error[])
{
    if (!error || !error->fatal)
        return;
    put_indent();
    str_putstr("/!\\ FATAL /!\\");
    new_line();
}

static void put_error_name(const err_t error[])
{
    if (!error)
        return;
    put_indent();
    if (error->title && str_strlen(error->title)) {
        str_putstr(error->title);
        str_put_char(':');
    } else
        str_putstr("Error:");
    new_line();
}

static void put_error_message(const err_t error[])
{
    if (!error || !error->msg || !str_strlen(error->msg)) {
        put_indent();
        return new_line();
    }
    put_indent();
    str_putstr(error->msg);
    new_line();
    put_indent();
    new_line();
}

static void put_error_info(const err_t error[])
{
    if (!error || !error->file || !error->func)
        return;
    put_indent();
    str_putstr("\"");
    str_putstr(error->file);
    str_putstr("\" in ");
    str_putstr(error->func);
    str_putstr("() at line ");
    str_put_nbr((int)error->line);
    new_line();
}

void err_print(const err_t error[])
{
    if (!error)
        return;
    put_separation();
    put_error_fatal(error);
    put_error_name(error);
    put_error_message(error);
    put_error_info(error);
}
