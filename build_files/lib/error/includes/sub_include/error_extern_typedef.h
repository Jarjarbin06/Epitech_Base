/*
** EPITECH PROJECT, 2025
** sub_includes - newcsfml_typedef.h
** File description:
** <description>
*/

// Typedef //
#ifndef ERROR_EXTERN_T
    #define ERROR_EXTERN_T

    #include <stdbool.h>
    #include "error_typedef.h"

    #ifndef T_ERROR_DATA
        #define T_ERROR_DATA
typedef struct {
    err_t *(*upt)(const err_t *, const title_t, const message_t);
    err_t *(*ftl)(const err_t *);
} error_data_t;
    #endif

    #ifndef T_ERROR_LIST
        #define T_ERROR_LIST
typedef struct {
    const error_data_t data;
    void *(*p)(const err_t[], void *);
    void *(*p_s)(title_t, message_t, void *);
    void *(*pn)(const err_t[]);
    void *(*pn_s)(title_t, message_t);
    int (*i)(const err_t[], int);
    int (*i_s)(title_t, message_t, int);
    int (*ie)(const err_t[]);
    int (*ie_s)(title_t, message_t);
} error_list_t;
    #endif

#endif
