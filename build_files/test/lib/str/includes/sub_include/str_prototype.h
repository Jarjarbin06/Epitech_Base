/*
** EPITECH PROJECT, 2025
** sub_includes - str_prototype.h
** File description:
** <description>
*/

// Prototype //
#ifndef STR_P
    #define STR_P

    #include "str_include.h"
    #include "str_typedef.h"

    #ifndef STR_P_BASE
        #define STR_P_BASE
void str_exist(void);
    #endif

    #ifndef P_STR_GETNBR
        #define P_STR_GETNBR
int str_getnbr(const char *str);
    #endif

    #ifndef P_STR_PUT_NBR
        #define P_STR_PUT_NBR
void str_put_nbr(int nbr);
    #endif

    #ifndef P_STR_PUTCHAR
        #define P_STR_PUTCHAR
int str_putchar(char c);
    #endif

    #ifndef P_STR_PUTSTR
        #define P_STR_PUTSTR
int str_putstr(const char *str);
    #endif

    #ifndef P_STR_REVSTR
        #define P_STR_REVSTR
char *str_revstr(char *str);
    #endif

    #ifndef P_IS_ALPHA
        #define P_IS_ALPHA
bool str_is_alpha(char c);
    #endif

    #ifndef P_STR_STR_ISALPHA
        #define P_STR_STR_ISALPHA
bool str_str_isalpha(const char *str);
    #endif

    #ifndef P_IS_LOWER
        #define P_IS_LOWER
bool str_is_lower(char c);
    #endif

    #ifndef P_STR_STR_ISLOWER
        #define P_STR_STR_ISLOWER
bool str_str_islower(const char *str);
    #endif

    #ifndef P_IS_NUM
        #define P_IS_NUM
bool str_is_num(char c);
    #endif

    #ifndef P_STR_STR_ISNUM
        #define P_STR_STR_ISNUM
bool str_str_isnum(const char *str);
    #endif

    #ifndef P_IS_PRINTABLE
        #define P_IS_PRINTABLE
bool str_is_printable(char c);
    #endif

    #ifndef P_STR_STR_ISPRINTABLE
        #define P_STR_STR_ISPRINTABLE
bool str_str_isprintable(const char *str);
    #endif

    #ifndef P_IS_UPPER
        #define P_IS_UPPER
bool str_is_upper(char c);
    #endif

    #ifndef P_STR_STR_ISUPPER
        #define P_STR_STR_ISUPPER
bool str_str_isupper(const char *str);
    #endif

    #ifndef P_STR_STR_TO_WORD_ARRAY
        #define P_STR_STR_TO_WORD_ARRAY
char **str_str_to_word_array(const char *str);
    #endif

    #ifndef P_STR_STRCAPITALIZE
        #define P_STR_STRCAPITALIZE
char *str_strcapitalize(char *str);
    #endif

    #ifndef P_STR_STRCAT
        #define P_STR_STRCAT
char *str_strcat(char *src_1, const char *src_2);
    #endif

    #ifndef P_STR_STRCMP
        #define P_STR_STRCMP
int str_strcmp(const char *str1, const char *str2);
    #endif

    #ifndef P_STR_STRCPY
        #define P_STR_STRCPY
char *str_strcpy(char *dest, const char *src);
    #endif

    #ifndef P_STR_STRDUP
        #define P_STR_STRDUP
char *str_strdup(const char *src);
    #endif

    #ifndef P_STR_STRLEN
        #define P_STR_STRLEN
int str_strlen(const char *str);
    #endif

    #ifndef P_STR_STRLOWCASE
        #define P_STR_STRLOWCASE
char *str_strlowcase(char *str);
    #endif

    #ifndef P_STR_STRNCAT
        #define P_STR_STRNCAT
char *str_strncat(char *dest, const char *src, int n);
    #endif

    #ifndef P_STR_STRNCMP
        #define P_STR_STRNCMP
int str_strncmp(const char *str1, const char *str2, int n);
    #endif

    #ifndef P_STR_STRNCPY
        #define P_STR_STRNCPY
char *str_strncpy(char *dest, const char *src, int n);
    #endif

    #ifndef P_STR_STRNDUP
        #define P_STR_STRNDUP
char *str_strndup(const char *src, int n);
    #endif

    #ifndef P_STR_STRSTR
        #define P_STR_STRSTR
char *str_strstr(char *str, const char *to_find);
    #endif

    #ifndef P_STR_STRUPCASE
        #define P_STR_STRUPCASE
char *str_strupcase(char *str);
    #endif

    #ifndef P_STR_SWAP_CHAR
        #define P_STR_SWAP_CHAR
void str_swap_char(char *ptr_a, char *ptr_b);
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
void free_array(void **array);
    #endif

#endif
