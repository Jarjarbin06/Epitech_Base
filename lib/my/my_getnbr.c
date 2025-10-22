/*
** EPITECH PROJECT, 2025
** my_evil_str.c
** File description:
** None
*/

#include "my.h"

static int is_good_char(char const *str, int len, int last_idx)
{
    int check = 1;

    if (!(is_num(str[last_idx])))
        check = 0;
    if (!check && (str[last_idx] == '-' || str[last_idx] == '+'))
        check = 1;
    if (str[last_idx] == '\0')
        check = 0;
    if (len == 0)
        check = 0;
    return check;
}

static int get_neg_count(char const *str, int len, int *last_idx)
{
    int neg_count = 0;

    for (; is_good_char(str, len, last_idx[0]); last_idx[0]++)
        if (str[*last_idx] == '-')
            neg_count++;
    return neg_count;
}

static int make_neg(int nbr, int neg_count)
{
    if (neg_count % 2 != 0)
        nbr = nbr * -1;
    return nbr;
}

int my_getnbr(char const *str)
{
    int neg_count = 0;
    int len = my_strlen(str);
    int last_idx = 0;
    int nbr = 0;

    if (!is_good_char(str, len, last_idx))
        return 0;
    neg_count = get_neg_count(str, len, &last_idx);
    for (int idx = 0; idx < last_idx; idx++)
        if (is_num(str[idx])) {
            nbr *= 10;
            nbr += (str[idx] - 48);
        }
    nbr = make_neg(nbr, neg_count);
    return nbr;
}
