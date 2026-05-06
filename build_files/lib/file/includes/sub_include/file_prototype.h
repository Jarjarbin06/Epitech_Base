/*
** EPITECH PROJECT, 2025
** sub_includes - file_prototype.h
** File description:
** <description>
*/

// Prototype //
#ifndef FILE_P
    #define FILE_P

    #include "file_include.h"
    #include "file_typedef.h"

    #ifndef FILE_P_BASE
        #define FILE_P_BASE
void file_exist(void);
    #endif

    #ifndef P_FILE_CREATE
        #define P_FILE_CREATE
file_t *file_create(const char full_path[]);
    #endif

    #ifndef P_FILE_DESTROY
        #define P_FILE_DESTROY
int file_destroy(file_t **file);
    #endif

    #ifndef P_FILE_SHOW
        #define P_FILE_SHOW
void file_show(file_t *file);
    #endif

    #ifndef P_FILE_OPEN
        #define P_FILE_OPEN
int file_open(file_t *file);
    #endif

    #ifndef P_FILE_CLOSE
        #define P_FILE_CLOSE
int file_close(file_t *file);
    #endif

    #ifndef P_FILE_LOAD
        #define P_FILE_LOAD
int file_load(file_t *file);
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

    #ifndef P_STR_DUP
        #define P_STR_DUP
str_t str_dup(cstr_t src);
    #endif

    #ifndef P_STR_NDUP
        #define P_STR_NDUP
str_t str_ndup(cstr_t src, int n);
    #endif

    #ifndef P_STR_PUT_STR
        #define P_STR_PUT_STR
int str_put_str(cstr_t string);
    #endif

    #ifndef P_STR_LEN
        #define P_STR_LEN
int str_len(cstr_t string);
    #endif

    #ifndef P_STR_TO_WORD_ARRAY
        #define P_STR_TO_WORD_ARRAY
str_t *str_split(cstr_t string, cc_t separator);
    #endif

#endif
