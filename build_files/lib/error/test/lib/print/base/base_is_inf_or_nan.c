/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include <math.h>
#include "../includes/print.h"

int p_is_inf_or_nan(p_ld_t nb, int *char_total, int is_maj)
{
    char *inf = "inf";
    char *nan = "nan";

    if (is_maj) {
        inf = "INF";
        nan = "NAN";
    }
    if (nb == INFINITY) {
        p_put_str(inf, char_total);
        return 1;
    }
    if (nb != nb) {
        p_put_str(nan, char_total);
        return 1;
    }
    return 0;
}
