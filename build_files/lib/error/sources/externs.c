/*
** EPITECH PROJECT, 2026
** EpitechBase - externs.c
** File description:
** <description>
*/

#include "../includes/error.h"

const error_data_t err_data = {
    err_data_upt,
    err_data_ftl
};
const error_list_t err = {
    err_data,
    err_pointer,
    err_pointer_simple,
    err_pointer_null,
    err_pointer_null_simple,
    err_int,
    err_int_simple,
    err_int_error,
    err_int_error_simple,
};
const error_shortcut_nerror_t nerror = err.pn;
const error_shortcut_ierror_t ierror = err.ie;
const error_shortcut_upt_t upt = err.data.upt;
const error_shortcut_ftl_t ftl = err.data.ftl;
