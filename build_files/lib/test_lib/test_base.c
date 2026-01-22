/*
** EPITECH PROJECT, 2025
** test_my_printf.c
** File description:
** None
*/

#include "test.h"

void test_start(void)
{
    printf("test started");
}

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
