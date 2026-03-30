/*
** EPITECH PROJECT, 2025
** sources - source_file.c
** File description:
** <description>
*/

#include <stdio.h>

#include "include.h"

int function(const int argc, const char **argv)
{
    printf("%d -", argc);
    for (int idx = 0; idx < argc; idx++)
        printf(" \"%s\"", argv[idx]);
    printf("\n");
    return EXIT_SUCCESS;
}
