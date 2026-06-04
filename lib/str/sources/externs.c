/*
** EPITECH PROJECT, 2026
** EpitechBase - externs.c
** File description:
** <description>
*/

#include "../includes/str.h"

const str_transform_t transform = {
    str_reverse,
    str_capitalize,
    str_lowcase,
    str_upcase,
    str_c_swap
};

const str_put_t put = {
    str_put_nbr,
    str_put_char,
    str_put_str
};

const str_check_t check = {
    str_c_is_alpha,
    str_is_alpha,
    str_c_is_num,
    str_is_num,
    str_c_is_lower,
    str_is_lower,
    str_c_is_upper,
    str_is_upper,
    str_c_is_printable,
    str_is_printable,
    str_cmp
};

const str_get_t get = {
    str_get_nbr,
    str_split,
    str_len
};

const str_manage_t manage = {
    str_cat,
    str_cpy,
    str_dup,
    str_ndup
};

const str_str_t str = {
    transform,
    put,
    check,
    get,
    manage
};
