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

    #ifndef T_ERROR_SHORTCUT_NERROR
        #define T_ERROR_SHORTCUT_NERROR
typedef void *(*error_shortcut_nerror_t)(const err_t[]);
    #endif

    #ifndef T_ERROR_SHORTCUT_IERROR
        #define T_ERROR_SHORTCUT_IERROR
typedef int (*error_shortcut_ierror_t)(const err_t[]);
    #endif

    #ifndef T_ERROR_SHORTCUT_UPT
        #define T_ERROR_SHORTCUT_UPT
typedef err_t *(*error_shortcut_upt_t)(const err_t *, const title_t,
    const message_t);
    #endif

    #ifndef T_ERROR_SHORTCUT_FTL
        #define T_ERROR_SHORTCUT_FTL
typedef err_t *(*error_shortcut_ftl_t)(const err_t *);
    #endif

#endif
