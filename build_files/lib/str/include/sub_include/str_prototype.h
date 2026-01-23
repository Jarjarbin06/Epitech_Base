/*
** EPITECH PROJECT, 2025
** sub_include - str_prototype.h
** File description:
** <description>
*/

// Prototype //
#ifndef STR_P
    #define STR_P

    #include "str_define.h"
    #include "str_include.h"
    #include "str_typedef.h"

// _str.c //
void _str_show_macro(void);
// my_getnbr.c //
int my_getnbr(const char *str);
// my_putnbr.c //
void my_put_nbr(int nbr);
// my_putchar.c //
void my_putchar(char c);
// my_putstr.c //
int my_putstr(const char *str);
// my_revstr.c //
char *my_revstr(char *str);
// my_str_isalpha.c //
bool is_alpha(char c);
bool my_str_isalpha(const char *str);
// my_str_islower.c //
bool is_lower(char c);
bool my_str_islower(const char *str);
// my_str_isnum.c //
bool is_num(char c);
bool my_str_isnum(const char *str);
// my_str_isprintable.c //
bool is_printable(char c);
bool my_str_isprintable(const char *str);
// my_str_isupper.c //
bool is_upper(char c);
bool my_str_isupper(const char *str);
// my_str_to_word_array.c //
char **my_str_to_word_array(const char *str);
// my_strcapitalize.c //
char *my_strcapitalize(char *str);
// my_strcat.c //
char *my_strcat(char *dest, const char *src);
// my_strcmp.c //
int my_strcmp(const char *str1, const char *str2);
// my_strcpy.c //
char *my_strcpy(char *dest, const char *src);
//my_strdup.c //
char *my_strdup(const char *src);
// my_strlen.c //
int my_strlen(const char *str);
// my_strlowcase.c //
char *my_strlowcase(char *str);
// my_strncat.c //
char *my_strncat(char *dest, const char *src, int n);
// my_strncmp.c //
int my_strncmp(const char *str1, const char *str2, int n);
// my_strncpy.c //
char *my_strncpy(char *dest, const char *src, int n);
// my_strstr.c //
char *my_strstr(char *str, const char *to_find);
// my_strupcase.c //
char *my_strupcase(char *str);
// my_swap_char.c //
void my_swap_char(char *ptr_a, char *ptr_b);

    // add type prototype here //

#endif
