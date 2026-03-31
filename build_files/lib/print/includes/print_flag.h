/*
** EPITECH PROJECT, 2025
** mini_printf.h
** File description:
** None
*/

#ifndef PRINTF_MY_FLAG_H
    #define PRINTF_MY_FLAG_H
    #include "print_type.h"

int p_flag_err(const char *format, int idx, p_flag_t *Flag);
int p_get_flag(const char *format, int idx, p_flag_t *Flag);
int p_get_hashtag(const char *format, int idx, p_flag_t *Flag);
int p_get_plus(const char *format, int idx, p_flag_t *Flag);
int p_get_precision(const char *format, int idx, p_flag_t *Flag);
int p_get_space(const char *format, int idx, p_flag_t *Flag);

#endif
