/*
** EPITECH PROJECT, 2025
** 2list - twodlist.c
** File description:
** <description>
*/

#include "../includes/twodlist.h"

#ifdef PRINT

void twodlist_show_macro(void)
{
    print("EXIT :\n");
    print("    EXIT_SUCCESS : %d\n", EXIT_SUCCESS);
    print("    EXIT_FAILURE : %d\n", EXIT_FAILURE);
    print("C (COLOR) :\n");
    print("    C_ERROR : %stext%s\n", C_ERROR, C_RESET);
    print("    C_WARNING : %stext%s\n", C_WARNING, C_RESET);
    print("    C_VALID : %stext%s\n", C_VALID, C_RESET);
    print("    C_INFO : %stext%s\n", C_INFO, C_RESET);
    print("    C_ITALIC : %stext%s\n", C_ITALIC, C_RESET);
    print("    C_BOLD : %stext%s\n", C_BOLD, C_RESET);
    print("    C_UNDERLINE : %stext%s\n", C_UNDERLINE, C_RESET);
    print("    C_DIM : %stext%s\n", C_DIM, C_RESET);
}
#else
    #include <unistd.h>

void twodlist_show_macro(void)
{
    write(1, "twodlist_show_macro not available\n", 34);
    write(1, "import libprint to use it\n", 26);
}
#endif

void twodlist_exist(void)
{
}
