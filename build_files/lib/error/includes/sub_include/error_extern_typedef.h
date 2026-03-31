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

    #ifndef T_ERROR_DATA
        #define T_ERROR_DATA
typedef struct {
    err_t *(*upt)(err_t *, const title_t, const message_t);
    err_t *(*ftl)(err_t *);
} error_data_t;
    #endif

    #ifndef T_ERROR_LIST
        #define T_ERROR_LIST
typedef struct {
    error_data_t data;
    void *(*n)(const err_t[]);
    void *(*n_s)(const title_t, const message_t);
    int (*i)(const err_t[], const int);
    int (*i_s)(const title_t, const message_t, const int);
    int (*ie)(const err_t[]);
    int (*ie_s)(const title_t, const message_t);
} error_list_t;
    #endif

#endif
