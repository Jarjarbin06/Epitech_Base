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
    char *(*reverse)(char *);
    char *(*capitalize)(char *);
    char *(*lowcase)(char *);
    char *(*upcase)(char *);
    void (*c_swap)(char *, char *);
} str_transform_t;
    #endif

    #ifndef T_STR_PUT
        #define T_STR_PUT
typedef struct {
    void (*nbr)(int);
    int (*chr)(char);
    int (*str)(char *);
} str_put_t;
    #endif

    #ifndef T_STR_CHECK
        #define T_STR_CHECK
typedef struct {
    bool (*c_alpha)(char);
    bool (*alpha)(char *);
    bool (*c_num)(char);
    bool (*num)(char *);
    bool (*c_lower)(char);
    bool (*lower)(char *);
    bool (*c_upper)(char);
    bool (*upper)(char *);
    bool (*c_printable)(char);
    bool (*printable)(char *);
    int (*cmp)(char *, char *);
} str_check_t;
    #endif

    #ifndef T_STR_GET
        #define T_STR_GET
typedef struct {
    int (*nbr)(char *);
    char **(*word_array)(char *, char);
    int (*len)(char *);
} str_get_t;
    #endif

    #ifndef T_STR_MANAGE
        #define T_STR_MANAGE
typedef struct {
    char *(*cat)(char *, char *);
    char *(*cpy)(char *, char *);
    char *(*dup)(char *);
    char *(*ndup)(char *, int);
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
