/*
** EPITECH PROJECT, 2025
** sub_includes - file_typedef.h
** File description:
** <description>
*/

#include <stdio.h>

#include "../includes/flag.h"

static void show_flag(const flag_t *flag)
{
    if (!flag)
        return;
    printf("\"%s\" ", flag->name);
    if (flag->simple || flag->advanced) {
        printf("(");
        if (flag->simple)
            printf("-%c", flag->simple);
        if (flag->simple && flag->advanced)
            printf(", ");
        if (flag->advanced)
            printf("--%s", flag->advanced);
        printf(")");
    }
    if (flag->need_value)
        printf("(need value)");
    printf("\n");
}

void flag_show(const flags_t *flags)
{
    if (!flags)
        return;
    for (size_t idx = 0; idx < flags->max_size; idx++) {
        show_flag(&flags->flags[idx]);
    }
}
