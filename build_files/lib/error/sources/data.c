/*
** EPITECH PROJECT, 2026
** EpitechBase - data.c
** File description:
** <description>
*/

#include "../includes/error.h"

err_t *err_data_upt(const err_t *error, const title_t title, const message_t
    msg)
{
    err_t *temp_error = (err_t *)error;

    if (title)
        temp_error->title = title;
    if (msg)
        temp_error->msg = msg;
    return temp_error;
}

err_t *err_data_ftl(const err_t *error)
{
    err_t *temp_error = (err_t *)error;

    temp_error->fatal = true;
    return temp_error;
}