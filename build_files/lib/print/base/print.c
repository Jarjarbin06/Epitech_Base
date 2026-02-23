/*
** EPITECH PROJECT, 2025
** str - str.c
** File description:
** <description>
*/

#include "../includes/print.h"

#ifdef PRINT
void print_show_macro(void)
{
    print("EXIT :\n");
    print("    EXIT_SUCCESS : %d\n", EXIT_SUCCESS);
    print("    EXIT_FAILURE : %d\n", EXIT_ERROR);
}

#else
    #include <unistd.h>
void print_show_macro(void)
{
    write(1, "str_show_macro not available\n", 29);
    write(1, "import libprint to use it\n", 26);
}

#endif

void print_exist(void)
{
}
