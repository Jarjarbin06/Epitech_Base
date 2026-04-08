/*
** EPITECH PROJECT, 2025
** sub_includes - error_prototype.h
** File description:
** <description>
*/

// Prototype //
#ifndef ERROR_P
    #define ERROR_P

    #include "error_include.h"
    #include "error_typedef.h"

    #ifndef ERROR_P_BASE
        #define ERROR_P_BASE
void error_exist(void);
    #endif

    #ifndef ERROR_P_PRINT_ERROR
        #define ERROR_P_PRINT_ERROR
void err_print(const err_t error[]);
    #endif

    #ifndef ERROR_P_ERR_UPT
        #define ERROR_P_ERR_UPT
err_t *err_data_upt(const err_t *error, title_t title, message_t msg);
    #endif

    #ifndef ERROR_P_ERR_FTL
        #define ERROR_P_ERR_FTL
err_t *err_data_ftl(const err_t *error);
    #endif

    #ifndef ERROR_P_ERR_NULL
        #define ERROR_P_ERR_NULL
void *err_pointer_null(const err_t error[]);
    #endif

    #ifndef ERROR_P_ERR_NULL_SIMPLE
        #define ERROR_P_ERR_NULL_SIMPLE
void *err_pointer_null_simple(title_t title, message_t msg);
    #endif

    #ifndef ERROR_P_ERR_POINTER
        #define ERROR_P_ERR_POINTER
void *err_pointer(const err_t error[], void *ptr);
    #endif

    #ifndef ERROR_P_ERR_POINTER_SIMPLE
        #define ERROR_P_ERR_POINTER_SIMPLE
void *err_pointer_simple(title_t title, message_t msg, void *ptr);
    #endif

    #ifndef ERROR_P_ERR_ERROR
        #define ERROR_P_ERR_ERROR
int err_int_error(const err_t error[]);
    #endif

    #ifndef ERROR_P_ERR_ERROR_SIMPLE
        #define ERROR_P_ERR_ERROR_SIMPLE
int err_int_error_simple(title_t title, message_t msg);
    #endif

    #ifndef ERROR_P_ERR_INT
        #define ERROR_P_ERR_INT
int err_int(const err_t error[], int i);
    #endif

    #ifndef ERROR_P_ERR_INT_SIMPLE
        #define ERROR_P_ERR_INT_SIMPLE
int err_int_simple(title_t title, message_t msg, int i);
    #endif

    #ifndef ERROR_P_ERR_VOID
        #define ERROR_P_ERR_VOID
void err_void(const err_t error[]);
    #endif

    #ifndef ERROR_P_ERR_VOID_SIMPLE
        #define ERROR_P_ERR_VOID_SIMPLE
void err_void_simple(title_t title, message_t msg);
    #endif

/* OTHER LIB */
    #ifndef P_STR_PUTCHAR
        #define P_STR_PUTCHAR
int str_putchar(char c);
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
