/*
** EPITECH PROJECT, 2025
** sources - str_getnbr.c
** File description:
** <description>
*/

#include "../../includes/str.h"

static bool is_good_char(const cstr_t string, const int len, const int last_idx)
{
    bool check = true;

    if (!string)
        return false;
    if (!(str_c_is_num(string[last_idx])))
        check = false;
    if (!check && (string[last_idx] == '-' || string[last_idx] == '+'))
        check = true;
    if (string[last_idx] == '\0')
        check = false;
    if (len == 0)
        check = false;
    return check;
}

static int get_neg_count(const cstr_t string, const int len,
    int *const last_idx)
{
    int neg_count = 0;

    if (!string || !last_idx)
        return 0;
    for (; is_good_char(string, len, *last_idx); (*last_idx)++)
        if (string[*last_idx] == '-')
            neg_count++;
    return neg_count;
}

static int make_neg(const int nbr, const int neg_count)
{
    if (neg_count % 2 != 0)
        return nbr * -1;
    return nbr;
}

int str_get_nbr(const cstr_t string)
{
    int neg_count = 0;
    const int len = str_len(string);
    int last_idx = 0;
    int nbr = 0;

    if (!is_good_char(string, len, last_idx))
        return 0;
    neg_count = get_neg_count(string, len, &last_idx);
    for (int idx = 0; idx < last_idx; idx++)
        if (str_c_is_num(string[idx])) {
            nbr *= 10;
            nbr += (string[idx] - 48);
        }
    nbr = make_neg(nbr, neg_count);
    return nbr;
}
