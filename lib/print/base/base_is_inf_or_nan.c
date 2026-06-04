/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include <math.h>
#include "../includes/print.h"

int p_is_inf_or_nan(const p_ld_t nb, int *char_total, const int is_maj)
{
    const char *inf = "inf";
    const char *nan = "nan";

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
