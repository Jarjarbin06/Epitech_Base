/*
** EPITECH PROJECT, 2025
** tests - test_seg.c
** File description:
** None
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "include_test.h"

Test(main, test, .init=redirect_all_std)
{
    cr_assert(1);
}
