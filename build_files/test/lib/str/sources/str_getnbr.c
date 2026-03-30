/*
** EPITECH PROJECT, 2025
** sources - str_getnbr.c
** File description:
** <description>
*/

#include "str.h"

static bool is_good_char(const char *str, const int len, const int last_idx)
{
    bool check = true;

    if (!str)
        return false;
    if (!(str_is_num(str[last_idx])))
        check = false;
    if (!check && (str[last_idx] == '-' || str[last_idx] == '+'))
        check = true;
    if (str[last_idx] == '\0')
        check = false;
    if (len == 0)
        check = false;
    return check;
}

static int get_neg_count(const char *str, const int len, int *last_idx)
{
    int neg_count = 0;

    if (!str || !last_idx)
        return 0;
    for (; is_good_char(str, len, last_idx[0]); last_idx[0]++)
        if (str[*last_idx] == '-')
            neg_count++;
    return neg_count;
}

static int make_neg(int nbr, const int neg_count)
{
    if (neg_count % 2 != 0)
        nbr = nbr * -1;
    return nbr;
}

int str_getnbr(const char *str)
{
    int neg_count = 0;
    const int len = str_strlen(str);
    int last_idx = 0;
    int nbr = 0;

    if (!is_good_char(str, len, last_idx))
        return 0;
    neg_count = get_neg_count(str, len, &last_idx);
    for (int idx = 0; idx < last_idx; idx++)
        if (str_is_num(str[idx])) {
            nbr *= 10;
            nbr += (str[idx] - 48);
        }
    nbr = make_neg(nbr, neg_count);
    return nbr;
}
