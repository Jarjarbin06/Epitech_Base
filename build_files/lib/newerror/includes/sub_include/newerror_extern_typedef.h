/*
** EPITECH PROJECT, 2025
** sub_includes - newerror_extern_typedef.h
** File description:
** <description>
*/

// Typedef //
#ifndef NEWERROR_EXTERN_T
    #define NEWERROR_EXTERN_T

    #include <stdbool.h>
    #include "newerror_typedef.h"

#ifndef T_NEWERROR_DATA
        #define T_NEWERROR_DATA
typedef struct {
    err_t *(*upt)(const err_t *, title_t, message_t);
    err_t *(*ftl)(const err_t *);
} error_data_t;
    #endif

    #ifndef T_NEWERROR_LIST
        #define T_NEWERROR_LIST
typedef struct {
    const error_data_t data;
    void (*v)(const err_t[]);
    void (*v_s)(title_t, message_t);
    void *(*p)(const err_t[], void *);
    void *(*p_s)(title_t, message_t, void *);
    void *(*pn)(const err_t[]);
    void *(*pn_s)(title_t, message_t);
    int (*i)(const err_t[], int);
    int (*i_s)(title_t, message_t, int);
    int (*ie)(const err_t[]);
    int (*ie_s)(title_t, message_t);
    bool (*b)(const err_t[], bool);
    bool (*b_s)(title_t, message_t, bool);
    bool (*bf)(const err_t[]);
    bool (*bf_s)(title_t, message_t);
} error_list_t;
    #endif

    #ifndef T_NEWERROR_SHORTCUT_VERROR
        #define T_NEWERROR_SHORTCUT_VERROR
typedef void (*error_shortcut_verror_t)(const err_t[]);
    #endif

    #ifndef T_NEWERROR_SHORTCUT_NERROR
        #define T_NEWERROR_SHORTCUT_NERROR
typedef void *(*error_shortcut_nerror_t)(const err_t[]);
    #endif

    #ifndef T_NEWERROR_SHORTCUT_IERROR
        #define T_NEWERROR_SHORTCUT_IERROR
typedef int (*error_shortcut_ierror_t)(const err_t[]);
    #endif

    #ifndef T_NEWERROR_SHORTCUT_FERROR
        #define T_NEWERROR_SHORTCUT_FERROR
typedef bool (*error_shortcut_ferror_t)(const err_t[]);
    #endif

    #ifndef T_NEWERROR_SHORTCUT_UPT
        #define T_NEWERROR_SHORTCUT_UPT
typedef err_t *(*error_shortcut_upt_t)(const err_t *, const title_t,
    const message_t);
    #endif

    #ifndef T_NEWERROR_SHORTCUT_FTL
        #define T_NEWERROR_SHORTCUT_FTL
typedef err_t *(*error_shortcut_ftl_t)(const err_t *);
    #endif

#endif
