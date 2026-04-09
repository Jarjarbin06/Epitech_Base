/*
** EPITECH PROJECT, 2025
** sub_includes - newcsfml_typedef.h
** File description:
** <description>
*/

// Typedef //
#ifndef STR_EXTERN_T
    #define STR_EXTERN_T

    #include <stdbool.h>
    #include "str_typedef.h"

    #ifndef T_STR_TRANSFORM
        #define T_STR_TRANSFORM
typedef struct {
    str_t (*reverse)(str_t);
    str_t (*capitalize)(str_t);
    str_t (*lowcase)(str_t);
    str_t (*upcase)(str_t);
    void (*c_swap)(str_t, str_t);
} str_transform_t;
    #endif

    #ifndef T_STR_PUT
        #define T_STR_PUT
typedef struct {
    void (*nbr)(int);
    int (*chr)(char);
    int (*str)(str_t);
} str_put_t;
    #endif

    #ifndef T_STR_CHECK
        #define T_STR_CHECK
typedef struct {
    bool (*c_alpha)(char);
    bool (*alpha)(str_t);
    bool (*c_num)(char);
    bool (*num)(str_t);
    bool (*c_lower)(char);
    bool (*lower)(str_t);
    bool (*c_upper)(char);
    bool (*upper)(str_t);
    bool (*c_printable)(char);
    bool (*printable)(str_t);
    int (*cmp)(str_t, str_t);
} str_check_t;
    #endif

    #ifndef T_STR_GET
        #define T_STR_GET
typedef struct {
    int (*nbr)(str_t);
    str_t *(*word_array)(str_t, char);
    int (*len)(str_t);
} str_get_t;
    #endif

    #ifndef T_STR_MANAGE
        #define T_STR_MANAGE
typedef struct {
    str_t (*cat)(str_t, str_t);
    str_t (*cpy)(str_t, str_t);
    str_t (*dup)(str_t);
    str_t (*ndup)(str_t, int);
} str_manage_t;
    #endif

    #ifndef T_STR_STR
        #define T_STR_STR
typedef struct {
    str_transform_t t;
    str_put_t p;
    str_check_t c;
    str_get_t g;
    str_manage_t m;
} str_str_t;
    #endif

#endif
