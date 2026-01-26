/*
** EPITECH PROJECT, 2025
** test_redirect.c
** File description:
** None
*/

#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
