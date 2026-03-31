/*
** EPITECH PROJECT, 2025
** my_printf.h
** File description:
** None
*/

#ifndef PRINTF_MY_TYPE_H
    #define PRINTF_MY_TYPE_H
    #include <stdarg.h>
    #include <stdbool.h>

typedef void (*p_var_ptr_t)(void *);
typedef unsigned long long int (p_lli_t);
typedef double (p_ld_t);

typedef struct p_flag_length_s {
    bool is_hashtag;
    bool is_zero;
    bool is_dash;
    bool is_space;
    bool is_plus;
    int *width;
    int *precision;
    char *length_mod;
} p_flag_t;

typedef struct p_struct_list_s {
    char conv;
    void (*func)(va_list, int *, p_flag_t *Flag);
} p_list_t;

typedef struct p_struct_display_param_s {
    const char *format;
    int i;
    int char_total;
} p_display_param_t;

#endif
