/*
** EPITECH PROJECT, 2025
** sub_includes - newcsfml_prototype.h
** File description:
** <description>
*/

// Prototype //
#ifndef NEWCSFML_OTHER
    #define NEWCSFML_OTHER

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

    #ifndef P_MY_STRDUP
        #define P_MY_STRDUP
char *my_strdup(const char *src);
    #endif

    #ifndef P_MY_STRLEN
        #define P_MY_STRLEN
int my_strlen(const char *str);
    #endif

#endif
