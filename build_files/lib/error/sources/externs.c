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
    err_null,
    err_null_simple,
    err_int,
    err_int_simple,
    err_int_error,
    err_int_error_simple,
};
