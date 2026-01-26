/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** <description>
*/

#include "include/include_file.h"

int main(int argc, char **argv)
{
    bool err = false;

    err = ((function()) ? (true) : (err));
    return (!(err) ? (EXIT_SUCCESS) : (EXIT_ERROR));
}
