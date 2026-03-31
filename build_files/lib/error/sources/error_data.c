/*
** EPITECH PROJECT, 2026
** EpitechBase - error_data.c
** File description:
** <description>
*/

#include "../includes/error.h"

err_t *err_data_upt(err_t *error, const title_t title, const message_t msg)
{
    if (title)
        error->title = title;
    if (msg)
        error->msg = msg;
    return error;
}

err_t *err_data_ftl(err_t *error)
{
    error->fatal = true;
    return error;
}