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

typedef void (*var_ptr_t)(void *);
typedef unsigned long long int (my_lli_t);
typedef double (my_ld_t);

typedef struct flag_length_s {
    bool is_hashtag;
    bool is_zero;
    bool is_dash;
    bool is_space;
    bool is_plus;
    int *width;
    int *precision;
    char *length_mod;
} flag_t;

typedef struct struct_list_s {
    char conv;
    void (*func)(va_list, int *, flag_t *Flag);
} list_t;

typedef struct struct_display_param_s {
    const char *format;
    int i;
    int char_total;
} display_param_t;

#endif
