/*
** EPITECH PROJECT, 2025
** sub_includes - newerror_prototype.h
** File description:
** <description>
*/

// Prototype //
#ifndef NEWERROR_P
    #define NEWERROR_P

    #include "newerror_include.h"
    #include "newerror_typedef.h"

#ifndef NEWERROR_P_BASE
        #define NEWERROR_P_BASE
void error_exist(void);
    #endif

    #ifndef NEWERROR_P_PRINT_ERROR
        #define NEWERROR_P_PRINT_ERROR
void err_print(const err_t error[]);
    #endif

    #ifndef NEWERROR_P_ERR_UPT
        #define NEWERROR_P_ERR_UPT
err_t *err_data_upt(const err_t *error, title_t title, message_t msg);
    #endif

    #ifndef NEWERROR_P_ERR_FTL
        #define NEWERROR_P_ERR_FTL
err_t *err_data_ftl(const err_t *error);
    #endif

    #ifndef NEWERROR_P_ERR_NULL
        #define NEWERROR_P_ERR_NULL
void *err_pointer_null(const err_t error[]);
    #endif

    #ifndef NEWERROR_P_ERR_NULL_SIMPLE
        #define NEWERROR_P_ERR_NULL_SIMPLE
void *err_pointer_null_simple(title_t title, message_t msg);
    #endif

    #ifndef NEWERROR_P_ERR_POINTER
        #define NEWERROR_P_ERR_POINTER
void *err_pointer(const err_t error[], void *ptr);
    #endif

    #ifndef NEWERROR_P_ERR_POINTER_SIMPLE
        #define NEWERROR_P_ERR_POINTER_SIMPLE
void *err_pointer_simple(title_t title, message_t msg, void *ptr);
    #endif

    #ifndef NEWERROR_P_ERR_ERROR
        #define NEWERROR_P_ERR_ERROR
int err_int_error(const err_t error[]);
    #endif

    #ifndef NEWERROR_P_ERR_ERROR_SIMPLE
        #define NEWERROR_P_ERR_ERROR_SIMPLE
int err_int_error_simple(title_t title, message_t msg);
    #endif

    #ifndef NEWERROR_P_ERR_INT
        #define NEWERROR_P_ERR_INT
int err_int(const err_t error[], int i);
    #endif

    #ifndef NEWERROR_P_ERR_INT_SIMPLE
        #define NEWERROR_P_ERR_INT_SIMPLE
int err_int_simple(title_t title, message_t msg, int i);
    #endif

    #ifndef NEWERROR_P_ERR_FALSE
        #define NEWERROR_P_ERR_FALSE
bool err_bool_false(const err_t error[]);
    #endif

    #ifndef NEWERROR_P_ERR_FALSE_SIMPLE
        #define NEWERROR_P_ERR_FALSE_SIMPLE
bool err_bool_false_simple(title_t title, message_t msg);
    #endif

    #ifndef NEWERROR_P_ERR_BOOL
        #define NEWERROR_P_ERR_BOOL
bool err_bool(const err_t error[], bool b);
    #endif

    #ifndef NEWERROR_P_ERR_BOOL_SIMPLE
        #define NEWERROR_P_ERR_BOOL_SIMPLE
bool err_bool_simple(title_t title, message_t msg, bool b);
    #endif

    #ifndef NEWERROR_P_ERR_VOID
        #define NEWERROR_P_ERR_VOID
void err_void(const err_t error[]);
    #endif

    #ifndef NEWERROR_P_ERR_VOID_SIMPLE
        #define NEWERROR_P_ERR_VOID_SIMPLE
void err_void_simple(title_t title, message_t msg);
    #endif

/* OTHER LIB */
    #ifndef P_STR_PUTCHAR
        #define P_STR_PUTCHAR
int str_put_char(char c);
    #endif

    #ifndef P_STR_PUTSTR
        #define P_STR_PUTSTR
int str_putstr(const char *str);
    #endif

    #ifndef P_STR_STRLEN
        #define P_STR_STRLEN
int str_strlen(const char *str);
    #endif

    #ifndef P_STR_PUT_NBR
        #define P_STR_PUT_NBR
void str_put_nbr(int nbr);
    #endif

#endif
