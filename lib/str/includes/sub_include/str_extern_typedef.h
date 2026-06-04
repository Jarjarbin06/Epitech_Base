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
    int (*str)(const char *);
} str_put_t;
    #endif

    #ifndef T_STR_CHECK
        #define T_STR_CHECK
typedef struct {
    bool (*c_alpha)(char);
    bool (*alpha)(const char *);
    bool (*c_num)(char);
    bool (*num)(const char *);
    bool (*c_lower)(char);
    bool (*lower)(const char *);
    bool (*c_upper)(char);
    bool (*upper)(const char *);
    bool (*c_printable)(char);
    bool (*printable)(const char *);
    int (*cmp)(const char *, const char *);
} str_check_t;
    #endif

    #ifndef T_STR_GET
        #define T_STR_GET
typedef struct {
    int (*nbr)(const char *);
    char **(*split)(const char *, char);
    size_t (*len)(const char *);
} str_get_t;
    #endif

    #ifndef T_STR_MANAGE
        #define T_STR_MANAGE
typedef struct {
    char *(*cat)(const char *, const char *);
    char *(*copy)(char *, const char *);
    char *(*dup)(const char *);
    char *(*ndup)(const char *, int);
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
