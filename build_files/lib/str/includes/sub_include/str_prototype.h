/*
** EPITECH PROJECT, 2025
** sub_includes - str_prototype.h
** File description:
** <description>
*/

// Prototype //
#ifndef STR_P
    #define STR_P

    #include "str_typedef.h"

    #ifndef STR_P_BASE
        #define STR_P_BASE
void str_exist(void);
    #endif

    #ifndef P_STR_GET_NBR
        #define P_STR_GET_NBR
int str_get_nbr(cstr_t string);
    #endif

    #ifndef P_STR_PUT_NBR
        #define P_STR_PUT_NBR
void str_put_nbr(int nbr);
    #endif

    #ifndef P_STR_PUT_CHAR
        #define P_STR_PUT_CHAR
int str_put_char(cc_t c);
    #endif

    #ifndef P_STR_PUT_STR
        #define P_STR_PUT_STR
int str_put_str(cstr_t string);
    #endif

    #ifndef P_STR_REVERSE
        #define P_STR_REVERSE
str_t str_reverse(str_t string);
    #endif

    #ifndef P_STR_C_IS_ALPHA
        #define P_STR_C_IS_ALPHA
bool str_c_is_alpha(cc_t c);
    #endif

    #ifndef P_STR_IS_ALPHA
        #define P_STR_IS_ALPHA
bool str_is_alpha(cstr_t string);
    #endif

    #ifndef P_STR_C_IS_LOWER
        #define P_STR_C_IS_LOWER
bool str_c_is_lower(cc_t c);
    #endif

    #ifndef P_STR_IS_LOWER
        #define P_STR_IS_LOWER
bool str_is_lower(cstr_t string);
    #endif

    #ifndef P_STR_C_IS_NUM
        #define P_STR_C_IS_NUM
bool str_c_is_num(cc_t c);
    #endif

    #ifndef P_STR_IS_NUM
        #define P_STR_IS_NUM
bool str_is_num(cstr_t string);
    #endif

    #ifndef P_STR_C_IS_PRINTABLE
        #define P_STR_C_IS_PRINTABLE
bool str_c_is_printable(cc_t c);
    #endif

    #ifndef P_STR_IS_PRINTABLE
        #define P_STR_IS_PRINTABLE
bool str_is_printable(cstr_t str);
    #endif

    #ifndef P_STR_C_IS_UPPER
        #define P_STR_C_IS_UPPER
bool str_c_is_upper(cc_t c);
    #endif

    #ifndef P_STR_IS_UPPER
        #define P_STR_IS_UPPER
bool str_is_upper(cstr_t str);
    #endif

    #ifndef P_STR_TO_WORD_ARRAY
        #define P_STR_TO_WORD_ARRAY
str_t *str_split(cstr_t string, cc_t separator);
    #endif

    #ifndef P_STR_CAPITALIZE
        #define P_STR_CAPITALIZE
str_t str_capitalize(str_t string);
    #endif

    #ifndef P_STR_CAT
        #define P_STR_CAT
str_t str_cat(cstr_t src_1, cstr_t src_2);
    #endif

    #ifndef P_STR_CMP
        #define P_STR_CMP
int str_cmp(cstr_t str1, cstr_t str2);
    #endif

    #ifndef P_STR_CPY
        #define P_STR_CPY
str_t str_cpy(str_t dest, cstr_t src);
    #endif

    #ifndef P_STR_DUP
        #define P_STR_DUP
str_t str_dup(cstr_t src);
    #endif

    #ifndef P_STR_LEN
        #define P_STR_LEN
size_t str_len(cstr_t string);
    #endif

    #ifndef P_STR_LOWCASE
        #define P_STR_LOWCASE
str_t str_lowcase(str_t string);
    #endif

    #ifndef P_STR_NCAT
        #define P_STR_NCAT
str_t str_ncat(cstr_t dest, cstr_t src, int n);
    #endif

    #ifndef P_STR_NCMP
        #define P_STR_NCMP
int str_ncmp(cstr_t str1, cstr_t str2, int n);
    #endif

    #ifndef P_STR_NCPY
        #define P_STR_NCPY
str_t str_ncpy(str_t dest, cstr_t src, int n);
    #endif

    #ifndef P_STR_NDUP
        #define P_STR_NDUP
str_t str_ndup(cstr_t src, int n);
    #endif

    #ifndef P_STR_STRSTR
        #define P_STR_STRSTR
str_t str_str(str_t str, str_t to_find);
    #endif

    #ifndef P_STR_UPCASE
        #define P_STR_UPCASE
str_t str_upcase(str_t string);
    #endif

    #ifndef P_STR_C_SWAP
        #define P_STR_C_SWAP
void str_c_swap(str_t ptr_a, str_t ptr_b);
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

#endif
