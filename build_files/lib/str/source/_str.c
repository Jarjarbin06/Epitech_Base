/*
** EPITECH PROJECT, 2025
** str - _str.c
** File description:
** <description>
*/

#include "../include/str.h"

void _str_show_macro(void)
{
    printf("EXIT :\n");
    printf("    EXIT_SUCCESS : %d\n",EXIT_SUCCESS);
    printf("    EXIT_FAILURE : %d\n",EXIT_FAILURE);
    printf("C (COLOR) :\n");
    printf("    C_ERROR : %stext%s\n",C_ERROR, C_RESET);
    printf("    C_WARNING : %stext%s\n",C_WARNING, C_RESET);
    printf("    C_VALID : %stext%s\n",C_VALID, C_RESET);
    printf("    C_INFO : %stext%s\n",C_INFO, C_RESET);
    printf("    C_ITALIC : %stext%s\n",C_ITALIC, C_RESET);
    printf("    C_BOLD : %stext%s\n",C_BOLD, C_RESET);
    printf("    C_UNDERLINE : %stext%s\n",C_UNDERLINE, C_RESET);
    printf("    C_DIM : %stext%s\n",C_DIM, C_RESET);
}
