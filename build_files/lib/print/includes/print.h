/*
** EPITECH PROJECT, 2025
** mini_printf.h
** File description:
** None
*/

#ifndef PRINT
    #define PRINT
    #include "print_flag.h"
#ifndef EXIT_SUCCESS
    #define EXIT_SUCCESS 0
#endif
#ifndef EXIT_ERROR
    #define EXIT_ERROR 84
#endif
    #define UP_CASE(c, up) ((up) ? (c - 32) : (c))

#ifndef _PRINT_P_BASE
    #define _PRINT_P_BASE
void print_show_macro(void);
void print_exist(void);
#endif

int is_inf_or_nan(my_ld_t nb, int *char_total, int is_maj);

bool is_num(const char c);

int my_get_nbr(char const *str);

int my_strlen(char const *str);

int print(const char *format, ...);

void my_put_char(const char c, int *char_total);

void my_put_str(const char *str, int *char_total);

void redirect_all_std(void);

#endif
