/*
** EPITECH PROJECT, 2025
** my_printf.c
** File description:
** None
*/

#include <stddef.h>
#include <stdarg.h>
#include "../includes/print.h"
#include "../includes/print_conv.h"

static const list_t Valid_Conv[] = {
    {'d', NULL},
    {'i', NULL},
    {'o', NULL},
    {'u', NULL},
    {'x', NULL},
    {'X', NULL},
    {'e', NULL},
    {'E', NULL},
    {'f', NULL},
    {'F', NULL},
    {'g', NULL},
    {'G', NULL},
    {'a', NULL},
    {'A', NULL},
    {'c', NULL},
    {'s', NULL},
    {'p', NULL},
    {'n', NULL},
    {'m', NULL},
    {'%', NULL},
    {'\n', NULL},
    {'\0', NULL}
};

static int is_valid(const char *format, const int idx, flag_t *Flag)
{
    if (get_flag(format, idx, Flag)
        || is_num(format[idx])
        || format[idx] == '\0')
        return 1;
    return 0;
}

static int count_space(const char *format, int idx, flag_t *Flag)
{
    idx++;
    while (is_valid(format, idx, Flag)) {
        idx++;
        if (format[idx] == '\0')
            return (idx - 1);
    }
    return idx;
}

static int get_is_conv(const char c)
{
    for (int i = 0; Valid_Conv[i].conv != '\0'; i++)
        if (c == Valid_Conv[i].conv)
            return 1;
    return 0;
}

static void modify_conv_and_done(int *is_conv, int *if_done,
    const int ic, const int id)
{
    *is_conv = ic;
    *if_done = id;
}

static int check_format(const char *format)
{
    int is_conv = 0;
    int width = 0;
    int precision = -1;
    char len_mod = '0';
    flag_t Flag[] = {{0, 0, 0, 0, 0, &width, &precision, &len_mod}};
    int if_done = 0;

    if (format == NULL)
        return 0;
    for (int idx = 0; format[idx] != '\0'; idx++) {
        if (is_conv && (get_is_conv(format[idx]) || format[idx] == '%'))
            modify_conv_and_done(&is_conv, &if_done, 0, 1);
        if (is_conv && !is_valid(format, idx, Flag))
            return 0;
        if (!if_done && (!is_conv && format[idx] == '%'))
            modify_conv_and_done(&is_conv, &if_done, 1, 0);
    }
    return !is_conv;
}

static void display(va_list list, display_param_t *Disp)
{
    int width = 0;
    int precision = -1;
    char len_mod = '0';
    flag_t Flag[] = {{0, 0, 0, 0, 0, &width, &precision, &len_mod}};
    const int new_i = count_space(Disp->format, Disp->i, Flag);

    *(Flag[0].length_mod) = Disp->format[new_i - 1];
    display_conv(Disp->format[new_i], list, &Disp->char_total, Flag);
    Disp->i = new_i;
}

int print(const char *format, ...)
{
    va_list list;
    display_param_t Disp;

    Disp.format = format;
    if (!check_format(Disp.format))
        return -1;
    va_start(list, format);
    Disp.i = 0;
    Disp.char_total = 0;
    for (; format[Disp.i] != '\0'; Disp.i++)
        if (format[Disp.i] == '%' && format[Disp.i + 1] != '\0')
            display(list, &Disp);
        else
            my_put_char(format[Disp.i], &Disp.char_total);
    va_end(list);
    return Disp.char_total;
}
