/*
** EPITECH PROJECT, 2025
** test_my_printf.c
** File description:
** None
*/

#include <stdio.h>

#include "test.h"

void test_start(void)
{
    printf("test start\n");
    fflush(stdout);
}

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
