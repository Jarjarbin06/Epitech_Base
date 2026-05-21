/*
** EPITECH PROJECT, 2025
** mini_printf.h
** File description:
** None
*/

#ifndef PRINT
    #define PRINT
    #include "print_flag.h"
    #ifndef E_SUCCESS
        #define E_SUCCESS 0
    #endif
    #ifndef E_ERROR
        #define E_ERROR 84
    #endif
    #define UP_CASE(c, up) ((up) ? (c - 32) : (c))

    #ifndef PRINT_P_BASE
        #define PRINT_P_BASE
void print_exist(void);
    #endif

int p_is_inf_or_nan(p_ld_t nb, int *char_total, int is_maj);

bool p_is_num(char c);

int p_get_nbr(const char *str);

int p_strlen(const char *str);

int print(const char *format, ...);

void p_put_char(char c, int *char_total);

void p_put_str(const char *str, int *char_total);

void redirect_all_std(void);

#endif
