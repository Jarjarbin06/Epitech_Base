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

    #ifndef P_MY_GETNBR
        #define P_MY_GETNBR
int my_getnbr(const char *str);
    #endif

    #ifndef P_MY_PUT_NBR
        #define P_MY_PUT_NBR
void my_put_nbr(int nbr);
    #endif

    #ifndef P_MY_PUTCHAR
        #define P_MY_PUTCHAR
int my_putchar(char c);
    #endif

    #ifndef P_MY_PUTSTR
        #define P_MY_PUTSTR
int my_putstr(const char *str);
    #endif

    #ifndef P_MY_REVSTR
        #define P_MY_REVSTR
char *my_revstr(char *str);
    #endif

    #ifndef P_IS_ALPHA
        #define P_IS_ALPHA
bool is_alpha(char c);
    #endif

    #ifndef P_MY_STR_ISALPHA
        #define P_MY_STR_ISALPHA
bool my_str_isalpha(const char *str);
    #endif

    #ifndef P_IS_LOWER
        #define P_IS_LOWER
bool is_lower(char c);
    #endif

    #ifndef P_MY_STR_ISLOWER
        #define P_MY_STR_ISLOWER
bool my_str_islower(const char *str);
    #endif

    #ifndef P_IS_NUM
        #define P_IS_NUM
bool p_is_num(char c);
    #endif

    #ifndef P_MY_STR_ISNUM
        #define P_MY_STR_ISNUM
bool my_str_isnum(const char *str);
    #endif

    #ifndef P_IS_PRINTABLE
        #define P_IS_PRINTABLE
bool is_printable(char c);
    #endif

    #ifndef P_MY_STR_ISPRINTABLE
        #define P_MY_STR_ISPRINTABLE
bool my_str_isprintable(const char *str);
    #endif

    #ifndef P_IS_UPPER
        #define P_IS_UPPER
bool is_upper(char c);
    #endif

    #ifndef P_MY_STR_ISUPPER
        #define P_MY_STR_ISUPPER
bool my_str_isupper(const char *str);
    #endif

    #ifndef P_MY_STR_TO_WORD_ARRAY
        #define P_MY_STR_TO_WORD_ARRAY
char **my_str_to_word_array(const char *str);
    #endif

    #ifndef P_MY_STRCAPITALIZE
        #define P_MY_STRCAPITALIZE
char *my_strcapitalize(char *str);
    #endif

    #ifndef P_MY_STRCAT
        #define P_MY_STRCAT
char *my_strcat(char *src_1, const char *src_2);
    #endif

    #ifndef P_MY_STRCMP
        #define P_MY_STRCMP
int my_strcmp(const char *str1, const char *str2);
    #endif

    #ifndef P_MY_STRCPY
        #define P_MY_STRCPY
char *my_strcpy(char *dest, const char *src);
    #endif

    #ifndef P_MY_STRDUP
        #define P_MY_STRDUP
char *my_strdup(const char *src);
    #endif

    #ifndef P_MY_STRLEN
        #define P_MY_STRLEN
int p_strlen(const char *str);
    #endif

    #ifndef P_MY_STRLOWCASE
        #define P_MY_STRLOWCASE
char *my_strlowcase(char *str);
    #endif

    #ifndef P_MY_STRNCAT
        #define P_MY_STRNCAT
char *my_strncat(char *dest, const char *src, int n);
    #endif

    #ifndef P_MY_STRNCMP
        #define P_MY_STRNCMP
int my_strncmp(const char *str1, const char *str2, int n);
    #endif

    #ifndef P_MY_STRNCPY
        #define P_MY_STRNCPY
char *my_strncpy(char *dest, const char *src, int n);
    #endif

    #ifndef P_MY_STRNDUP
        #define P_MY_STRNDUP
char *my_strndup(const char *src, int n);
    #endif

    #ifndef P_MY_STRSTR
        #define P_MY_STRSTR
char *my_strstr(char *str, const char *to_find);
    #endif

    #ifndef P_MY_STRUPCASE
        #define P_MY_STRUPCASE
char *my_strupcase(char *str);
    #endif

    #ifndef P_MY_SWAP_CHAR
        #define P_MY_SWAP_CHAR
void my_swap_char(char *ptr_a, char *ptr_b);
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
