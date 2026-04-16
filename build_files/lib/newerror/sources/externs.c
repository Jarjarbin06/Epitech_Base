/*
** EPITECH PROJECT, 2026
** EpitechBase - externs.c
** File description:
** <description>
*/

#include "../includes/newerror.h"

const error_data_t nerr_data = {
    err_data_upt,
    err_data_ftl
};
const error_list_t nerr = {
    nerr_data,
    err_void,
    err_void_simple,
    err_pointer,
    err_pointer_simple,
    err_pointer_null,
    err_pointer_null_simple,
    err_int,
    err_int_simple,
    err_int_error,
    err_int_error_simple,
    err_bool,
    err_bool_simple,
    err_bool_false,
    err_bool_false_simple
};
const error_shortcut_verror_t v_err = err_void;
const error_shortcut_nerror_t n_err = err_pointer_null;
const error_shortcut_ierror_t i_err = err_int_error;
const error_shortcut_ferror_t f_err = err_bool_false;
const error_shortcut_upt_t upt = err_data_upt;
const error_shortcut_ftl_t ftl = err_data_ftl;
