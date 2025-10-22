/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** None
*/

#ifndef _MY_H
    #define _MY_H
    #define EXIT_SUCCESS 0
    #define EXIT_ERROR 84

void my_putchar(char c);                              /*      TEST OK      */
int my_isneg(int n);                                  /*      TEST OK      */
int my_put_nbr(int nb);                               /*      TEST OK      */
void my_swap(int *ptr_a, int *ptr_b);                 /*      TEST OK      */
void my_swap_char(char *ptr_a, char *ptr_b);          /*      TEST OK      */
int my_putstr(char const *str);                       /*      TEST OK      */
int my_strlen(char const *str);                       /*      TEST OK      */
int my_getnbr(char const *str);                       /*      TEST OK      */
void my_sort_int_array(int *tab, int size);           /*      TEST OK      */
int my_compute_power_rec(int nb, int p);              /*      TEST OK      */
int my_compute_square_root(int nb);                   /*      TEST OK      */
int my_is_prime(int nb);                              /*      TEST OK      */
int my_find_prime_sup(int nb);                        /*      TEST OK      */
char *my_strcpy(char *dest, char const *src);         /* /!\  NO TEST  /!\ */
char *my_strncpy(char *dest, char const *src, int n); /* /!\  NO TEST  /!\ */
char *my_revstr(char *str);                           /* /!\  NO TEST  /!\ */
char *my_strstr(char *str, char const *to_find);      /* /!\  NO TEST  /!\ */
int my_strcmp(char const *s1, char const *s2);        /*      TEST OK      */
int my_strncmp(char const *s1, char const *s2, int n);/*      TEST OK      */
char *my_strlowcase(char *str);                       /* /!\  NO TEST  /!\ */
char *my_strupcase(char *str);                        /* /!\  NO DONE  /!\ */
char *my_strcapitalize(char *str);                    /*      TEST OK      */
int my_str_isalpha(char const *str);                  /*      TEST OK      */
int is_alpha(char const c);                           /* /!\  NO TEST  /!\ */
int my_str_isnum(char const *str);                    /*      TEST OK      */
int is_num(char const c);                             /* /!\  NO TEST  /!\ */
int my_str_islower(char const *str);                  /*      TEST OK      */
int is_lower(char const c);                           /* /!\  NO TEST  /!\ */
int my_str_isupper(char const *str);                  /*      TEST OK      */
int is_upper(char const c);                           /* /!\  NO TEST  /!\ */
int my_str_isprintable(char const *str);              /*      TEST OK      */
int is_printable(char const c);                       /* /!\  NO TEST  /!\ */
int my_showstr(char const *str);                      /* /!\  NO TEST  /!\ */
int my_showmem(char const *str, int size);            /* /!\  NO TEST  /!\ */
char *my_strcat(char *dest, char const *src);         /*      TEST OK      */
char *my_strncat(char *dest, char const *src, int nb);/* /!\  NO DONE  /!\ */
char *my_strdup(char const *src);                     /*      TEST OK      */
int my_show_word_array(char const **tab);             /*      TEST OK      */
char **my_str_to_word_array(char const *str);         /*  ?   TEST OK   ?  */
char *concat_params(int argc, char **argv);           /*      TEST OK      */
int my_macro_abs(int nbr);                            /*      TEST OK      */

#endif
