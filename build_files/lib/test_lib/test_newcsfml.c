/*
** EPITECH PROJECT, 2025
** test_lib - test_newcsfml.c
** File description:
** None
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "test.h"

// test_start //
Test(test_start, test_newcsfml_test_start, .init = redirect_all_std)
{
    test_start();
    cr_assert_stdout_eq_str("test start\n");
}

Test(newcsfml_exist, test_newcsfml_exist)
{
    newcsfml_exist();
    cr_assert(1);
}

/* STRUCT */
// sprite.c //
Test(nsf_sprite_create, test_newcsfml_nsf_sprite_create)
{
    nsf_sprite *sprite = nsf_sprite_create("test sprite");
    cr_assert(sprite);
    free(sprite->sprite);
    free(sprite);
}

Test(nsf_sprite_destroy, test_newcsfml_nsf_sprite_destroy_valid)
{
    nsf_sprite *sprite = (nsf_sprite *)malloc(sizeof(nsf_sprite));
    cr_assert(sprite);
    nsf_sprite_destroy(&sprite);
    cr_assert(!sprite);
}

Test(nsf_sprite_destroy, test_newcsfml_nsf_sprite_destroy_invalid)
{
    nsf_sprite *sprite = NULL;
    cr_assert(!sprite);
    nsf_sprite_destroy(&sprite);
    cr_assert(!sprite);
}
