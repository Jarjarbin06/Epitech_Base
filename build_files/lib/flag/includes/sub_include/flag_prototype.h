/*
** EPITECH PROJECT, 2025
** sub_includes - file_prototype.h
** File description:
** <description>
*/

// Prototype //
#ifndef FLAG_P
    #define FLAG_P

    #include "flag_include.h"
    #include "flag_typedef.h"

    #ifndef FLAG_P_BASE
        #define FLAG_P_BASE
void flag_exist(void);
    #endif

    #ifndef P_FLAG_CREATE
        #define P_FLAG_CREATE
flags_t *flag_create(size_t size);
    #endif

    #ifndef P_FLAG_DESTROY
        #define P_FLAG_DESTROY
int flag_destroy(flags_t **flags);
    #endif

    #ifndef P_FLAG_ADD
        #define P_FLAG_ADD
int flag_add(flags_t *flags, const flag_set_t flag_set[]);
    #endif

    #ifndef P_FLAG_ADD_BATCH
        #define P_FLAG_ADD_BATCH
int flag_add_batch(flags_t *flags, size_t len, const flag_set_t flag_set[]);
    #endif

    #ifndef P_FLAG_LOAD
        #define P_FLAG_LOAD
int flag_load(flags_t *flags, int argc, const char *const *argv);
    #endif

    #ifndef P_FLAG_SHOW
        #define P_FLAG_SHOW
void flag_show(const flags_t *flags);
    #endif

    #ifndef P_FLAG_GET
        #define P_FLAG_GET
const flag_t *flag_get(flags_t *flags, const char *flag);
    #endif

    #ifndef P_FLAG_GET_ACTIVE
        #define P_FLAG_GET_ACTIVE
bool flag_get_active(flags_t *flags, const char *flag);
    #endif

    #ifndef P_FLAG_GET_VALUE
        #define P_FLAG_GET_VALUE
const char *flag_get_value(flags_t *flags, const char *flag);
    #endif

/* OTHER LIB */
    #ifndef P_MALLOC_ANY
        #define P_MALLOC_ANY
void *malloc_any(unsigned size);
    #endif

    #ifndef P_FREE_ANY
        #define P_FREE_ANY
void *free_any(void *ptr);
    #endif

    #ifndef P_AUTO_FREE
        #define P_AUTO_FREE
int auto_free(unsigned len, free_t free_list[]);
    #endif

    #ifndef P_FREE_ARRAY
        #define P_FREE_ARRAY
void *free_array(void **array);
    #endif

    #ifndef T_STR
        #define T_STR
typedef char *str_t;
    #endif

    #ifndef T_CSTR
        #define T_CSTR
typedef const char *cstr_t;
    #endif

    #ifndef T_CC
        #define T_CC
typedef const char cc_t;
    #endif

    #ifndef P_STR_DUP
        #define P_STR_DUP
str_t str_dup(cstr_t src);
    #endif

    #ifndef P_STR_LEN
        #define P_STR_LEN
int str_len(cstr_t string);
    #endif

    #ifndef P_STR_CMP
        #define P_STR_CMP
int str_cmp(cstr_t str1, cstr_t str2);
    #endif

#endif
